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

#include "cub.h"

void pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->cub.addr + (y * data->cub.line_length + x * (data->cub.bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int rgb_to_int(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}

void    set_fov(t_data *data, char c)
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

void    set_direction(t_data *data, char c)
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

void    check_player_orientation(t_data *data)
{
    int     i;
    int     j;
    char    c;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'N' || data->map[i][j] == 'S' \
            || data->map[i][j] == 'E' || data->map[i][j] == 'W')
            {
                c = data->map[i][j];
                data->posX = j;
                data->posY = i;
                set_direction(data, c);
                set_fov(data, c);
            }
            j++;
        }
        i++;
    }
}

void init_data(t_data *data)
{
    data->path_north = ft_strdup("../textures/NORD.xpm");
    data->path_south = ft_strdup("../textures/SOUTH.xpm");
    data->path_east = ft_strdup("../textures/EAST.xpm");
    data->path_west = ft_strdup("../textures/WEST.xpm");
    data->floor_color = rgb_to_int(255, 122, 0); // parsing manu
    data->top_color = rgb_to_int(152, 192, 0);  // parsing manu
    data->ms = 0.06;
    set_player_pos(data);
}

void build_window(t_data *data)
{
    data->ptr = mlx_init();
    data->mlx_win = mlx_new_window(data->ptr, WIDTH, HEIGHT, "Hello world!");
    data->cub.img_data = mlx_new_image(data->ptr, WIDTH, HEIGHT);
    data->cub.addr = mlx_get_data_addr(data->cub.img_data, &data->cub.bits_per_pixel, &data->cub.line_length, &data->cub.endian);
    mlx_put_image_to_window(data->ptr, data->mlx_win, data->cub.img_data, 0, 0);
    mlx_loop(data->ptr);
}

int main(int ac, char *av[])
{
    t_data data;

	if (ac > 1 && ac < 3)
	{
		if (ft_check_cub(av[1]) == 0)
		{
			if (ft_check_access(av[1]) != -1)
			{
				if (ft_check_dir(av[1]) == -1)
				{
					data.map = parse(av[1]);
					//check_map(map);
					ft_print_split(data.map);
                }

			}
		}
		else
			printf("error\n");
	}
	else
		printf("bad nb of args\n");
    //parsing manu
    init_data(&data);
    build_window(&data);
}
