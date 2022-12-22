/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:28:44 by mmatthie          #+#    #+#             */
/*   Updated: 2022/12/22 15:57:32 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

/*mod is like this  | NO | 0
					| S0 | 1
					| WE | 2
					| EA | 3
					| C  | 4
					| F  | 5
*/

void	insert_text(t_data	*data, int mod, char	*str)
{
	if (mod == 0)
		data->path_north = ft_strdup_v2(str);
	if (mod == 1)
		data->path_south = ft_strdup_v2(str);
	if (mod == 2)
		data->path_west = ft_strdup_v2(str);
	if (mod == 3)
		data->path_east = ft_strdup_v2(str);
}

int	check_path(char	*str, t_data	*data, int mod)
{
	if (str)
	{
		check_xpm(str);
		ft_check_access(str);
		ft_check_dir(str);
		insert_text(data, mod, str);
		free(str);
	}
	return (1);
}

char	*tamerelaputelanorme(int begin, char *str, int i, char *line)
{
	int	count;

	count = begin;
	while (str[begin] && !ft_isspace(str[begin]))
	{
		i++;
		begin++;
	}
	while (str[begin] && ft_isspace(str[begin]))
		begin++;
	if (str[begin] && !ft_isspace(str[begin]))
		print_and_exit("bad syntax\n", -1);
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		print_and_exit("malloc error\n", -1);
	line[i] = '\0';
	i = -1;
	while (str[count] && !ft_isspace(str[count]))
	{
		line[++i] = str[count];
		count++;
	}
	return (line);
	printf("%s\n", line);
}

int	get_path(char	*str, int begin, t_data	*data, int mod)
{
	int		i;
	int		count;
	char	*line;

	i = 0;
	if (str)
	{
		while (str[begin] && ft_isspace(str[begin]))
			begin++;
		if (str[begin])
			line = tamerelaputelanorme(begin, str, i, line);
		else
			print_and_exit("empty texture's path\n", -1);
	}
	return (check_path(line, data, mod));
}

/*char	*fill_line(char	*str, int count, char	*line, int begin)
{
	int	i;

	i = -1;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		print_and_exit("malloc error\n", -1);
	line[begin] = '\0';
	while (str[count] && !ft_isspace(str[count]))
	{
		line[++i] = str[count];
		count++;
	}
	return (line);
}

int	get_path(char	*str, int begin, t_data	*data, int mod)
{
	int		i;
	int		count;
	char	*line;

	i = 0;
	line = NULL;
	if (str)
	{
		while (str[begin] && ft_isspace(str[begin]))
			begin++;
		if (str[begin])
		{
			count = begin;
			while (str[begin] && !ft_isspace(str[begin++]))
				i++;
			while (str[begin] && ft_isspace(str[begin]))
				begin++;
			if (str[begin] && !ft_isspace(str[begin]))
				print_and_exit("bad syntax\n", -1);
			line = fill_line(str, count, line, i);
		}
		else
			print_and_exit("empty texture's path\n", -1);
	}
	return (check_path(line, data, mod));
}*/

void	get_texture(char	*str, t_data	*data, int mod)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str && str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] == '.' && str[i + 1])
		{
			i++;
			if (str[i] == '/' && str[i + 1])
				if (get_path(str, ++i, data, mod) == 1)
					free_and_replace(data, mod, 1);
		}
		else
			print_and_exit("bad texture's path\n", -1);
	}
}
