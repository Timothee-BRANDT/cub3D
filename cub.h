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
#include "Libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#define WIDTH 920
#define HEIGHT 540

typedef struct s_img
{
	void	*img_data;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_img;

typedef struct t_data
{
	// parsing
	char **checker;
	char *path_north;
	char *path_south;
	char *path_east;
	char *path_west;
	char *C;
	char *F;
	// pointeur window
	void *ptr;
	void *mlx_win;
	// textures
	int r;
	int g;
	int b;
	int floor_color;
	int sky_color;
	t_img img_north;
	t_img img_south;
	t_img img_east;
	t_img img_west;
	// map 
	char	**map;
	// variables for dda and print_pixels
	t_img 	cub;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	ray_x;
	double	ray_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_x;
	double	delta_y;
	double	cam_x;
	double	ms;
	double	wall_distance;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		map_x;
	int		map_y;
	// textures variables
	char	*tex_color;
	char	*tex_pixel;
	int		tex_x;
	int		tex_y;
	double	wall_x;
	double	step;
	double	tex_position;
	int		i;
	int		j;
} t_data;

// parsing
int ft_check_cub(char *filename);
size_t ft_strlen_v2(char *str);
int ft_strncmp_v2(char *s1, char *s2, size_t n);
int ft_check_access(char *filename);
int ft_check_dir(char *filename);
char **ft_split(char const *s, char c);
char **parse(char *filename);
char *ft_strjoin(char *s1, char *s2);
void ft_print_split(char **map);
int ft_isspace(int c);
char *ft_strjoin_v2(char *src, char *dest);
char *ft_strdup(char *str);
void init_checker(t_data *parsing);
int print_and_exit(char *str, int ret);
char *ft_join_free_ss(char *s1, char *s2);
void free_and_replace(t_data *data, int mod, int change);
int ft_check_texture(char *str, t_data *data);
void check_NO(char *av, t_data *data, int index);
void *ft_calloc(size_t count, size_t size);
int ft_atoi(const char *str);
void get_texture(char *str, t_data *data, int mod);
void check_EA(char *av, t_data *data, int index);
void check_WE(char *av, t_data *data, int index);
void check_SO(char *av, t_data *data, int index);
void check_C(char *str, t_data *data, int begin);
void check_F(char *str, t_data *data, int begin);
int ft_isdigit(int arg);
int ft_strlen2tab(char **strs);

//raycasting
int		rgb_to_int(int r, int g, int b);
void	pixel_put(t_data *data, int x, int y, int color);
void	check_player_orientation(t_data *data);
void	set_direction(t_data *data, char c);
void	set_fov(t_data *data, char c);
void	init_data(t_data *data);
void 	set_textures_img(t_data *data);
void	print_sky(t_data *data);
void	print_ground(t_data *data);
void 	dda(t_data *data);
void 	calculate_side_dist(t_data *data);
void 	hit_and_side(t_data *data);
void	lets_play(t_data *data);
void 	build_window(t_data *data);
void 	set_textures_variables(t_data *data);
void	print_pixels(t_data *data);

#endif
