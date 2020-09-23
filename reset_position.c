/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 10:46:16 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/23 20:36:38 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	reset_pos_move(t_game *pos)
{
	pos->player.turn = 0;
	pos->player.walk = 0;
	pos->player.player_angle = 0;
	pos->player.movespeed = 1.5;
	pos->player.rotationspeed = 2 * (PI / 180);
}

void	reset_cast(t_game *pos)
{
	pos->player.FOV_angle = 66 * (PI / 180);
	pos->player.num_rays = 0;
	pos->rays[id].foundhorizwallhit = FALSE;
	pos->rays[id].foundvertwallhit = FALSE;
	pos->rays[id].horizwallhitx = 0;
	pos->rays[id].horizwallhity = 0;
	pos->rays[id].horizwallcontent = 0;
	pos->rays[id].vertwallhitx = 0;
	pos->rays[id].vertwallhity = 0;
	pos->rays[id].vertwallcontent = 0;
}

void	reset_position(t_game *pos)
{
	reset_pos_move(pos);
	reset_cast(pos);
	pos->dir.x = 0;
	pos->dir.y = 0;
	pos->player.pos.x = 0;
	pos->player.pos.y = 0;
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
