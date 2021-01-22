/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 09:16:28 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/21 15:33:11 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void		player_direction(t_game *pos, t_pos *tile_pos)
{
	if (pos->map[pos->tile.f][pos->tile.c] == 'N')
	{
		position_player(pos, tile_pos);
		pos->player.player_angle = PI * 1.5;
	}
	if (pos->map[pos->tile.f][pos->tile.c] == 'S')
	{
		position_player(pos, tile_pos);
		pos->player.player_angle = PI / 2;
	}
	if (pos->map[pos->tile.f][pos->tile.c] == 'E')
	{
		position_player(pos, tile_pos);
		pos->player.player_angle = 2 * PI;
	}
	if (pos->map[pos->tile.f][pos->tile.c] == 'W')
	{
		position_player(pos, tile_pos);
		pos->player.player_angle = PI;
	}
}

int			put_color(t_game *pos)
{
	t_pos	tile_pos;

	tile_pos.x = pos->tile.squa_c;
	tile_pos.y = 0;
	while (tile_pos.y < pos->tile.size)
	{
		player_direction(pos, &tile_pos);
		tile_pos.y++;
		tile_pos.x++;
	}
	return (pos->tile.size);
}

void		draw_player(t_game *pos)
{
	pos->tile.squa_f = 0;
	pos->tile.pos_squa = 0;
	pos->tile.f = 0;
	while (pos->tile.f < pos->rows)
	{
		pos->tile.c = 0;
		pos->tile.squa_c = 0;
		while (pos->tile.c < pos->columns)
		{
			pos->tile.squa_c += put_color(pos);
			pos->tile.c++;
		}
		pos->tile.squa_f++;
		pos->tile.pos_squa++;
		if (pos->tile.pos_squa >= pos->tile.size)
		{
			pos->tile.f++;
			pos->tile.pos_squa = 0;
		}
	}
}
