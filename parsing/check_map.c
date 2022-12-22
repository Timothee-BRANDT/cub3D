/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:07:44 by mmatthie          #+#    #+#             */
/*   Updated: 2022/12/22 17:28:43 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_token(char c)
{
	if (c)
	{
		if (c == 'N')
			return (0);
		else if (c == 'S')
			return (1);
		else if (c == 'W')
			return (2);
		else if (c == 'E')
			return (3);
		else if (c == 'C')
			return (4);
		else if (c == 'F')
			return (5);
		else
			return (-1);
	}
	else
		return (42);
}

void	ft_texture(int mod, char	*path, int begin, t_data	*data)
{
	if (mod == 0)
		check_no(path, data, begin);
	if (mod == 1)
		check_so(path, data, begin);
	if (mod == 2)
		check_we(path, data, begin);
	if (mod == 3)
		check_ea(path, data, begin);
	if (mod == 4)
		check_c(path, data, begin);
	if (mod == 5)
		check_f(path, data, begin);
}

void	ft_check_texture(char	*str, t_data	*data)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (str)
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i])
		{
			res = check_token(str[i]);
			if (res == -1)
				print_and_exit("Error : Problem in texture path\n", -1);
			else
				ft_texture(res, str, i, data);
		}
	}
}
