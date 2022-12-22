/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:19:15 by mmatthie          #+#    #+#             */
/*   Updated: 2022/12/22 17:06:14 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

// RGB color function take 3 int between 0 > 255

void	get_rgb(char	**tab, t_data	*data, int mod)
{
	int	i;

	i = -1;
	if (tab)
	{
		if (mod == 1)
		{
			data->c = malloc(sizeof(int) * 3);
			if (!data->c)
				print_and_exit("malloc error\n", -1);
			while (++i <= 2)
				data->c[i] = ft_atoi(tab[i]);
		}
		else if (mod == 2)
		{
			data->f = malloc(sizeof(int) * 3);
			if (!data->f)
				print_and_exit("malloc error\n", -1);
			while (++i <= 2)
				data->f[i] = ft_atoi(tab[i]);
		}
	}
}

void	check_tab_content(char	**tab)
{
	int	i;
	int	j;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			j = 0;
			while (tab[i][j])
			{
				if (ft_isdigit(tab[i][j]))
					print_and_exit \
					("need only positive number's on color's\n", -1);
				else
					j++;
			}
			i++;
		}
	}
}

void	check_tab(char	**tab, char	*str, t_data	*data, int mod)
{
	int	a;
	int	b;
	int	c;

	(void)str;
	check_tab_content(tab);
	a = ft_atoi(tab[0]);
	b = ft_atoi(tab[1]);
	c = ft_atoi(tab[2]);
	if ((a < 0 || a > 255) || (b < 0 || b > 255) || (c < 0 || c > 255))
		print_and_exit("only use int from 0 to 255 for color's\n", -1);
	get_rgb(tab, data, mod);
	if (mod == 1)
		free_and_replace(data, 4, 1);
	else if (mod == 2)
		free_and_replace(data, 5, 1);
}

void	check_c(char	*str, t_data	*data, int begin)
{
	char	**tab;
	char	*tmp;

	if (str[begin] && str[begin] == 'C')
		begin++;
	while (str[begin] && ft_isspace(str[begin]))
		begin++;
	if (str[begin])
	{
		tab = ft_split(&str[begin], '\n');
		if (!tab)
			print_and_exit("split error\n", -1);
		tmp = ft_strdup_v2(tab[0]);
		full_free(tab);
		tab = ft_split(tmp, ',');
		if (!tab)
			print_and_exit("split error", -1);
		if (ft_strlen2tab(tab) < 4)
			check_tab(tab, str, data, 1);
		free (tmp);
		full_free(tab);
	}
	else
		print_and_exit("color cannot be empty\n", -1);
}

void	check_f(char	*str, t_data	*data, int begin)
{
	char	**tab;
	char	*tmp;

	if (str[begin] && str[begin] == 'F')
		begin++;
	while (str[begin] && ft_isspace(str[begin]))
		begin++;
	if (str[begin])
	{
		tab = ft_split(&str[begin], '\n');
		if (!tab)
			print_and_exit("split error\n", -1);
		tmp = ft_strdup_v2(tab[0]);
		full_free(tab);
		tab = ft_split(tmp, ',');
		if (!tab)
			print_and_exit("split error", -1);
		if (ft_strlen2tab(tab) < 4)
			check_tab(tab, str, data, 2);
		free (tmp);
		full_free(tab);
	}
	else
		print_and_exit("color cannot be empty\n", -1);
}
