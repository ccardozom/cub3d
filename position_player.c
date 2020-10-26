/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:01:10 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/27 00:38:50 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	position_player(t_game *pos, t_pos *tile_pos)
{
	if (tile_pos->y >= (int)(pos->tile.size / 2) && tile_pos->y <=
	(((int)(pos->tile.size / 2)) + 12))
		if (pos->tile.pos_squa >= (int)(pos->tile.size / 2) &&
		pos->tile.pos_squa <= (((int)(pos->tile.size / 2)) + 12))
		{
			if (tile_pos->y == (int)(pos->tile.size / 2) &&
			pos->tile.pos_squa == (int)(pos->tile.size / 2))
			{
				pos->player.pos.x = tile_pos->x;
				pos->player.pos.y = pos->tile.squa_f;
			}
			my_mlx_pixel_put(&pos->img, tile_pos->x * pos->player.minimapscale,
			pos->tile.squa_f * pos->player.minimapscale, 0x6495ed);
		}
	pos->player.player_control += 1;
}

void	sprite_position(t_sprite *sprites, t_game *pos, int pos_x, int pos_y)
{
	int		x;
	int		y;
	
	x = pos_x;
	y = pos_y;
	pos_x = (int)(pos_x / pos->tile.size);
	pos_x *= pos->tile.size;
	pos_y = (int)(pos_y / pos->tile.size);
	pos_y *= pos->tile.size;
	if (x == pos_x + (pos->tile.size / 2) && y == pos_y + (pos->tile.size / 2))
	{
		sprites->pos.x = x;
		sprites->pos.y = y;
	}
}
