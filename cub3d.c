/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:45:40 by rarias-p          #+#    #+#             */
/*   Updated: 2021/03/08 16:35:54 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_loop(t_data *data)
{
	data->z_buffrer = malloc((sizeof(double)) * data->resx + 1);
	start_direction(data);
	data->mlx_ptr = mlx_init();
	data->resx = data->resx > 2560 ? 2560 : data->resx;
	data->resy = data->resy > 1440 ? 1440 : data->resy;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->resx, data->resy,
	"CUB3D");
	if (data->resy < 50 || data->resx < 50)
		low_res(data);
	if (!(data->is_pos == 1))
		no_map();
	system("afplay rain.mp3 &");
	main_loop(data);
}

int		main(int argc, char const *argv[])
{
	t_data	*data;

	if (argc < 2 || argc > 3)
	{
		write(1, "Error\nNot enough arguments or too many arguments\n", 50);
		return (1);
	}
	data = malloc(sizeof(t_data));
	init(data);
	if ((data->fd = open(argv[1], O_RDONLY)) < 0)
	{
		write(1, "Error\nCould not open file\n", 27);
		return (1);
	}
	get_data(data);
	check_map(data);
	if (!(errors(data)) && argc < 3)
		init_loop(data);
	else if (!(errors(data)) && !(ft_strcmp("--save", argv[2])))
		save_bmp(data);
	else if (!(errors(data)) && (ft_strcmp("--save", argv[2])))
		arg_error(data);
	else
		print_errors(data);
	return (0);
}

/*
** 	printf("Resolution:\n\tX = %d\n\tY = %d\nTexture:\n\tNO: %s\n\tSO: %s\n
** 	\tWE: %s\n\tEA: %s\n\tSP: %s\nColor:\n\tC: %3d, %3d, %3d\n\tF: %3d, %3d,
** 	%3d\n\nN?? lines: %d\n\n\nErrors:\n\tMap: %d\n\tColors: %d\n\tTexture: %d\n
** 	\tResolution: %d\n\n\tTotal: %d",
** 	data->resx, data->resy, data->text_no, data->text_so, data->text_we,
** 	data->text_ea, data->text_sp, data->ceiling->r, data->ceiling->g,
** 	data->ceiling->b, data->floor->r, data->floor->g, data->floor->b,
** 	data->lines_map, data->errors->map, data->errors->colors,
** 	data->errors->texture, data->errors->resolution, data->errors->general);
*/
