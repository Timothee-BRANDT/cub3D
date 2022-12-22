/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:47:17 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/22 18:23:09 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->cub.addr + (y * data->cub.line_length + x * \
	(data->cub.bits_per_pixel / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

int	rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	ft_checker(t_data	*data)
{
	int	i;

	i = 0;
	while (data->checker[i])
	{
		if (ft_strcmp(data->checker[i], "0") == 0)
			return (0);
		else
			i++;
	}
	return (1);
}

void	ft_check_map(t_data	*data, char	*filename)
{
	char	*str;
	int		i;

	(void)filename;
	i = 0;
	str = get_next_line(data->fd);
	while (str && !ft_is_empty(str))
	{
		free(str);
		str = get_next_line(data->fd);
	}
	if (str)
	{
		while (str && ft_is_empty(str))
		{
			free (str);
			str = get_next_line(data->fd);
		}
		if (str && !ft_is_empty(str))
			print_and_exit("error bro you put empty line in map\n", -1);
	}
	else
		print_and_exit("empty map\n", -1);
	close (data->fd);
}

void	free_int_tab(t_data	*data)
{
	free (data->c);
	free (data->f);
}
