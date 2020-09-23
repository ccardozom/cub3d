/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:44:13 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/23 21:13:56 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	vertical_intersection(t_game *pos, int id)
{	//con esto encontramos la primera colision vertical
	pos->rays[id].xintercep = floor(pos->player.pos.x / pos->tile.size) * pos->tile.size;
	pos->rays[id].xintercep += pos->rays[id].israyfacingright ? pos->tile.size : 0;
	pos->rays[id].yintercep = pos->player.pos.y + (pos->rays[id].xintercep - pos->player.pos.x) / tan(pos->rays[id].rayangle);
	pos->rays[id].xstep = pos->tile.size;
	pos->rays[id].xstep *= pos->rays[id].israyfacingleft ? -1 : 1;
	pos->rays[id].ystep = pos->tile.size / tan(pos->rays[id].rayangle);
	pos->rays[id].ystep *= (pos->rays[id].israyfacingup && pos->rays[id].xstep > 0) ? -1 : 1;
	pos->rays[id].ystep *= (pos->rays[id].israyfacingdown && pos->rays[id].xstep < 0) ? -1 : 1;
	pos->rays[id].nextverttouchy = pos->rays[id].yintercep;
	pos->rays[id].nextverttouchx = pos->rays[id].xintercep;
	while (pos->rays[id].nextverttouchx >= 0 && pos->rays[id].nextverttouchx <= pos->winres.window_width &&
	pos->rays[id].nextverttouchy >= 0 && pos->rays[id].nextverttouchy <= pos->winres.window_height)
	{
		pos->rays[id].xtocheck = pos->rays[id].nextverttouchx + (pos->rays[id].israyfacingleft ? -1 : 0);
		pos->rays[id].ytocheck = pos->rays[id].nexthoriztouchy;
		if (wall_colision(pos, pos->rays[id].ytocheck, pos->rays[id].xtocheck))
		{
			pos->rays[id].vertwallhitx = pos->rays[id].nextverttouchx;
			pos->rays[id].vertwallhity = pos->rays[id].nextverttouchy;
			pos->rays[id].vertwallcontent = (int)(pos->map[(int)floor(pos->rays[id].ytocheck / pos->tile.size)][(int)floor(pos->rays[id].xtocheck / pos->tile.size)]);
			pos->rays[id].foundvertwallhit = TRUE;
			break;
		}
		else
		{
			pos->rays[id].vertwallhitx += pos->rays[id].xstep;
			pos->rays[id].vertwallhity += pos->rays[id].ystep;
		}
		
	}
}

void	horizontal_intersection(t_game *pos, int id)
{	//con esto encontramos la primera colision horizontal
	pos->rays[id].yintercep = floor(pos->player.pos.y / pos->tile.size) * pos->tile.size;
	pos->rays[id].yintercep += pos->rays[id].israyfacingdown ? pos->tile.size : 0;
	pos->rays[id].xintercep = pos->player.pos.x + (pos->rays[id].yintercep - pos->player.pos.y) / tan(pos->rays[id].rayangle);
	pos->rays[id].ystep = pos->tile.size;
	pos->rays[id].ystep *= pos->rays[id].israyfacingup ? -1 : 1;
	pos->rays[id].xstep = pos->tile.size / tan(pos->rays[id].rayangle);
	pos->rays[id].xstep *= (pos->rays[id].israyfacingleft && pos->rays[id].xstep > 0) ? -1 : 1;
	pos->rays[id].xstep *= (pos->rays[id].israyfacingright && pos->rays[id].xstep < 0) ? -1 : 1;
	pos->rays[id].nexthoriztouchy = pos->rays[id].yintercep;
	pos->rays[id].nexthoriztouchx = pos->rays[id].xintercep;
	while (pos->rays[id].nexthoriztouchx >= 0 && pos->rays[id].nexthoriztouchx <= pos->winres.window_width &&
	pos->rays[id].nexthoriztouchy >= 0 && pos->rays[id].nexthoriztouchy <= pos->winres.window_height)
	{
		pos->rays[id].xtocheck = pos->rays[id].nexthoriztouchx;
		pos->rays[id].ytocheck = pos->rays[id].nexthoriztouchy + (pos->rays[id].israyfacingup ? -1 : 0);
		if (wall_colision(pos, pos->rays[id].ytocheck, pos->rays[id].xtocheck))
		{
			pos->rays[id].horizwallhitx = pos->rays[id].nexthoriztouchx;
			pos->rays[id].horizwallhity = pos->rays[id].nexthoriztouchy;
			pos->rays[id].horizwallcontent = (int)(pos->map[(int)floor(pos->rays[id].ytocheck / pos->tile.size)][(int)floor(pos->rays[id].xtocheck / pos->tile.size)]);
			pos->rays[id].foundhorizwallhit = TRUE;
			break;
		}
		else
		{
			pos->rays[id].horizwallhitx += pos->rays[id].xstep;
			pos->rays[id].horizwallhity += pos->rays[id].ystep;
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

void	castray(t_game *pos, int id)
{
	//aqui todos los datos de las coliciones horizontales y verticales
	pos->rays[id].rayangle = normalizeangle(pos->ray.rayangle);
	pos->rays[id].israyfacingdown = pos->rays[id].rayangle > 0 && pos->rays[id].rayangle < PI;
	pos->rays[id].israyfacingup = !pos->rays[id].israyfacingdown;
	pos->rays[id].israyfacingright = pos->rays[id].rayangle < PI * 0.5 || pos->rays[id].rayangle > PI * 1.5;
	pos->rays[id].israyfacingleft = !pos->rays[id].israyfacingright;
	horizontal_intersection(pos, id);
	vertical_intersection(pos, id);
	
}

void	cast_all_rays(t_game *pos)
{	
	int id;
	if(!(pos->rays = (t_rays *)malloc(sizeof(t_rays) * pos->player.num_rays)))
		return_error(-1);
	pos->ray.rayangle = pos->player.player_angle - (pos->player.FOV_angle / 2);
	id = 0;
	while (id < pos->player.num_rays)
	{
		castray(pos, id);
		pos->ray.rayangle += pos->player.FOV_angle / pos->player.num_rays;
		id++;
	}
}	