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

void	destroy_window(int keycode, t_data *data)
{
	mlx_destroy_window(data->ptr, data->mlx_win);
	free(data->map);
	exit(2);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		destroy_window(0, data);
	if (keycode == KEY_W)
	{
		move_w(data);
		lets_play(data);
	}
	if (keycode == KEY_S)
	{
		move_s(data);
		lets_play(data);
	}
	/*if (keycode == KEY_A)
		move_a(data);
	if (keycode == KEY_D)
		move_d(data);*/
	return (0);
}