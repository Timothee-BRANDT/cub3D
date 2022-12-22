/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:53:41 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/22 18:05:06 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H

# define CUB_H

# include "minilibx/mlx.h"
# include "Libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <float.h>
# include <math.h>

# define WIDTH 920
# define HEIGHT 540

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct s_img
{
	void	*img_data;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct t_data
{
	char	**checker;
	char	**map;
	char	*path_north;
	char	*path_south;
	char	*path_east;
	char	*path_west;
	int		boucle;
	int		*c;
	int		*f;
	int		fd;
	void	*ptr;
	void	*mlx_win;
	t_img	cub;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
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
	t_img	img_north;
	t_img	img_south;
	t_img	img_east;
	t_img	img_west;
	int		r;
	int		g;
	int		b;
	int		floor_color;
	int		sky_color;
	int		tex_x;
	int		tex_y;
	int		i;
	int		j;
	double	wall_x;
	double	step;
	double	tex_position;
	char	*tex_color;
	char	*tex_pixel;
	int		tex_size;
}	t_data;

// parsing
int		ft_check_cub(char	*filename);
size_t	ft_strlen_v2(char	*str);
int		ft_strncmp_v2(char	*s1, char	*s2, size_t	n);
int		ft_check_access(char	*filename);
int		ft_check_dir(char	*filename);
char	**ft_split(char const	*s, char c);
void	parse(char *filename, t_data	*data);
char	*ft_strjoin_v2(char *s1, char *s2);
void	ft_print_split(char	**map);
int		ft_isspace(int c);
char	*ft_strjoin_v2(char	*src, char	*dest);
char	*ft_strdup_v2(char	*str);
void	init_checker(t_data	*parsing);
int		print_and_exit(char	*str, int ret);
char	*ft_join_free_ss(char *s1, char *s2);
void	free_and_replace(t_data	*data, int mod, int change);
void	ft_check_texture(char	*str, t_data	*data);
void	*ft_calloc( size_t	count, size_t	size);
int		ft_atoi(const char *str);
void	get_texture(char	*str, t_data	*data, int mod);
char	*ft_itoa_v2(int n);
int		ft_checker(t_data	*data);
void	check_no(char	*av, t_data	*data, int index);
void	check_ea(char	*av, t_data	*data, int index);
void	check_we(char	*av, t_data	*data, int index);
void	check_so(char	*av, t_data	*data, int index);
void	check_c(char	*str, t_data	*data, int begin);
void	check_f(char	*str, t_data	*data, int begin);
int		ft_isdigit(int arg);
int		ft_strlen2tab(char	**strs);
int		ft_checker(t_data	*data);
void	ft_print_data(t_data	*data);
int		ft_check_access_texture(char	*filename);
void	full_free(char	**tab);
int		ft_is_empty(char	*str);
void	ft_check_map(t_data	*data, char	*filename);
char	*ft_read_map(int fd);
char	**parse_map(char *filename);
void	check_map_content(t_data	*data);
void	get_the_map(char	*str, t_data	*data);
void	check_allowed_space_first_line(t_data	*data, int i, int j);
void	check_allowed_space_rest(t_data	*data, int i, int j);
void	check_allowed_space_last_line(t_data	*data, int i, int j);
int		check_token3(char c);
void	init_checker_map(t_data	*data);
int		rgb_to_int(int r, int g, int b);
void	free_int_tab(t_data	*data);
void	check_no(char	*av, t_data	*data, int index);
int		ft_map_token(char c);
void	init_checker_map(t_data	*data);
void	check_allowed_space(t_data	*data);
int		check_position(t_data	*data);
void	check_xpm(char	*str);

//raycasting
int		rgb_to_int(int r, int g, int b);
void	pixel_put(t_data *data, int x, int y, int color);
void	check_player_orientation(t_data *data);
void	set_direction(t_data *data, char c);
void	set_fov(t_data *data, char c);
void	init_data(t_data *data);
void	set_textures_img(t_data *data);
void	print_sky(t_data *data);
void	print_ground(t_data *data);
void	dda(t_data *data);
void	calculate_side_dist(t_data *data);
void	hit_and_side(t_data *data);
void	lets_play(t_data *data);
void	build_window(t_data *data);
void	set_textures_variables(t_data *data);
void	print_pixels(t_data *data);
int		destroy_window(int keycode, t_data *data);
int		ft_close(t_data *data);
int		key_press(int keycode, t_data *data);
int		exit_game(t_data *data);
void	try_no(t_data *data);
void	try_so(t_data *data);
void	try_ea(t_data *data);
void	try_we(t_data *data);
void	move_w(t_data *data);
void	move_s(t_data *data);
void	move_a(t_data *data);
void	move_d(t_data *data);
void	rotate_left(t_data *data);
void	rotate_right(t_data *data);
void	wich_texture(t_data *data);
void	define_draw(t_data *data);
#endif
