/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:00:13 by mmatthie          #+#    #+#             */
/*   Updated: 2022/12/22 13:45:39 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_so(char	*av, t_data	*data, int index)
{
	int	i;

	i = 0;
	if (av && av[index])
	{
		while (av[index] && ft_isspace(av[index]))
			index++;
		if (av[index] && av[index] == 'S')
		{
			index++;
			if (av[index] && av[index] == 'O' && av[index + 1])
			{
				if (av[index] && av[index] == 'O' && ft_isspace(av[index + 1]))
				{
					get_texture(&av[++index], data, 1);
				}
				else
					print_and_exit("please use space for path texture's\n", -1);
			}
			else
				print_and_exit("please use a valid path\n", -1);
		}
	}
}

void	check_we(char	*av, t_data	*data, int index)
{
	int	i;

	i = 0;
	if (av && av[index])
	{
		while (av[index] && ft_isspace(av[index]))
			index++;
		if (av[index] && av[index] == 'W')
		{
			index++;
			if (av[index] && av[index] == 'E' && av[index + 1])
			{
				if (av[index] && av[index] == 'E' && ft_isspace(av[index + 1]))
					get_texture(&av[++index], data, 2);
				else
					print_and_exit("please use space for path texture's\n", -1);
			}
			else
				print_and_exit("please use a valid path\n", -1);
		}
	}
}

void	check_ea(char	*av, t_data	*data, int index)
{
	int	i;

	i = 0;
	if (av && av[index])
	{
		while (av[index] && ft_isspace(av[index]))
			index++;
		if (av[index] && av[index] == 'E')
		{
			index++;
			if (av[index] && av[index] == 'A' && av[index + 1])
			{
				if (av[index] && av[index] == 'A' && ft_isspace(av[index + 1]))
					get_texture(&av[++index], data, 3);
				else
					print_and_exit("please use space for path texture's\n", -1);
			}
			else
				print_and_exit("please use a valid path\n", -1);
		}
	}
}

void	check_xpm(char	*str)
{
	int	len;

	len = ft_strlen(str);
		len -= 4;
	if (str[len] && str[len] == '.')
	{
		if (str[++len] && str[len] == 'x')
		{
			if (str[++len] && str[len] == 'p')
			{
				if (str[++len] && str[len] == 'm')
					return ;
				else
					print_and_exit("error not a xpm file\n", -1);
			}
			else
				print_and_exit("error not a xpm file\n", -1);
		}
		else
			print_and_exit("error not a xpm file\n", -1);
	}
	else
		print_and_exit("error not a xpm file\n", -1);
}
