/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:10:47 by mmatthie          #+#    #+#             */
/*   Updated: 2022/12/22 14:25:42 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*ft_strdup_v2(char	*str)
{
	int		i;
	char	*newline;

	i = ft_strlen_v2(str);
	newline = NULL;
	if (!i)
		return (NULL);
	newline = malloc(sizeof(char) * i + 1);
	if (!newline)
		return (NULL);
	i = 0;
	while (str[i])
	{
		newline[i] = str[i];
		i++;
	}
	newline[i] = '\0';
	return (newline);
}

char	*ft_join_free_ss(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1)
	{
		s1 = ft_calloc(1, 1);
		if (!s1)
			return (NULL);
	}
	if (!s2)
		return (NULL);
	join = malloc(sizeof(char) * ft_strlen_v2(s1) + ft_strlen_v2(s2) + 1);
	if (!join)
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free(s1);
	free(s2);
	return (join);
}

static int	get_len(int n)
{
	int	res;

	res = 0;
	if (!n)
		return (1);
	if (n < 0)
		res++;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa_v2(int n)
{
	char	*res;
	int		len_res;

	if (n == -2147483648)
		return (ft_strdup_v2("-2147483648"));
	len_res = (get_len(n));
	res = malloc(sizeof(char) * len_res + 1);
	if (!res)
		return (NULL);
	if (n == 0 || (!n))
		res[0] = '0';
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[len_res] = '\0';
	while (n)
	{
		res[--len_res] = (n % 10) + 48;
		n /= 10;
	}
	return (res);
}

void	free_and_replace(t_data	*data, int mod, int change)
{
	(void)change;
	free(data->checker[mod]);
	data->checker[mod] = ft_strdup_v2("1");
}
