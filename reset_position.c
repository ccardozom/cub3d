/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 10:46:16 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/10 17:05:47 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	reset_pos_move(t_game *pos)
{
	pos->move.turn = 0;
	pos->move.walk = 0;
	pos->move.player_angle = 0;
	pos->move.movespeed = 1.0;
	pos->move.rotationspeed = 1 * (PI / 180);
}

void	reset_control(t_game *pos)
{
	pos->control.ok_player = 0;
	pos->control.player_count = 0;
	pos->control.check_resolution = 0;
}

void	reset_cast(t_game *pos)
{
	pos->cast.player_visualangle = 60 * (PI / 180);
	pos->cast.num_rays = 0;
	pos->cast.idcolumns = 0;
	pos->rayB.foundHorzWallHit = FALSE;
	pos->rayB.horzWallhitx = 0;
	pos->rayB.horzWallhity = 0;
	pos->rayB.horzWallcontent = 0;
}

void	reset_position(t_game *pos)
{
	reset_pos_move(pos);
	reset_control(pos);
	reset_cast(pos);
	pos->dir.x = 0;
	pos->dir.y = 0;
	pos->player.x = 0;
	pos->player.y = 0;
	pos->winres.x = 0;
	pos->winres.y = 0;
	pos->columns = 0;
	pos->rows = 0;
	pos->map = NULL;
	pos->matriz.x = 0;
	pos->matriz.y = 0;
	pos->mlx_win = 0;
	pos->mlx = 0;
}
