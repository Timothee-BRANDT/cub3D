/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:21:16 by mmatthie          #+#    #+#             */
/*   Updated: 2022/12/22 17:26:33 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_checker_for_map(t_data	*data)
{
	int	i;

	i = 0;
	if (data->checker)
	{
		while (data->checker[i])
		{
			if (ft_strncmp_v2(data->checker[i], "0", 1) == 0)
				i++;
			else
				print_and_exit \
				("Error : Problem on the map\n", -1);
		}
	}
}

void	get_position(char c, t_data	*data)
{
	ft_checker_for_map(data);
	if (c == 'N')
		free_and_replace(data, 0, 1);
	else if (c == 'S')
		free_and_replace(data, 1, 1);
	else if (c == 'E')
		free_and_replace(data, 2, 1);
	else if (c == 'W')
		free_and_replace(data, 3, 1);
}

int	check_token2(char c, t_data	*data)
{
	if (c)
	{
		if ((ft_map_token(c)) || (ft_isspace(c)))
		{
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
				get_position(c, data);
			return (1);
		}
	}
	return (0);
}

void	check_map_content(t_data	*data)
{
	int	x;
	int	y;

	x = 6;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (check_token2(data->map[x][y], data))
				y++;
			else
				print_and_exit("Error : Problem on the map\n", -1);
		}
		x++;
	}
}
