/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:07:03 by mmatthie          #+#    #+#             */
/*   Updated: 2022/12/22 17:06:14 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*ft_read_map(int fd)
{
	int		byte_read;
	char	buf[100];
	char	*str;

	str = NULL;
	byte_read = 1;
	while (byte_read)
	{
		byte_read = read(fd, buf, 100);
		if (byte_read == -1)
		{
			write(2, "read error\n", 11);
			exit (-1);
		}
		buf[byte_read] = '\0';
		str = ft_strjoin_v2(str, buf);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	**parse_map(char *filename)
{
	int		fd;
	char	*str;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "error in fd\n", 12);
		exit (-1);
	}
	str = ft_read_map(fd);
	close(fd);
	if (!str)
		return (NULL);
	map = ft_split(str, '\n');
	if (!map)
		return (NULL);
	free (str);
	return (map);
}

void	get_the_map(char	*str, t_data	*data)
{
	data->map = parse_map(str);
	if (!data->map)
		print_and_exit("error in the map set\n", -1);
	init_checker_map(data);
	check_map_content(data);
	check_allowed_space(data);
	if (!check_position(data))
		print_and_exit("please init a position for the player\n", -1);
	data->floor_color = rgb_to_int(data->f[0], data->f[1], data->f[2]);
	data->sky_color = rgb_to_int(data->c[0], data->c[1], data->c[2]);
	free_int_tab(data);
}

void	init_checker_map(t_data	*data)
{
	int	i;

	i = 0;
	if (data->checker)
	{
		while (data->checker[i])
		{
			free(data->checker[i]);
			i++;
		}
	}
	free (data->checker);
	data->checker = malloc(sizeof(char *) * 4 + 1);
	if (!data->checker)
		print_and_exit("malloc error\n", -1);
	data->checker[5] = NULL;
	i = -1;
	while (++i < 5)
		data->checker[i] = ft_strdup_v2("0");
}

void	check_no(char	*av, t_data	*data, int index)
{
	int	i;

	i = 0;
	if (av && av[index])
	{
		if (av[index] && av[index] == 'N' && av[index + 1])
		{
			index++;
			if (av[index] && av[index] == 'O' && av[index + 1])
			{
				if (av[index] && av[index] == 'O' && ft_isspace(av[index + 1]))
					get_texture(&av[++index], data, 0);
				else
					print_and_exit("please use space for path texture's\n", -1);
			}
			else
				print_and_exit("please use a valid path\n", -1);
		}
	}
}
