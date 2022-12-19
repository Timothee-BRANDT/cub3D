/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:43:17 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/17 16:10:06 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void hit_and_side(t_data *data)
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

void calculate_side_dist(t_data *data)
{
    if (data->ray_x < 0)
    {
        data->step_x = -1;
        data->side_dist_x = (data->posX - data->map_x) * data->delta_x;
    }
    else
    {
        data->step_x = 1;
        data->side_dist_x = (data->map_x + 1.0 - data->posX) * data->delta_x;
    }
    if (data->ray_y < 0)
    {
        data->step_y = -1;
        data->side_dist_y = (data->posY - data->map_y) * data->delta_y;
    }
    else
    {
        data->step_y = 1;
        data->side_dist_y = (data->map_y + 1.0 - data->posY) * data->delta_y;
    }
}

void dda(t_data *data, int x)
{
    data->cam_x = 2 * x / (double)(WIDTH)-1;
    data->ray_x = data->dirX + data->planeX * data->cam_x;
    data->ray_y = data->dirY + data->planeY * data->cam_x;
    data->map_x = (int)data->posX;
    data->map_y = (int)data->posY;
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

void    lets_play(t_data *data)
{
    int i;

    i = 0;
    while (i < WIDTH)
    {
        dda(data, i);
        i++;
    }
}