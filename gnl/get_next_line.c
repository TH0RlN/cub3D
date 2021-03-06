/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:37:00 by rarias-p          #+#    #+#             */
/*   Updated: 2021/03/05 20:19:03 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		*buffer;
	static char	*file[4096];
	char		*acc;

	if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(char))) || fd < 0
	|| line == NULL)
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (file[fd] == NULL)
			file[fd] = ft_strdup(buffer);
		else
		{
			acc = ft_strjoin(file[fd], buffer);
			free(file[fd]);
			file[fd] = ft_strdup(acc);
			free(acc);
		}
		if (ft_strchr(file[fd], '\n'))
			break ;
	}
	free(buffer);
	return ((ret == 0 && !file[fd]) ? ft_aux(line)
	: ft_checker(fd, line, file, ret));
}

int		ft_aux(char **line)
{
	*line = ft_strdup("");
	return (0);
}

int		ft_checker(int fd, char **line, char **file, int ret)
{
	int		i;
	char	*temp;

	if (ret == -1)
		return (-1);
	i = 0;
	while (file[fd][i] && file[fd][i] != '\n')
		i++;
	if (file[fd][i] == '\n')
	{
		free (*line);
		*line = ft_substr(file[fd], 0, i);
		temp = ft_strdup(&((file[fd])[i + 1]));
		free(file[fd]);
		file[fd] = temp;
	}
	else
	{
		*line = ft_strdup(file[fd]);
		free(file[fd]);
		file[fd] = 0;
		free(*line);
		return (0);
	}
	free(*line);
	return (1);
}
