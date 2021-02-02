/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 09:57:34 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/27 14:22:54 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int		control_wall_y(t_game *pos, int new_pos)
{
	int position_x;
	int position_y;

	position_x = floor(pos->player.pos.x / pos->tile.size);
	position_y = floor(new_pos / pos->tile.size);
	if (position_x < 0 || position_x > pos->columns || position_y < 0 ||
		position_y > pos->rows)
		return (1);
	else if (pos->map[position_y][position_x] == '1')
		return (1);
	return (0);
}

int		control_wall_x(t_game *pos, float new_pos)
{
	int position_x;
	int position_y;

	position_x = floor(new_pos / pos->tile.size);
	position_y = floor(pos->player.pos.y / pos->tile.size);
	if (position_x < 0 || position_x > pos->columns || position_y < 0 ||
		position_y > pos->rows)
		return (1);
	else if (pos->map[position_y][position_x] == '1')
		return (1);
	return (0);
}

void	move_front_back(t_game *pos, t_new *new)
{
	new->move_step = pos->player.walk * pos->player.movespeed;
	new->new_player_x = pos->player.pos.x +
	cos(pos->player.player_angle) * new->move_step;
	new->new_player_y = pos->player.pos.y +
	sin(pos->player.player_angle) * new->move_step;
}

void	move_left_right(t_game *pos, t_new *new)
{
	new->move_l_r = pos->player.l_r * pos->player.movespeed;
	new->new_player_x += pos->player.player_angle > PI * 0.5 &&
	pos->player.player_angle < PI * 1.5 ? new->move_l_r *
	cos(pos->player.player_angle - PI * 0.5) : 0;
	new->new_player_y += pos->player.player_angle > PI * 0.5 &&
	pos->player.player_angle < PI * 1.5 ? sin(pos->player.player_angle -
	PI * 0.5) * new->move_l_r : 0;
	new->new_player_x += ((pos->player.player_angle > 0 &&
	pos->player.player_angle < PI * 0.5) || (pos->player.player_angle >
	PI * 1.5 && pos->player.player_angle < PI * 2)) ? new->move_l_r *
	cos(pos->player.player_angle - PI * 0.5) : 0;
	new->new_player_y += ((pos->player.player_angle > 0 &&
	pos->player.player_angle < PI * 0.5) || (pos->player.player_angle >
	PI * 1.5 && pos->player.player_angle < PI * 2)) ? new->move_l_r *
	sin(pos->player.player_angle - PI * 0.5) : 0;
}

void	update_player(t_game *pos)
{
	t_new new;

	new.new_player_x = 0;
	new.new_player_y = 0;
	pos->player.player_angle += pos->player.turn * pos->player.rotationspeed;
	pos->player.player_angle = normalizeangle(pos->player.player_angle);
	move_front_back(pos, &new);
	move_left_right(pos, &new);
	if (new.new_player_x)
	{
		if (control_wall_x(pos, new.new_player_x) == 0)
			pos->player.pos.x = new.new_player_x;
	}
	if (new.new_player_y)
	{
		if (control_wall_y(pos, new.new_player_y) == 0)
			pos->player.pos.y = new.new_player_y;
	}
	pos->first_frame = 1;
}
