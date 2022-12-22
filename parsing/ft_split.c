/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:02:03 by mmatthie          #+#    #+#             */
/*   Updated: 2022/12/22 13:45:39 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static	int	cnt_wd(const char	*str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			j++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (j);
}

static char	*ft_word(const char *str, char c)
{
	int		i;
	char	*wd;

	i = 0;
	while (*str && *str == c)
		str++;
	while (str[i] && str[i] != c)
		i++;
	wd = malloc(sizeof(char) * (i + 1));
	if (wd == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		wd[i] = str[i];
		i++;
	}
	wd[i] = '\0';
	return (wd);
}

void	free_wd(int i, char	**ptr)
{
	while (i >= 0)
	{
		free(ptr[i]);
		ptr[i] = 0;
		i--;
	}
	free (ptr);
}

char	**ft_split(char const	*s, char c)
{
	char	**ptr;
	int		w;
	int		i;

	if (!s || s[0] == '\0')
		return (NULL);
	w = cnt_wd(s, c);
	ptr = malloc(sizeof(char *) * (w + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < w)
	{
		while (*s && *s == c)
			s++;
		ptr[i] = ft_word(s, c);
		if (ptr == NULL)
			free_wd(i, ptr);
		while (*s && *s != c)
			s++;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
