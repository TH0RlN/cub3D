/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:41:52 by rarias-p          #+#    #+#             */
/*   Updated: 2021/03/08 16:58:15 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		drawer(t_data *data)
{
	keys_change(data, data->keys);
	data->sprite_check = data->sprite_check == SPRITE_SPEED ?
	0 : data->sprite_check + 1;
	engine(data, data->player, data->ray, data->plane);
	return (0);
}

void	start_direction_2(t_data *data)
{
	if (data->direction == 'S')
	{
		data->player->direction->x = 0.0;
		data->player->direction->y = 1.0;
		data->plane->x = -0.66;
		data->plane->y = 0.0;
	}
	else if (data->direction == 'N')
	{
		data->player->direction->x = 0.0;
		data->player->direction->y = -1.0;
		data->plane->x = 0.66;
		data->plane->y = 0.0;
	}
}

void	start_direction(t_data *data)
{
	if (data->direction == 'W')
	{
		data->player->direction->x = -1.0;
		data->player->direction->y = 0.0;
		data->plane->x = 0.0;
		data->plane->y = -0.66;
	}
	else if (data->direction == 'E')
	{
		data->player->direction->x = 1.0;
		data->player->direction->y = 0.0;
		data->plane->x = 0.0;
		data->plane->y = 0.66;
	}
	else if (data->direction == 'S' || data->direction == 'N')
		start_direction_2(data);
	data->player->position->x = data->init_pos->x + 0.5;
	data->player->position->y = data->init_pos->y + 0.5;
}

/*
** 	printf("Posici??n inicial:\n\tX:%f\n\tY:%f\n",
**  data->player->position->x, data->player->position->y);
*/

void	main_loop(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, drawer, data);
	mlx_hook(data->win_ptr, 17, 0, salida, (void *)data);
	mlx_hook(data->win_ptr, 2, 0, keys_press, (void *)data);
	mlx_hook(data->win_ptr, 3, 0, keys_released, (void *)data);
	mlx_loop(data->mlx_ptr);
}
