/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:44:13 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/24 17:08:03 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	vertical_intersection(t_game *pos, t_rays *rays)
{	//con esto encontramos la primera colision vertical
	rays->xintercep = floor(pos->player.pos.x / pos->tile.size) * pos->tile.size;
	rays->xintercep += rays->israyfacingright ? pos->tile.size : 0;
	rays->yintercep = pos->player.pos.y + (rays->xintercep - pos->player.pos.x) * tan(rays->rayangle);
	rays->xstep = pos->tile.size;
	rays->xstep *= rays->israyfacingleft ? -1 : 1;
	rays->ystep = pos->tile.size * tan(rays->rayangle);
	rays->ystep *= (rays->israyfacingup && rays->ystep > 0) ? -1 : 1;
	rays->ystep *= (rays->israyfacingdown && rays->ystep < 0) ? -1 : 1;
	rays->nextverttouchy = rays->yintercep;
	rays->nextverttouchx = rays->xintercep;
	while (rays->nextverttouchx >= 0 && rays->nextverttouchx <= pos->winres.window_width &&
	rays->nextverttouchy >= 0 && rays->nextverttouchy <= pos->winres.window_height)
	{
		rays->xtocheck = rays->nextverttouchx + (rays->israyfacingleft ? -1 : 0);
		rays->ytocheck = rays->nextverttouchy;
		if (wall_colision(pos, rays->ytocheck, rays->xtocheck))
		{
			rays->vertwallhitx = rays->nextverttouchx;
			rays->vertwallhity = rays->nextverttouchy;
			rays->vertwallcontent = (int)(pos->map[(int)floor(rays->ytocheck / pos->tile.size)][(int)floor(rays->xtocheck / pos->tile.size)]);
			rays->foundvertwallhit = TRUE;
			break;
		}
		else
		{
			rays->nextverttouchx += rays->xstep;
			rays->nextverttouchy += rays->ystep;
		}
		
	}
}

void	horizontal_intersection(t_game *pos, t_rays *rays)
{	//con esto encontramos la primera colision horizontal
	rays->yintercep = floor(pos->player.pos.y / pos->tile.size) * pos->tile.size;
	rays->yintercep += rays->israyfacingdown ? pos->tile.size : 0;
	rays->xintercep = pos->player.pos.x + (rays->yintercep - pos->player.pos.y) / tan(rays->rayangle);
	rays->ystep = pos->tile.size;
	rays->ystep *= rays->israyfacingup ? -1 : 1;
	rays->xstep = pos->tile.size / tan(rays->rayangle);
	rays->xstep *= (rays->israyfacingleft && rays->xstep > 0) ? -1 : 1;
	rays->xstep *= (rays->israyfacingright && rays->xstep < 0) ? -1 : 1;
	rays->nexthoriztouchy = rays->yintercep;
	rays->nexthoriztouchx = rays->xintercep;
	while (rays->nexthoriztouchx >= 0 && rays->nexthoriztouchx <= pos->winres.window_width &&
	rays->nexthoriztouchy >= 0 && rays->nexthoriztouchy <= pos->winres.window_height)
	{
		rays->xtocheck = rays->nexthoriztouchx;
		rays->ytocheck = rays->nexthoriztouchy + (rays->israyfacingup ? -1 : 0);
		if (wall_colision(pos, rays->ytocheck, rays->xtocheck))
		{
			rays->horizwallhitx = rays->nexthoriztouchx;
			rays->horizwallhity = rays->nexthoriztouchy;
			rays->horizwallcontent = (int)(pos->map[(int)floor(rays->ytocheck / pos->tile.size)][(int)floor(rays->xtocheck / pos->tile.size)]);
			rays->foundhorizwallhit = TRUE;
			break;
		}
		else
		{
			rays->horizwallhitx += rays->xstep;
			rays->horizwallhity += rays->ystep;
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

void	castray(t_game *pos, t_rays *rays)
{
	//aqui todos los datos de las coliciones horizontales y verticales
	rays->rayangle = normalizeangle(pos->ray.rayangle);
	rays->israyfacingdown = rays->rayangle > 0 && rays->rayangle < PI;
	rays->israyfacingup = !rays->israyfacingdown;
	rays->israyfacingright = rays->rayangle < PI * 0.5 || rays->rayangle > PI * 1.5;
	rays->israyfacingleft = !rays->israyfacingright;
	horizontal_intersection(pos, rays);
	vertical_intersection(pos, rays);
	pos->ray.horizhitdistance = rays->foundhorizwallhit ? distancebetweenpoints(pos->player.pos.x,
	pos->player.pos.y, rays->horizwallhitx, rays->horizwallhity) : 2147483647;
	pos->ray.verthitdistance = rays->foundvertwallhit ? distancebetweenpoints(pos->player.pos.x,
	pos->player.pos.y, rays->vertwallhitx, rays->vertwallhity) : 2147483647;
	if (pos->ray.verthitdistance < pos->ray.horizhitdistance)
	{
		rays->distance = pos->ray.verthitdistance;
		rays->wallhitX = rays->vertwallhitx;
		rays->wallhitY = rays->vertwallhity;
		rays->wallhitcontent = rays->vertwallcontent;
		rays->washitvertical = TRUE;
	}
	else
	{
		rays->distance = pos->ray.horizhitdistance;
		rays->wallhitX = rays->horizwallhitx;
		rays->wallhitY = rays->horizwallhity;
		rays->wallhitcontent = rays->horizwallcontent;
		rays->washitvertical = FALSE;
	}
	rays->rayangle = pos->ray.rayangle;
	
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
		castray(pos, &pos->rays[id]);
		pos->ray.rayangle += pos->player.FOV_angle / pos->player.num_rays;
		id++;
	}
}	