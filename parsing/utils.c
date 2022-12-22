/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:01:31 by mmatthie          #+#    #+#             */
/*   Updated: 2022/12/22 13:45:39 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_strncmp_v2(char	*s1, char	*s2, size_t	n)
{
	size_t			i;
	unsigned char	str1;
	unsigned char	str2;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		str1 = (unsigned char)s1[i];
		str2 = (unsigned char)s2[i];
		if (str1 != str2)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen_v2(char	*str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_print_split(char	**map)
{
	size_t	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			printf("%s\n", map[i]);
			i++;
		}
	}
	else
		printf("Map is empty.\n");
}

int	print_and_exit(char	*str, int ret)
{
	write(2, str, ft_strlen_v2(str));
	exit(ret);
}

int	ft_isspace(int c)
{
	if ((c == '\n') || (c == '\v') \
	|| ((c == '\r') || (c == '\f') || (c == ' ')))
		return (1);
	return (0);
}
