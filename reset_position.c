/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 10:46:16 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/03 09:44:13 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	reset_pos_move(t_game *pos)
{
	pos->player.turn = 0;
	pos->player.walk = 0;
	pos->player.player_angle = 0;
	pos->player.movespeed = 2;
	pos->player.rotationspeed = 1.5 * (PI / 180);
	pos->texture.north_text.path = NULL;
	pos->texture.south_text.path = NULL;
	pos->texture.weast_text.path = NULL;
	pos->texture.east_text.path = NULL;
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
	pos->ray_data->israyfacingup = 0;
	pos->ray_data->israyfacingdown = 0;
	pos->ray_data->israyfacingleft = 0;
	pos->ray_data->israyfacingright = 0;
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
	pos->player.textureoffsetx = 0;
	pos->player.textureoffsety = 0;
}

void	reset_sprites(t_game *pos)
{
	pos->sprites->distance = 0.0;
	pos->sprites->visible = 0;
	pos->sprites->vectx = 0;
	pos->sprites->vecty = 0;
	pos->sprites->spriteangulo = 0;
	pos->sprites->spr_top = 0;
	pos->sprites->spr_bottom = 0;
	pos->sprites->x = 0;
	pos->sprites->spr_height = 0;
}

void	reset_position(t_game *pos)
{
	reset_pos_move(pos);
	reset_cast(pos);
	pos->first_frame = 0;
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
	pos->tile.size = 64;
	pos->spritecount = 0;
	pos->spritecount_aux = 0;
	pos->control_map = 0;
	pos->pos_id_spr = 0;
	pos->line_count1 = 0;
	pos->line_count2 = 0;
	pos->checkplayer = 0;
}
