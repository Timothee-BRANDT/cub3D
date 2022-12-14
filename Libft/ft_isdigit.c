/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:45:23 by tbrandt           #+#    #+#             */
/*   Updated: 2021/10/18 17:37:34 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' & c <= '9')
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int main()
{
	printf("%d", ft_isdigit(4));
	printf("\n");
	printf("%d", isdigit(4));
}*/
