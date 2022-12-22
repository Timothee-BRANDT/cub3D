/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:09:26 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/22 13:52:41 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	push_buffer(char **str, char **buffer, char **tmp)
{
	*tmp = ft_strjoin_gnl(*str, *buffer);
	free(*str);
	*str = ft_strdup_gnl(*tmp);
	free(*tmp);
}

void	is_excess(char **str, char **excess)
{
	*str = ft_strjoin_gnl(*str, *excess);
	free(*excess);
	*excess = 0;
}

// second free if empty file
char	*return_line(char **excess, char *str, char *tmp, int read_value)
{
	if (read_value <= 0 && str[0] != '\0')
		return (str);
	if (ft_strchr_gnl(str, '\n') >= 0)
	{
		tmp = ft_strndup_gnl(str, ft_strchr_gnl(str, '\n'));
		*excess = ft_strdup_gnl(str + (ft_strchr_gnl(str, '\n') + 1));
		free(str);
		return (tmp);
	}
	free(str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*excess;
	char		*buffer;
	char		*str;
	char		*tmp;
	int			read_value;

	str = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	read_value = 1;
	is_excess(&str, &excess);
	while ((read_value > 0) && ft_strchr_gnl(str, '\n') < 0)
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		buffer[read_value] = '\0';
		push_buffer(&str, &buffer, &tmp);
	}
	free(buffer);
	str = return_line(&excess, str, tmp, read_value);
	return (str);
}
