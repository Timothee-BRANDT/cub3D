/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:47:17 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/20 15:52:32 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void set_fov(t_data *data, char c)
{
    if (c == 'N')
    {
        data->planeX = 0.66;
        data->planeY = 0;
    }
    else if (c == 'S')
    {
        data->planeX = -0.66;
        data->planeY = 0;
    }
    else if (c == 'E')
    {
        data->planeY = 0.66;
        data->planeX = 0;
    }
    else
    {
        data->planeY = -0.66;
        data->planeX = 0;
    }
}

void set_direction(t_data *data, char c)
{
    if (c == 'N')
    {
        data->dirX = 0;
        data->dirY = -1;
    }
    else if (c == 'S')
    {
        data->dirX = 0;
        data->dirY = 1;
    }
    else if (c == 'E')
    {
        data->dirX = 1;
        data->dirY = 0;
    }
    else
    {
        data->dirX = -1;
        data->dirY = 0;
    }
}

void check_player_orientation(t_data *data)
{
    int i;
    int j;
    char c;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || data->map[i][j] == 'E' || data->map[i][j] == 'W')
            {
                c = data->map[i][j];
                data->posX = j + 0.5;
                data->posY = i + 0.5;
                set_direction(data, c);
                set_fov(data, c);
            }
            j++;
        }
        i++;
    }
}

void    set_textures_img(t_data *data)
{
    int a = 64;
    int b = 64;

    data->img_north.img_data = mlx_xpm_file_to_image(data->ptr, data->path_north, &a, &b);
    data->img_north.addr = mlx_get_data_addr(data->img_north.img_data, &data->img_north.bits_per_pixel, &data->img_north.line_length, &data->img_north.endian);
    data->img_south.img_data = mlx_xpm_file_to_image(data->ptr, data->path_south, &a, &b);
    data->img_south.addr = mlx_get_data_addr(data->img_south.img_data, &data->img_south.bits_per_pixel, &data->img_south.line_length, &data->img_south.endian);
    data->img_east.img_data = mlx_xpm_file_to_image(data->ptr, data->path_east, &a, &b);
    data->img_east.addr = mlx_get_data_addr(data->img_east.img_data, &data->img_east.bits_per_pixel, &data->img_east.line_length, &data->img_east.endian);
    data->img_west.img_data = mlx_xpm_file_to_image(data->ptr, data->path_west, &a, &b);
    data->img_west.addr = mlx_get_data_addr(data->img_west.img_data, &data->img_west.bits_per_pixel, &data->img_west.line_length, &data->img_west.endian);
}

void init_data(t_data *data)
{
    data->path_north = ft_strdup("textures/basalt.xpm");
    data->path_south = ft_strdup("textures/cracked_wall.xpm");
    data->path_east = ft_strdup("textures/diamond.xpm");
    data->path_west = ft_strdup("textures/furnace_front_on.xpm");
    data->floor_color = rgb_to_int(124, 122, 0); // parsing manu
    data->sky_color = rgb_to_int(0, 255, 255);   // parsing manu
    data->ms = 0.15;
    check_player_orientation(data);
}