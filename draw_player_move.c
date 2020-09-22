/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:54:35 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/22 00:27:43 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_player_move(t_game *pos)
{
	float	x;
	float	y;
	int 	i;
	float	rayangle_init;
	float	rayangle_finish;

	y = pos->player.y;
	x = pos->player.x;
	rayangle_init = pos->ray.rayangle;
	rayangle_finish = pos->move.player_angle + (pos->cast.FOV_angle / 2)
	i = 0;
	while (rayangle_init < rayangle_finish)
	{
		while (i < 50)
		{
			my_mlx_pixel_put(&pos->img, x + cos(rayangle_init) * i,
			y + sin(rayangle_init) * i, 0x044D02);
			i++;
		}
		rayangle_init += 0.1;
	}
}
