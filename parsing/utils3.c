/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:26:27 by mmatthie          #+#    #+#             */
/*   Updated: 2022/12/22 14:07:07 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	neg;
	int	i;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] >= 7 && str[i] <= 13)
		i++;
	if ((str && (str[i] == '+')) || (str && (str[i] == '-')))
	{
		if (str[i] == '-')
			neg -= 2;
		i++;
	}
	while (str && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * neg);
}

int	ft_isdigit(int arg)
{
	if (arg >= 48 && arg <= 57)
		return (0);
	else
		return (1);
}

int	ft_strlen2tab(char	**strs)
{
	int	i;

	i = 0;
	if (strs)
	{
		while (strs[i])
			i++;
	}
	return (i);
}

void	full_free(char	**tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}
