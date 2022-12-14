/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:47:17 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/14 12:10:06 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init_data(t_data *data)
{
	data->screen_width = 920;
	data->screen_height = 540;
	data->map_width = 24;
	data->map_height = 24;
	data->posX = 22;
	data->posY = 12;
	data->dirX = -1;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = 0.66;
}

void	build_window(t_data *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, data->screen_width, data->screen_height, "Hello world!");
	data->img.img = mlx_new_image(data->mlx.mlx, data->screen_width, data->screen_height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	pixel_put(data, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->img.img, 0, 0);
	mlx_loop(data->mlx.mlx);
}

int main()
{
	t_data	data;
	char	**map;

	init_data(&data);
	build_window(&data);
}