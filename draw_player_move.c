/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:54:35 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/23 20:58:59 by ccardozo         ###   ########.fr       */
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

	y = pos->player.pos.y;
	x = pos->player.pos.x;
	rayangle_init = pos->rays->rayangle;
	rayangle_finish = pos->player.player_angle + (pos->player.FOV_angle / 2);
	
	while (rayangle_init < rayangle_finish)
	{
		i = 0;
		while (i < 50)
		{
			my_mlx_pixel_put(&pos->img, x + cos(rayangle_init) * i,
			y + sin(rayangle_init) * i, 0x044D02);
			i++;
		}
		rayangle_init += 0.1;
	}
}
