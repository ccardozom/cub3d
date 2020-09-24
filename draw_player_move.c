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

	y = pos->player.pos.y;
	x = pos->player.pos.x;
	i = 0;
	while (i < pos->player.num_rays)
	{
		my_mlx_pixel_put(&pos->img, x + cos(pos->rays[i].rayangle) * pos->rays[i].wallhitX,
		y + sin(pos->rays[i].rayangle) * pos->rays[i].wallhitY, 0x044D02);
		i++;
	}
}
