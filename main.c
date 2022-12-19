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

void build_window(t_data *data)
{
    data->ptr = mlx_init();
    data->mlx_win = mlx_new_window(data->ptr, WIDTH, HEIGHT, "Hello world!");
    init_data(data);
    data->cub.img_data = mlx_new_image(data->ptr, WIDTH, HEIGHT);
    data->cub.addr = mlx_get_data_addr(data->cub.img_data, &data->cub.bits_per_pixel, &data->cub.line_length, &data->cub.endian);
    set_textures_img(data);
	print_sky(data);
	print_ground(data);
	lets_play(data);
    mlx_put_image_to_window(data->ptr, data->mlx_win, data->cub.img_data, 0, 0);
    mlx_loop(data->ptr);
}

int main(int ac, char *av[])
{
    t_data *data;

	data = malloc(sizeof(t_data));
	if (ac > 1 && ac < 3)
	{
		if (ft_check_cub(av[1]) == 0)
		{
			if (ft_check_access(av[1]) != -1)
			{
				if (ft_check_dir(av[1]) == -1)
				{
					data->map = parse(av[1]);
					//check_map(map);
					ft_print_split(data->map);
                }

			}
		}
		else
			printf("error\n");
	}
	else
		printf("bad nb of args\n");
    //parsing manu
    build_window(data);
}
