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
