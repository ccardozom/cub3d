/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:44:13 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/06 14:00:16 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	vertical_intersection(t_game *pos, t_ray *ray_data)
{	
	pos->rays.xintercep = (int)(pos->player.pos.x / pos->tile.size) * pos->tile.size;
	pos->rays.xintercep += ray_data->israyfacingright ? pos->tile.size : 0;
	pos->rays.yintercep = pos->player.pos.y + (pos->rays.xintercep - pos->player.pos.x) * tan(pos->rays.rayangle);
	pos->rays.xstep = pos->tile.size;
	pos->rays.xstep *= ray_data->israyfacingleft ? -1 : 1;
	pos->rays.ystep = pos->tile.size * tan(pos->rays.rayangle);
	pos->rays.ystep *= (ray_data->israyfacingup && pos->rays.ystep > 0) ? -1 : 1;
	pos->rays.ystep *= (ray_data->israyfacingdown && pos->rays.ystep < 0) ? -1 : 1;
	pos->rays.nextverttouchy = pos->rays.yintercep;
	pos->rays.nextverttouchx = pos->rays.xintercep;
	while (pos->rays.nextverttouchx >= 0 && pos->rays.nextverttouchx <= pos->winres.window_width &&
	pos->rays.nextverttouchy >= 0 && pos->rays.nextverttouchy <= pos->winres.window_height)
	{
		pos->rays.xtocheck = pos->rays.nextverttouchx + (ray_data->israyfacingleft ? -1 : 0);
		pos->rays.ytocheck = pos->rays.nextverttouchy;
		if (wall_colision(pos, pos->rays.ytocheck, pos->rays.xtocheck))
		{
			pos->rays.vertwallhitx = pos->rays.nextverttouchx;
			pos->rays.vertwallhity = pos->rays.nextverttouchy;
			pos->rays.vertwallcontent = pos->map[(int)(pos->rays.ytocheck / pos->tile.size)][(int)(pos->rays.xtocheck / pos->tile.size)];
			pos->rays.foundvertwallhit = TRUE;
			break;
		}
		else
		{
			pos->rays.nextverttouchx += pos->rays.xstep;
			pos->rays.nextverttouchy += pos->rays.ystep;
			pos->rays.foundvertwallhit = FALSE;
		}
		
	}
}

void	horizontal_intersection(t_game *pos, t_ray *ray_data)
{	
	pos->rays.yintercep = (int)(pos->player.pos.y / pos->tile.size) * pos->tile.size;
	pos->rays.yintercep += ray_data->israyfacingdown ? pos->tile.size : 0;
	pos->rays.xintercep = pos->player.pos.x + (pos->rays.yintercep - pos->player.pos.y) / tan(pos->rays.rayangle);
	pos->rays.ystep = pos->tile.size;
	pos->rays.ystep *= ray_data->israyfacingup ? -1 : 1;
	pos->rays.xstep = pos->tile.size / tan(pos->rays.rayangle);
	pos->rays.xstep *= (ray_data->israyfacingleft && pos->rays.xstep > 0) ? -1 : 1;
	pos->rays.xstep *= (ray_data->israyfacingright && pos->rays.xstep < 0) ? -1 : 1;
	pos->rays.nexthoriztouchy = pos->rays.yintercep;
	pos->rays.nexthoriztouchx = pos->rays.xintercep;
	while (pos->rays.nexthoriztouchx >= 0 && pos->rays.nexthoriztouchx <= pos->winres.window_width &&
	pos->rays.nexthoriztouchy >= 0 && pos->rays.nexthoriztouchy <= pos->winres.window_height)
	{
		pos->rays.xtocheck = pos->rays.nexthoriztouchx;
		pos->rays.ytocheck = pos->rays.nexthoriztouchy + (ray_data->israyfacingup ? -1 : 0);
		if (wall_colision(pos, pos->rays.ytocheck, pos->rays.xtocheck))
		{
			pos->rays.horizwallhitx = pos->rays.nexthoriztouchx;
			pos->rays.horizwallhity = pos->rays.nexthoriztouchy;
			pos->rays.horizwallcontent = pos->map[(int)(pos->rays.ytocheck / pos->tile.size)][(int)(pos->rays.xtocheck / pos->tile.size)];
			pos->rays.foundhorizwallhit = TRUE;
			break;
		}
		else
		{
			pos->rays.nexthoriztouchx += pos->rays.xstep;
			pos->rays.nexthoriztouchy += pos->rays.ystep;
			pos->rays.foundhorizwallhit = FALSE;
		}
		
	}
}

float	normalizeangle(float angle)
{
	if (angle >= 360 * (M_PI / 180))
        angle = angle - (2 * M_PI);
    if (angle < 0)
        angle = (2 * M_PI) + angle;
	return (angle);
}

void	castray(t_game *pos, t_ray *ray_data)
{
	pos->rays.rayangle = normalizeangle(pos->rays.rayangle);
	pos->rays.rayangle = pos->rays.rayangle;
	ray_data->israyfacingdown = pos->rays.rayangle > 0 && pos->rays.rayangle < PI;
	ray_data->israyfacingup = !ray_data->israyfacingdown;
	ray_data->israyfacingright = pos->rays.rayangle < PI * 0.5 || pos->rays.rayangle > PI * 1.5;
	ray_data->israyfacingleft = !ray_data->israyfacingright;
	horizontal_intersection(pos, ray_data);
	vertical_intersection(pos, ray_data);
	pos->rays.horizhitdistance = pos->rays.foundhorizwallhit ? distancebetweenpoints(pos->player.pos.x,
	pos->player.pos.y, pos->rays.horizwallhitx, pos->rays.horizwallhity) : 2147483647;
	pos->rays.verthitdistance = pos->rays.foundvertwallhit ? distancebetweenpoints(pos->player.pos.x,
	pos->player.pos.y, pos->rays.vertwallhitx, pos->rays.vertwallhity) : 2147483647;
	if (pos->rays.verthitdistance < pos->rays.horizhitdistance)
	{
		ray_data->distance = pos->rays.verthitdistance;
		ray_data->wallhitX = pos->rays.vertwallhitx;
		ray_data->wallhitY = pos->rays.vertwallhity;
		ray_data->wallhitcontent = pos->rays.vertwallcontent;
		ray_data->washitvertical = TRUE;
	}
	else
	{
		ray_data->distance = pos->rays.horizhitdistance;
		ray_data->wallhitX = pos->rays.horizwallhitx;
		ray_data->wallhitY = pos->rays.horizwallhity;
		ray_data->wallhitcontent = pos->rays.horizwallcontent;
		ray_data->washitvertical = FALSE;
	}
	ray_data->ray_angle = pos->rays.rayangle;
	
}

void	cast_all_rays(t_game *pos)
{	
	int id;

	if(!(pos->ray_data = (t_ray *)malloc(sizeof(t_ray) * pos->player.num_rays)))
		return_error(-1);
	pos->rays.rayangle = pos->player.player_angle - (pos->player.FOV_angle / 2);
	pos->rays.rayangle = normalizeangle(pos->rays.rayangle);
	printf("%f\n",pos->rays.rayangle);
	id = 0;
	while (id < pos->player.num_rays)
	{
		reset_rays_data(pos);
		castray(pos, &pos->ray_data[id]);
		pos->rays.rayangle += pos->player.FOV_angle / pos->player.num_rays;
		id++;
	}
}	