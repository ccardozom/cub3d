/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:54:35 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/15 17:11:57 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void	draw_player_move(t_game *pos)
{
	float	x;
	float	y;

printf("\nposicion player (%f, %f)\n", pos->player.y, pos->player.x);

	y = pos->player.y;
	x = pos->player.x;

	float	ini_ray;
	float	end_ray;
	int i;
	
	ini_ray = pos->move.player_angle - (pos->cast.FOV_angle / 2);
	end_ray = pos->move.player_angle + (pos->cast.FOV_angle / 2);
	while (ini_ray < end_ray)
	{
		i = 0;
		while (i < 50)
		{
			//printf("%f %f ",x + cos(ini_ray) * i,y + sin(ini_ray) * i);
			my_mlx_pixel_put(&pos->img, x + cos(ini_ray) * i,
			y + sin(ini_ray) * i, 0xFCE904);
			i++;
		}
		ini_ray += 0.01;
	}
}