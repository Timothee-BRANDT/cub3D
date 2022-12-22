/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:43:17 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/22 18:24:15 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	hit_and_side(t_data *data)
{
	data->hit = 0;
	while (!data->hit)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map[data->map_y][data->map_x] == '1')
			data->hit = 1;
	}
}

void	calculate_side_dist(t_data *data)
{
	if (data->ray_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1 - data->pos_x) * data->delta_x;
	}
	if (data->ray_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1 - data->pos_y) * data->delta_y;
	}
}

void	dda(t_data *data)
{
	data->cam_x = 2 * data->i / (double)(WIDTH) -1;
	data->ray_x = data->dir_x + data->plane_x * data->cam_x;
	data->ray_y = data->dir_y + data->plane_y * data->cam_x;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	if (!data->ray_x)
		data->delta_x = INFINITY;
	else
		data->delta_x = fabs(1 / data->ray_x);
	if (!data->ray_y)
		data->delta_y = INFINITY;
	else
		data->delta_y = fabs(1 / data->ray_y);
	calculate_side_dist(data);
	hit_and_side(data);
}

void	build_window(t_data *data)
{
	data->ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->ptr, WIDTH, HEIGHT, "cub3D");
	data->cub.img_data = mlx_new_image(data->ptr, WIDTH, HEIGHT);
	data->cub.addr = mlx_get_data_addr \
	(data->cub.img_data, &data->cub.bits_per_pixel, \
	&data->cub.line_length, &data->cub.endian);
	data->tex_size = 64;
	set_textures_img(data);
	lets_play(data);
	mlx_hook(data->mlx_win, 2, 0, key_press, data);
	mlx_hook(data->mlx_win, 17, 0, exit_game, data);
	mlx_loop(data->ptr);
}

void	lets_play(t_data *data)
{
	print_ground(data);
	print_sky(data);
	data->i = 0;
	while (data->i <= WIDTH)
	{
		dda(data);
		set_textures_variables(data);
		print_pixels(data);
		data->i++;
	}
	mlx_put_image_to_window(data->ptr, data->mlx_win, data->cub.img_data, 0, 0);
}
