/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:01:10 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/27 14:21:46 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	position_player(t_game *pos, t_pos *tile_pos)
{
	if (tile_pos->y == (int)(pos->tile.size / 2) &&
	pos->tile.pos_squa == (int)(pos->tile.size / 2))
	{
		pos->player.pos.x = tile_pos->x;
		pos->player.pos.y = pos->tile.squa_f;
	}
	pos->player.player_control += 1;
}
