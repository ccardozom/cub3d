/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:44:13 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/22 15:48:08 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	vertical_intersection(t_game *pos)
{	//con esto encontramos la primera colision vertical
	pos->rays->xintercep = floor(pos->player.pos.x / pos->tile.size) * pos->tile.size;
	pos->rays->xintercep += pos->rays->israyfacingright ? pos->tile.size : 0;
	pos->rays->yintercep = pos->player.pos.y + (pos->rays->xintercep - pos->player.pos.x) / tan(pos->rays->rayangle);
	pos->rays->xstep = pos->tile.size;
	pos->rays->xstep *= pos->rays->israyfacingleft ? -1 : 1;
	pos->rays->ystep = pos->tile.size / tan(pos->rays->rayangle);
	pos->rays->ystep *= (pos->rays->israyfacingup && pos->rays->xstep > 0) ? -1 : 1;
	pos->rays->ystep *= (pos->rays->israyfacingdown && pos->rays->xstep < 0) ? -1 : 1;
	pos->rays->nextverttouchy = pos->rays->yintercep;
	pos->rays->nextverttouchx = pos->rays->xintercep;
	while (pos->rays->nextverttouchx >= 0 && pos->rays->nextverttouchx <= pos->winres.window_width &&
	pos->rays->nextverttouchy >= 0 && pos->rays->nextverttouchy <= pos->winres.window_height)
	{
		pos->rays->xtocheck = pos->rays->nextverttouchx + (pos->rays->israyfacingleft ? -1 : 0);
		pos->rays->ytocheck = pos->rays->nexthoriztouchy;
		if (wall_colision(pos, pos->rays->ytocheck, pos->rays->xtocheck))
		{
			pos->rays->vertwallhitx = pos->rays->nextverttouchx;
			pos->rays->vertwallhity = pos->rays->nextverttouchy;
			pos->rays->vertwallcontent = (int)(pos->map[(int)floor(pos->rays->ytocheck / pos->tile.size)][(int)floor(pos->rays->xtocheck / pos->tile.size)]);
			pos->rays->foundvertwallhit = TRUE;
			break;
		}
		else
		{
			pos->rays->vertwallhitx += pos->rays->xstep;
			pos->rays->vertwallhity += pos->rays->ystep;
		}
		
	}
}

void	horizontal_intersection(t_game *pos)
{	//con esto encontramos la primera colision horizontal
	pos->rays->yintercep = floor(pos->player.pos.y / pos->tile.size) * pos->tile.size;
	pos->rays->yintercep += pos->rays->israyfacingdown ? pos->tile.size : 0;
	pos->rays->xintercep = pos->player.pos.x + (pos->rays->yintercep - pos->player.pos.y) / tan(pos->rays->rayangle);
	pos->rays->ystep = pos->tile.size;
	pos->rays->ystep *= pos->rays->israyfacingup ? -1 : 1;
	pos->rays->xstep = pos->tile.size / tan(pos->rays->rayangle);
	pos->rays->xstep *= (pos->rays->israyfacingleft && pos->rays->xstep > 0) ? -1 : 1;
	pos->rays->xstep *= (pos->rays->israyfacingright && pos->rays->xstep < 0) ? -1 : 1;
	pos->rays->nexthoriztouchy = pos->rays->yintercep;
	pos->rays->nexthoriztouchx = pos->rays->xintercep;
	while (pos->rays->nexthoriztouchx >= 0 && pos->rays->nexthoriztouchx <= pos->winres.window_width &&
	pos->rays->nexthoriztouchy >= 0 && pos->rays->nexthoriztouchy <= pos->winres.window_height)
	{
		pos->rays->xtocheck = pos->rays->nexthoriztouchx;
		pos->rays->ytocheck = pos->rays->nexthoriztouchy + (pos->rays->israyfacingup ? -1 : 0);
		if (wall_colision(pos, pos->rays->ytocheck, pos->rays->xtocheck))
		{
			pos->rays->horizwallhitx = pos->rays->nexthoriztouchx;
			pos->rays->horizwallhity = pos->rays->nexthoriztouchy;
			pos->rays->horizwallcontent = (int)(pos->map[(int)floor(pos->rays->ytocheck / pos->tile.size)][(int)floor(pos->rays->xtocheck / pos->tile.size)]);
			pos->rays->foundhorizwallhit = TRUE;
			break;
		}
		else
		{
			pos->rays->horizwallhitx += pos->rays->xstep;
			pos->rays->horizwallhity += pos->rays->ystep;
		}
		
	}
}

float	normalizeangle(float angle)
{
	angle = remainder(angle, PI * 2);
	if (angle < 0)
		angle = PI * 2 + angle;
	return (angle);
}

void	castray(t_game *pos)
{
	//aqui todos los datos de las coliciones horizontales y verticales
	pos->rays->rayangle = normalizeangle(pos->ray.rayangle);
	pos->rays->israyfacingdown = pos->rays->rayangle > 0 && pos->rays->rayangle < PI;
	pos->rays->israyfacingup = !pos->rays->israyfacingdown;
	pos->rays->israyfacingright = pos->rays->rayangle < PI * 0.5 || pos->rays->rayangle > PI * 1.5;
	pos->rays->israyfacingleft = !pos->rays->israyfacingright;
	horizontal_intersection(pos);
	vertical_intersection(pos);
	
}

void	cast_all_rays(t_game *pos)
{
	if(!(pos->rays = (t_rays *)malloc(sizeof(t_rays) * pos->player.num_rays)))
		return_error(-1);
	pos->ray.rayangle = pos->player.player_angle - (pos->player.FOV_angle / 2);
	pos->rays->idcolumns = 0;
	while (pos->rays->idcolumns < pos->player.num_rays)
	{
		castray(pos);
		pos->ray.rayangle += pos->player.FOV_angle / pos->player.num_rays;
		pos->rays->idcolumns++;
	}
}	