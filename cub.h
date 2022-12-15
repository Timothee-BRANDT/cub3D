/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:53:41 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/14 12:05:53 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

#define CUB3D_H
#define BUFFER_SIZE 100

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 960
#define HEIGHT 540

typedef struct s_img
{
	void *img_data;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_img;

typedef struct s_mlx
{
	void *ptr;
	void *mlx_win;
	t_img img;
	t_img map;
} t_mlx;

typedef struct s_text
{
	int		r;
	int		g;
	int		b;
	int		floor;
	int		top;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	t_img	img_north;
	t_img	img_south;
	t_img	img_east;
	t_img	img_west;
}	t_text;

typedef struct t_data
{
	char	**map;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	ray_x;
	double	ray_y;
	double	s_dist_x;
	double	s_dist_y;
	double	delta_x;
	double	delta_y;
	double	cam_x;
	t_mlx	*mlx;
	t_text	*text;
} t_data;

// parsing
int ft_check_cub(char *filename);
size_t ft_strlen(char *str);
int ft_strncmp(char *s1, char *s2, size_t n);
int ft_check_access(char *filename);
int ft_check_dir(char *filename);
char **ft_split(char const *s, char c);
char **parse(char *filename);
char *ft_strjoin(char *s1, char *s2);
void ft_print_split(char **map);
char *ft_strjoin(char *src, char *dest);

#endif