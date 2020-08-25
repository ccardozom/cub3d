/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:01:10 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/25 09:56:32 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	position_player(t_game *pos, t_pos *tile_pos)
{
	if (tile_pos->y >= (int)(pos->tile.size / 2) && tile_pos->y <= (((int)(pos->tile.size / 2)) + 12))
		if (pos->tile.pos_squa >= (int)(pos->tile.size / 2) &&
		 pos->tile.pos_squa <= (((int)(pos->tile.size / 2)) + 12))
		{
			if (tile_pos->y == (int)(pos->tile.size / 2) &&
			pos->tile.pos_squa == (int)(pos->tile.size / 2))
			{
				pos->player.x = tile_pos->x;
				pos->player.y = pos->tile.squa_f;
			}
			my_mlx_pixel_put(&pos->img, tile_pos->x, pos->tile.squa_f, 0x6495ed);
		}
}