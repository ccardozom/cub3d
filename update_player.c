/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 09:57:34 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/04 10:02:09 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		control_wall_y(t_game *pos, int new_pos)
{
	int position_x;
	int position_y;

	position_x = (int)(pos->player.x / pos->tile.size);
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
	position_y = (int)(pos->player.y / pos->tile.size);
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
	pos->move.player_angle += pos->move.turn * pos->move.rotationspeed;
	move_step = pos->move.walk * pos->move.movespeed;
	new_player_x = pos->player.x + cos(pos->move.player_angle) * move_step;
	new_player_y = pos->player.y + sin(pos->move.player_angle) * move_step;
	if (new_player_x)
	{
		if (control_wall_x(pos, new_player_x) == 0)
			pos->player.x = new_player_x;
	}
	if (new_player_y)
	{
		if (control_wall_y(pos, new_player_y) == 0)
			pos->player.y = new_player_y;
	}
}
