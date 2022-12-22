/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:09:37 by mmatthie          #+#    #+#             */
/*   Updated: 2022/12/22 14:43:52 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

//need to check .xpm file's

int	ft_check_cub(char	*filename)
{
	char	*str;
	size_t	sizelen;
	int		i;

	sizelen = ft_strlen_v2(filename);
	i = 0;
	while (filename[i] && filename[i] != '.')
	{
		i++;
		sizelen--;
	}
	if (filename[i] && sizelen == 4)
		str = filename + i;
	else
		return (1);
	if (!ft_strncmp_v2(str, ".cub", ft_strlen_v2(str)))
		return (0);
	return (1);
}

int	ft_check_access(char	*filename)
{
	int	fd;

	fd = 0;
	if (filename)
	{
		fd = access(filename, O_RDONLY);
		if (fd == -1)
			print_and_exit("error: access not allowed\n", fd);
	}
	return (1);
}

int	ft_check_dir(char	*filename)
{
	int	i;

	i = open(filename, O_DIRECTORY);
	if (i != -1)
		print_and_exit("error: directory is not allowed\n", -1);
	return (i);
}

void	init_checker(t_data	*parsing)
{
	int	i;

	i = 0;
	parsing->checker = malloc(sizeof(char *) * 6 + 1);
	parsing->checker[6] = NULL;
	while (i < 6)
	{
		parsing->checker[i] = ft_strdup_v2("0");
		i++;
	}
}

int	ft_map_token(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	return (0);
}
