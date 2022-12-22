/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:47:17 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/22 17:16:36 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	set_fov(t_data *data, char c)
{
	if (c == 'N')
	{
		data->plane_x = 0.66;
		data->plane_y = 0;
	}
	else if (c == 'S')
	{
		data->plane_x = -0.66;
		data->plane_y = 0;
	}
	else if (c == 'E')
	{
		data->plane_y = 0.66;
		data->plane_x = 0;
	}
	else
	{
		data->plane_y = -0.66;
		data->plane_x = 0;
	}
}

void	set_direction(t_data *data, char c)
{
	if (c == 'N')
	{
		data->dir_x = 0;
		data->dir_y = -1;
	}
	else if (c == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1;
	}
	else if (c == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
	}
	else
	{
		data->dir_x = -1;
		data->dir_y = 0;
	}
}

void	check_player_orientation(t_data *data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] \
			== 'S' || data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				c = data->map[i][j];
				data->pos_x = j + 0.5;
				data->pos_y = i + 0.5;
				set_direction(data, c);
				set_fov(data, c);
			}
			j++;
		}
		i++;
	}
}

void	define_draw(t_data *data)
{
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + HEIGHT / 2;
	if (data->draw_end >= HEIGHT)
		data->draw_end = HEIGHT + 1;
}

void	set_textures_img(t_data *data)
{
	try_no(data);
	try_so(data);
	try_ea(data);
	try_we(data);
	data->ms = 0.10;
	check_player_orientation(data);
}
