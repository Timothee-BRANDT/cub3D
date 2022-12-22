/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:17:20 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/22 17:06:46 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	print_sky(t_data *data)
{
	int	i;
	int	y;
	int	middle;

	i = 0;
	y = 0;
	middle = HEIGHT / 2;
	while (y <= middle)
	{
		i = 0;
		while (i <= WIDTH)
		{
			pixel_put(data, i, y, data->sky_color);
			i++;
		}
		y++;
	}
}

void	print_ground(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = HEIGHT / 2 + 1;
	while (y < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			pixel_put(data, i, y, data->floor_color);
			i++;
		}
		y++;
	}
}

void	wich_texture(t_data *data)
{
	if (data->hit && data->side && data->step_y < 0)
		data->tex_color = data->img_north.addr + \
		(data->tex_y * data->img_north.line_length - data->tex_x \
		* (data->img_north.bits_per_pixel / 8));
	else if (data->hit && data->side && data->step_y > 0)
		data->tex_color = data->img_south.addr + \
		(data->tex_y * data->img_south.line_length - (data->tex_x + 1) \
		* (data->img_south.bits_per_pixel / 8));
	else if (data->hit && !data->side && data->step_x > 0)
		data->tex_color = data->img_east.addr + \
		(data->tex_y * data->img_east.line_length - \
		data->tex_x * (data->img_east.bits_per_pixel / 8));
	else if (data->hit && !data->side && data->step_x < 0)
		data->tex_color = data->img_west.addr + \
		(data->tex_y * data->img_west.line_length - \
		(data->tex_x + 1) * (data->img_west.bits_per_pixel / 8));
}

void	print_pixels(t_data *data)
{
	while (data->j <= data->draw_end)
	{
		data->tex_y = (int)data->tex_position & (64 - 1);
		data->tex_y += 1;
		data->tex_position += data->step;
		wich_texture(data);
		data->tex_pixel = data->cub.addr + \
		(data->j * data->cub.line_length + data->i * \
		(data->cub.bits_per_pixel / 8));
		*(int *)data->tex_pixel = *(int *)data->tex_color;
			data->j++;
	}
}

void	set_textures_variables(t_data *data)
{
	if (!data->side)
		data->wall_distance = data->side_dist_x - data->delta_x;
	else
		data->wall_distance = data->side_dist_y - data->delta_y;
	data->line_height = (int)(HEIGHT / data->wall_distance);
	data->draw_start = -data->line_height / 2 + HEIGHT / 2;
	define_draw(data);
	if (!data->side)
		data->wall_x = data->pos_y + data->wall_distance * data->ray_y;
	else
		data->wall_x = data->pos_x + data->wall_distance * data->ray_x;
	data->wall_x -= floor(data->wall_x);
	data->tex_x = (int)(data->wall_x * 64);
	if (!data->side && data->ray_x > 0)
		data->tex_x = 64 - data->tex_x;
	if (data->side && data->ray_y < 0)
		data->tex_x = 64 - data->tex_x;
	data->step = 1.0 * 64 / data->line_height;
	data->tex_position = \
	(data->draw_start - HEIGHT / 2.0 + \
	data->line_height / 2.0) * data->step;
	data->j = data->draw_start;
}
