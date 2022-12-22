/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:12:35 by mmatthie          #+#    #+#             */
/*   Updated: 2022/12/22 18:25:30 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*ft_read_file(int fd)
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
			exit(-1);
		}
		buf[byte_read] = '\0';
		str = ft_strjoin_v2(str, buf);
		if (!str)
			return (NULL);
	}
	return (str);
}

int	ft_is_empty(char	*str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (ft_isspace(str[i]))
				i++;
			else
				return (1);
		}
	}
	return (0);
}

void	parse(char *filename, t_data	*data)
{
	char	*str;

	(void)data;
	data->fd = open(filename, O_RDONLY);
	if (data->fd == -1)
		print_and_exit("error in open\n", -1);
	str = get_next_line(data->fd);
	while (str && !ft_checker(data))
	{
		if (str && !ft_is_empty(str) && !ft_checker(data))
			free (str);
		else if (str && ft_is_empty(str) && !ft_checker(data))
		{
			ft_check_texture(str, data);
			free (str);
		}
		if (!ft_checker(data))
			str = get_next_line(data->fd);
	}
	if (!ft_checker(data))
		print_and_exit("texture uncompleted\n", -1);
}

void	*ft_calloc( size_t	count, size_t	size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (!(ptr))
		return (NULL);
	while (i < count * size)
		*(char *)(ptr + i++) = 0;
	return (ptr);
}

char	*ft_strjoin_v2(char	*s1, char	*s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen_v2(s1) + ft_strlen_v2(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	free (s1);
	return (str);
}
