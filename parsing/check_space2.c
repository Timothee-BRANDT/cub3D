/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:10:21 by mmatthie          #+#    #+#             */
/*   Updated: 2022/12/22 13:45:39 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_allowed_space(t_data	*data)
{
	int	i;
	int	j;

	i = 6;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0' || check_token3(data->map[i][j]))
			{
				if (i == 6)
					check_allowed_space_first_line(data, i, j);
				else if (i > 6 && i < (ft_strlen2d(data->map) - 1))
					check_allowed_space_rest(data, i, j);
				else if (i == (ft_strlen2d(data->map) - 1))
					check_allowed_space_last_line(data, i, j);
			}
			j++;
		}
		i++;
	}
}

void	check_allowed_space_rest(t_data	*data, int i, int j)
{
	if (data->map[i][j] == '0' || check_token3(data->map[i][j]))
	{
		if (data->map[i][j + 1] && (data->map[i][j + 1] != ' '))
		{
			if (data->map[i][j - 1] && (data->map[i][j - 1] != ' '))
			{
				if (data->map[i + 1][j] && (data->map[i + 1][j] != ' '))
				{
					if (data->map[i - 1][j] && (data->map[i - 1][j] != ' '))
						return ;
					else
						print_and_exit("error unclosed map\n", -1);
				}
				else
					print_and_exit("error unclosed map\n", -1);
			}
			else
				print_and_exit("error unclosed map\n", -1);
		}
		else
			print_and_exit("error unclosed map3\n", -1);
	}
}

void	check_allowed_space_last_line(t_data	*data, int i, int j)
{
	if (data->map[i][j] == '0' || check_token3(data->map[i][j]))
		print_and_exit("unclosed map\n", -1);
}

void	check_allowed_space_first_line(t_data	*data, int i, int j)
{
	if (data->map[i][j] == '0' || check_token3(data->map[i][j]))
		print_and_exit("unclosed map\n", -1);
}

int	check_token3(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	return (0);
}
