/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:02:42 by mmatthie          #+#    #+#             */
/*   Updated: 2022/12/22 13:45:39 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_space_for_first_line(t_data	*data, int i, int j)
{
	if (data->map[i][j] == ' ')
	{
		if (data->map[i][j + 1] && \
		(data->map[i][j + 1] == '1' || data->map[i][j + 1] == ' '))
		{
			if (data->map[i][j - 1] && \
			(data->map[i][j - 1] == '1' || data->map[i][j - 1] == ' '))
			{
				if (data->map[i + 1][j] && \
				(data->map[i + 1][j] == '1' || data->map[i + 1][j] == ' '))
					return ;
				else
					print_and_exit("error space in map\n", -1);
			}
			else
				print_and_exit("error space in map\n", -1);
		}
		else
			print_and_exit("error space in map\n", -1);
	}
}

void	check_space_for_last_line(t_data	*data, int i, int j)
{
	if (data->map[i][j] == ' ')
	{
		if (data->map[i][j + 1] && \
		(data->map[i][j + 1] == '1' || data->map[i][j + 1] == ' '))
		{
			if (data->map[i][j - 1] && \
			(data->map[i][j - 1] == '1' || data->map[i][j - 1] == ' '))
			{
				if (data->map[i - 1][j] == '1' || data->map[i + 1][j] == ' ')
					return ;
				else
					print_and_exit("error space in map1\n", -1);
			}
			else
				print_and_exit("error space in map2\n", -1);
		}
		else
			print_and_exit("error space in map3\n", -1);
	}
}

void	check_space_side(t_data	*data, int i, int j)
{
	if (data->map[i][j] == ' ')
	{
		if (data->map[i][j + 1] && \
		(data->map[i][j + 1] == '1' || data->map[i][j + 1] == ' '))
		{
			if (data->map[i][j - 1] && \
			(data->map[i][j - 1] == '1' || data->map[i][j - 1] == ' '))
			{
				if (data->map[i + 1][j] && \
				(data->map[i + 1][j] == '1' || data->map[i + 1][j] == ' '))
				{
					if (data->map[i - 1][j] && \
					(data->map[i - 1][j] == '1' || data->map[i + 1][j] == ' '))
						return ;
				}
				else
					print_and_exit("error space in map4\n", -1);
			}
			else
				print_and_exit("error space in map5\n", -1);
		}
		else
			print_and_exit("error space in map6\n", -1);
	}
}

void	check_spaces_in_map(t_data	*data)
{
	int	i;
	int	j;

	i = 6;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == ' ')
			{
				if (i == 6)
					check_space_for_first_line(data, i, j);
				else if (i > 6 && i < (ft_strlen2d(data->map) - 1))
					check_space_side(data, i, j);
				else if (i == (ft_strlen2d(data->map) - 1))
					check_space_for_last_line(data, i, j);
			}
			j++;
		}
		i++;
	}
}

int	check_position(t_data	*data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ft_strncmp_v2(data->checker[i], "1", 1) == 0)
			return (1);
		else
			i++;
	}
	return (0);
}
