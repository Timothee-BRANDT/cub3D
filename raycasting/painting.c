/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:17:20 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/14 12:10:06 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    print_sky(t_data *data)
{
    int i;
    int y;
    int middle;

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

void    print_ground(t_data *data)
{
    int i;
    int y;

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