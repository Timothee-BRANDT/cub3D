/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatthie <mmatthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:20:19 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/22 13:56:11 by mmatthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFFER_SIZE 100

# include	<stdlib.h> // malloc
# include	<unistd.h>	// read
# include	<sys/types.h> // open
# include	<sys/stat.h> // open
# include	<fcntl.h> // open

char	*get_next_line(int fd);
int		ft_strchr_gnl(char *s, int c);
char	*ft_strdup_gnl(char *s);
char	*ft_strndup_gnl(char *s, int n);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strlen_gnl(char *str);

#endif
