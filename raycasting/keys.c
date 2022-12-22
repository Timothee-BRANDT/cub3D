/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:57:19 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/22 17:12:12 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	destroy_window(int keycode, t_data *data)
{
	mlx_destroy_window(data->ptr, data->mlx_win);
	free(data->map);
	exit(2);
}

void	rotate_left(t_data *data)
{
	double	rotate;
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	rotate = 0.10;
	data->dir_x = data->dir_x * cos(-rotate) - data->dir_y * sin(-rotate);
	data->dir_y = old_dir_x * sin(-rotate) + data->dir_y * cos(-rotate);
	data->plane_x = data->plane_x * cos(-rotate) - data->plane_y * sin(-rotate);
	data->plane_y = old_plane_x * sin(-rotate) + data->plane_y * cos(-rotate);
}

void	rotate_right(t_data *data)
{
	double	rotate;
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	rotate = 0.10;
	data->dir_x = data->dir_x * cos(rotate) - data->dir_y * sin(rotate);
	data->dir_y = old_dir_x * sin(rotate) + data->dir_y * cos(rotate);
	data->plane_x = data->plane_x * cos(rotate) - data->plane_y * sin(rotate);
	data->plane_y = old_plane_x * sin(rotate) + data->plane_y * cos(rotate);
}

void	move(t_data *data, int code)
{
	if (code == KEY_W)
		move_w(data);
	if (code == KEY_S)
		move_s(data);
	if (code == KEY_A)
		move_a(data);
	if (code == KEY_D)
		move_d(data);
	if (code == KEY_LEFT)
		rotate_left(data);
	if (code == KEY_RIGHT)
		rotate_right(data);
	lets_play(data);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		destroy_window(0, data);
	if (keycode == KEY_W)
		move(data, KEY_W);
	if (keycode == KEY_S)
		move(data, KEY_S);
	if (keycode == KEY_A)
		move(data, KEY_A);
	if (keycode == KEY_D)
		move(data, KEY_D);
	if (keycode == KEY_LEFT)
		move(data, KEY_LEFT);
	if (keycode == KEY_RIGHT)
		move(data, KEY_RIGHT);
	return (0);
}
