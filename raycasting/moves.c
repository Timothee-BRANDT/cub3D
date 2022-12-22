/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:16:09 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/22 17:06:46 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	move_w(t_data *data)
{
	if ((data->map[(int)data->pos_y][(int) \
	(data->pos_x + data->dir_x * data->ms)]) != '1')
		data->pos_x += data->dir_x * data->ms;
	if ((data->map[(int)(data->pos_y + data->dir_y * data->ms)] \
	[(int)data->pos_x]) != '1')
		data->pos_y += data->dir_y * data->ms;
}

void	move_s(t_data *data)
{
	if ((data->map[(int)data->pos_y] \
	[(int)(data->pos_x - data->dir_x * data->ms)]) != '1')
		data->pos_x -= data->dir_x * data->ms;
	if ((data->map[(int)(data->pos_y - data->dir_y * data->ms)] \
	[(int)data->pos_x]) != '1')
		data->pos_y -= data->dir_y * data->ms;
}

void	move_a(t_data *data)
{
	if (data->map[(int)data->pos_y] \
	[(int)(data->pos_x - data->plane_x * data->ms)] != '1')
		data->pos_x -= data->plane_x * data->ms;
	if (data->map[(int)(data->pos_y - data->plane_y * data->ms)] \
	[(int)data->pos_x] != '1')
		data->pos_y -= data->plane_y * data->ms;
}

void	move_d(t_data *data)
{
	if (data->map[(int)data->pos_y] \
	[(int)(data->pos_x + data->plane_x * data->ms)] != '1')
		data->pos_x += data->plane_x * data->ms;
	if (data->map[(int)(data->pos_y + data->plane_y * data->ms)] \
	[(int)data->pos_x] != '1')
		data->pos_y += data->plane_y * data->ms;
}

void	free_all(t_data	*data)
{
	full_free(data->map);
	free (data->path_north);
	free (data->path_south);
	free (data->path_east);
	free (data->path_west);
}
