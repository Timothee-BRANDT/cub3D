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

void pixel_put(t_mlx *mlx, int x, int y, int color)
{
    char *dst;

    dst = mlx->img.addr + (y * mlx->img.line_length + x * (mlx->img.bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int rgb_to_int(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}

void init_data(t_data *data)
{
    data->text = malloc(sizeof(t_text));
    data->text->north = ft_strdup("../textures/NORD.xpm");
    data->text->south = ft_strdup("../textures/SOUTH.xpm");
    data->text->east = ft_strdup("../textures/EAST.xpm");
    data->text->west = ft_strdup("../textures/WEST.xpm");
    data->text->floor = rgb_to_int(255, 122, 0); // parsing manu
    data->text->top = rgb_to_int(152, 192, 0);  // parsing manu
    data->posX = 22;
    data->posY = 12;
    data->dirX = -1;
    data->dirY = 0;
    data->planeX = 0;
    data->planeY = 0.66;
}

void build_window(t_data *data)
{
    data->mlx = malloc(sizeof(t_mlx));
    data->mlx->ptr = mlx_init();
    data->mlx->mlx_win = mlx_new_window(data->mlx->ptr, WIDTH, HEIGHT, "Hello world!");
    data->mlx->img.img_data = mlx_new_image(data->mlx->ptr, WIDTH, HEIGHT);
    data->mlx->img.addr = mlx_get_data_addr(data->mlx->img.img_data, &data->mlx->img.bits_per_pixel, &data->mlx->img.line_length, &data->mlx->img.endian);
    mlx_put_image_to_window(data->mlx->ptr, data->mlx->mlx_win, data->mlx->img.img_data, 0, 0);
    mlx_loop(data->mlx->ptr);
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
    printf("1\n");
    build_window(&data);
}
