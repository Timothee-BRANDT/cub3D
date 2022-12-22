/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:44:51 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/22 17:40:57 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	exit_game(t_data *data)
{
	free(data->map);
	exit(1);
}

void	try_no(t_data *data)
{
	data->img_north.img_data = mlx_xpm_file_to_image \
	(data->ptr, data->path_north, &data->tex_size, &data->tex_size);
	if (!data->img_north.img_data)
		print_and_exit("Error : problem on textures\n", -1);
	data->img_north.addr = mlx_get_data_addr(data->img_north.img_data, \
	&data->img_north.bits_per_pixel, \
	&data->img_north.line_length, &data->img_north.endian);
}

void	try_so(t_data *data)
{
	data->img_south.img_data = mlx_xpm_file_to_image \
	(data->ptr, data->path_south, &data->tex_size, &data->tex_size);
	if (!data->img_south.img_data)
		print_and_exit("Error : problem on textures\n", -1);
	data->img_south.addr = mlx_get_data_addr \
	(data->img_south.img_data, &data->img_south.bits_per_pixel, \
	&data->img_south.line_length, &data->img_south.endian);
}

void	try_ea(t_data *data)
{
	data->img_east.img_data = mlx_xpm_file_to_image \
	(data->ptr, data->path_east, &data->tex_size, &data->tex_size);
	if (!data->img_east.img_data)
		print_and_exit("Error : problem on textures\n", -1);
	data->img_east.addr = mlx_get_data_addr \
	(data->img_east.img_data, &data->img_east.bits_per_pixel, \
	&data->img_east.line_length, &data->img_east.endian);
}

void	try_we(t_data *data)
{
	data->img_west.img_data = mlx_xpm_file_to_image \
	(data->ptr, data->path_west, &data->tex_size, &data->tex_size);
	if (!data->img_west.img_data)
		print_and_exit("Error : problem on textures\n", -1);
	data->img_west.addr = mlx_get_data_addr \
	(data->img_west.img_data, &data->img_west.bits_per_pixel, \
	&data->img_west.line_length, &data->img_west.endian);
}
