/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:47:17 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/22 18:23:54 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char *av[])
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (ac > 1 && ac < 3)
	{
		if (ft_check_cub(av[1]) == 0)
		{
			ft_check_access(av[1]);
			if (ft_check_dir(av[1]) == -1)
			{
				init_checker(data);
				parse(av[1], data);
				ft_check_map(data, av[1]);
				get_the_map(av[1], data);
				build_window(data);
			}
		}
		else
			printf("error\n");
	}
	else
		printf("bad nb of args\n");
}
