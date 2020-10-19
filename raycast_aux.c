/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 21:44:38 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/23 21:44:38 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

float   distancebetweenpoints(float x1, float y1, float x2, float y2)
{
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int		wall_colision_search_hor(t_game *pos, t_ray *ray_data)
{
	pos->rays.xtocheck = pos->rays.nexthoriztouchx;
	pos->rays.ytocheck = pos->rays.nexthoriztouchy + (ray_data->israyfacingup ? -1 : 0);
	if (wall_colision(pos, pos->rays.ytocheck, pos->rays.xtocheck))
	{
		pos->rays.horizwallhitx = pos->rays.nexthoriztouchx;
		pos->rays.horizwallhity = pos->rays.nexthoriztouchy;
		pos->rays.horizwallcontent = pos->map[(int)(pos->rays.ytocheck / pos->tile.size)][(int)(pos->rays.xtocheck / pos->tile.size)];
		pos->rays.foundhorizwallhit = TRUE;
		return (1);
	}
	else
	{
		pos->rays.nexthoriztouchx += pos->rays.xstep;
		pos->rays.nexthoriztouchy += pos->rays.ystep;
		pos->rays.foundhorizwallhit = FALSE;
	}
	return (0);
}

int		wall_colision_search_ver(t_game *pos, t_ray *ray_data)
{
	pos->rays.xtocheck = pos->rays.nextverttouchx + (ray_data->israyfacingleft ? -1 : 0);
	pos->rays.ytocheck = pos->rays.nextverttouchy;
	if (wall_colision(pos, pos->rays.ytocheck, pos->rays.xtocheck))
	{
		pos->rays.vertwallhitx = pos->rays.nextverttouchx;
		pos->rays.vertwallhity = pos->rays.nextverttouchy;
		pos->rays.vertwallcontent = pos->map[(int)(pos->rays.ytocheck / pos->tile.size)][(int)(pos->rays.xtocheck / pos->tile.size)];
		pos->rays.foundvertwallhit = TRUE;
		return (1);
	}
	else
	{
		pos->rays.nextverttouchx += pos->rays.xstep;
		pos->rays.nextverttouchy += pos->rays.ystep;
		pos->rays.foundvertwallhit = FALSE;
	}
	return (0);
}

void	dir_colision(t_game *pos, t_ray *ray_data)
{
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
}