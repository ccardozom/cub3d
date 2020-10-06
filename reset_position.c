/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 10:46:16 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/06 14:07:14 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	reset_pos_move(t_game *pos)
{
	pos->player.turn = 0;
	pos->player.walk = 0;
	pos->player.player_angle = 0;
	pos->player.movespeed = 1.5;
	pos->player.rotationspeed = 10 * (PI / 180);
}

void	reset_rays_data(t_game *pos)
{
	pos->rays.xintercep = 0;
	pos->rays.yintercep = 0;
	pos->rays.xstep = 0;
	pos->rays.ystep = 0;
	pos->rays.horizwallhitx = 0;
	pos->rays.horizwallhity = 0;
	pos->rays.nexthoriztouchx = 0;
	pos->rays.nexthoriztouchy = 0;
	pos->rays.xtocheck = 0;
	pos->rays.ytocheck = 0;
	pos->rays.idcolumns = 0;
	pos->rays.foundhorizwallhit = 0;
	pos->rays.horizwallcontent = 0;
	pos->rays.foundvertwallhit = 0;
	pos->rays.vertwallhitx = 0;
	pos->rays.vertwallhity = 0;
	pos->rays.vertwallcontent = 0;
	pos->rays.nextverttouchx = 0;
	pos->rays.nextverttouchy = 0;
}

void	reset_cast(t_game *pos)
{
	pos->player.FOV_angle = 66 * (PI / 180);
	pos->player.num_rays = 0;
	pos->player.player_control = 0;
	pos->player.minimapscale = 0.2;
	pos->rays.foundhorizwallhit = FALSE;
	pos->rays.foundvertwallhit = FALSE;
	pos->rays.horizwallhitx = 0;
	pos->rays.horizwallhity = 0;
	pos->rays.horizwallcontent = 0;
	pos->rays.vertwallhitx = 0;
	pos->rays.vertwallhity = 0;
	pos->rays.vertwallcontent = 0;
	pos->ray_data->israyfacingup = 0;
	pos->ray_data->israyfacingdown = 0;
	pos->ray_data->israyfacingleft = 0;
	pos->ray_data->israyfacingright = 0;
}

void	reset_position(t_game *pos)
{
	//reset_rays_data(pos);
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
