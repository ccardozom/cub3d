/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:54:35 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/06 13:52:08 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_player_move(t_game *pos)
{
	float	x;
	float	y;
	int 	i;
	int ray;
	

	y = pos->player.pos.y;
	x = pos->player.pos.x;
	i = 0;
	while (i < pos->player.num_rays)
	{ 
		//if (i == pos->player.num_rays / 2)
		ray = 0;
		while (ray < pos->ray_data[i].distance)
		{ 
		my_mlx_pixel_put(&pos->img, (x + cos(pos->ray_data[i].ray_angle) * ray)  * pos->player.minimapscale,
		(y + sin(pos->ray_data[i].ray_angle) * ray)  * pos->player.minimapscale, 0x044D02);
		ray += 1;
		}
		i += 1;
		break;
	}
}
