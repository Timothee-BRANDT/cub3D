/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:11:13 by tbrandt           #+#    #+#             */
/*   Updated: 2021/10/28 14:08:58 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*overflow(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
		return (ft_strdup("2147483647"));
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648 || n == 2147483647)
		return (overflow(n));
	str = malloc(sizeof(char) * len(n) + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	i = len(n);
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1 ;
	}
	str[i] = '\0';
	i--;
	while (n > 0)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (str);
}
