/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 09:57:34 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/06 14:02:11 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		control_wall_y(t_game *pos, int new_pos)
{
	int position_x;
	int position_y;

	position_x = (int)(pos->player.pos.x / pos->tile.size);
	position_y = (int)(new_pos / pos->tile.size);
	if (pos->map[position_y][position_x] == '1')
		return (1);
	return (0);
}

int		control_wall_x(t_game *pos, float new_pos)
{
	int position_x;
	int position_y;

	position_x = (int)(new_pos / pos->tile.size);
	position_y = (int)(pos->player.pos.y / pos->tile.size);
	if (pos->map[position_y][position_x] == '1')
		return (1);
	return (0);
}

void	update_player(t_game *pos)
{
	float new_player_x;
	float new_player_y;
	float move_step;

	new_player_x = 0;
	new_player_y = 0;
	pos->player.player_angle += pos->player.turn * pos->player.rotationspeed;
	pos->player.player_angle = normalizeangle(pos->player.player_angle);
	move_step = pos->player.walk * pos->player.movespeed;
	new_player_x = pos->player.pos.x + cos(pos->player.player_angle) * move_step;
	new_player_y = pos->player.pos.y + sin(pos->player.player_angle) * move_step;
	if (new_player_x)
	{
		if (control_wall_x(pos, new_player_x) == 0)
			pos->player.pos.x = new_player_x;
	}
	if (new_player_y)
	{
		if (control_wall_y(pos, new_player_y) == 0)
			pos->player.pos.y = new_player_y;
	}
}
