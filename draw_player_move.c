/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:54:35 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/24 18:36:23 by ccardozo         ###   ########.fr       */
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
		ray = 0;
		while (ray < pos->ray_data[i].distance)
		{ 
		my_mlx_pixel_put(&pos->img, x + cos(pos->ray_data[i].rayangle) * ray,
		y + sin(pos->ray_data[i].rayangle) * ray, 0x044D02);
		ray += 10;
		}
		i += 10;
	}
}
