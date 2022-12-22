/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:16:09 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/22 13:59:14 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void move_w(t_data *data)
{
	if ((data->map[(int)data->posY][(int)(data->posX + data->dirX * data->ms)]) != '1')
		data->posX += data->dirX * data->ms;
	if ((data->map[(int)(data->posY + data->dirY * data->ms)][(int)data->posX]) != '1')
		data->posY += data->dirY * data->ms;
}

void move_s(t_data *data)
{
	if ((data->map[(int)data->posY][(int)(data->posX - data->dirX * data->ms)]) != '1')
		data->posX -= data->dirX * data->ms;
	if ((data->map[(int)(data->posY - data->dirY * data->ms)][(int)data->posX]) != '1')
		data->posY -= data->dirY * data->ms;
}

void move_a(t_data *data)
{
	if (data->map[(int)data->posY][(int)(data->posX - data->planeX * data->ms)] != '1')
		data->posX -= data->planeX * data->ms;
	if (data->map[(int)(data->posY - data->planeY * data->ms)][(int)data->posX] != '1')
		data->posY -= data->planeY * data->ms;
}

void move_d(t_data *data)
{
	if (data->map[(int)data->posY][(int)(data->posX + data->planeX * data->ms)] != '1')
		data->posX += data->planeX * data->ms;
	if (data->map[(int)(data->posY + data->planeY * data->ms)][(int)data->posX] != '1')
		data->posY += data->planeY * data->ms;
}

void	free_all(t_data	*data)
{
	full_free(data->map);
	free (data->path_north);
	free (data->path_south);
	free (data->path_east);
	free (data->path_west);
}
