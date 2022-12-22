/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:57:19 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/20 15:32:15 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	destroy_window(int keycode, t_data *data)
{
	mlx_destroy_window(data->ptr, data->mlx_win);
	free(data->map);
	exit(2);
}

int	exit_game(t_data *data)
{
	free(data->map);
	exit(1);
}

void	rotate_left(t_data *data)
{
	double	rotate;
	double	old_dirX;
	double	old_planeX;

	old_dirX = data->dirX;
	old_planeX = data->planeX;
	rotate = 0.10;
	data->dirX = data->dirX * cos(-rotate) - data->dirY * sin(-rotate);
	data->dirY = old_dirX * sin(-rotate) + data->dirY * cos(-rotate);
	data->planeX = data->planeX * cos(-rotate) - data->planeY * sin(-rotate);
	data->planeY = old_planeX * sin(-rotate) + data->planeY * cos(-rotate);
}

void	rotate_right(t_data *data)
{
	double	rotate;
	double	old_dirX;
	double	old_planeX;

	old_dirX = data->dirX;
	old_planeX = data->planeX;
	rotate = 0.10;
	data->dirX = data->dirX * cos(rotate) - data->dirY * sin(rotate);
	data->dirY = old_dirX * sin(rotate) + data->dirY * cos(rotate);
	data->planeX = data->planeX * cos(rotate) - data->planeY * sin(rotate);
	data->planeY = old_planeX * sin(rotate) + data->planeY * cos(rotate);
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