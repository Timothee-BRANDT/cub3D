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
/* ****************************************************************************/

#include "cub.h"

void pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->cub.addr + (y * data->cub.line_length + x * (data->cub.bits_per_pixel / 8));
    *(unsigned int *)dst = (unsigned int)color;
}

int rgb_to_int(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}