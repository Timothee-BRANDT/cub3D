/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:16:09 by tbrandt           #+#    #+#             */
/*   Updated: 2022/12/20 15:31:18 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	move_w(t_data *data)
{
   if((data->map[(int)data->posY][(int)(data->posX + data->dirX * data->ms)]) != '1')
		data->posX += data->dirX * data->ms;
   if((data->map[(int)(data->posY + data->dirY * data->ms)][(int)data->posX]) != '1')
		data->posY += data->dirY * data->ms;
}

void	move_s(t_data *data)
{
	if((data->map[(int)data->posY][(int)(data->posX - data->dirX * data->ms)]) != '1')
		data->posX -= data->dirX * data->ms;
   if((data->map[(int)(data->posY - data->dirY * data->ms)][(int)data->posX]) != '1')
		data->posY -= data->dirY * data->ms;
}