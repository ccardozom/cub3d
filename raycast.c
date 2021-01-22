/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:44:13 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/21 17:12:12 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	vertical_intersection(t_game *pos, t_ray *ray_data)
{
	pos->rays.xintercep = (int)(pos->player.pos.x /
	pos->tile.size) * pos->tile.size;
	pos->rays.xintercep += ray_data->israyfacingright ?
	pos->tile.size : 0;
	pos->rays.yintercep = pos->player.pos.y + (pos->rays.xintercep -
	pos->player.pos.x) * tan(pos->rays.rayangle);
	pos->rays.xstep = pos->tile.size;
	pos->rays.xstep *= ray_data->israyfacingleft ? -1 : 1;
	pos->rays.ystep = pos->tile.size * tan(pos->rays.rayangle);
	pos->rays.ystep *= (ray_data->israyfacingup &&
	pos->rays.ystep > 0) ? -1 : 1;
	pos->rays.ystep *= (ray_data->israyfacingdown &&
	pos->rays.ystep < 0) ? -1 : 1;
	pos->rays.nextverttouchy = pos->rays.yintercep;
	pos->rays.nextverttouchx = pos->rays.xintercep;
	while ((int)(pos->rays.nextverttouchx / pos->tile.size) >= 0 && (int)(pos->rays.nextverttouchx / pos->tile.size) <
	pos->columns &&
	(int)(pos->rays.nextverttouchy / pos->tile.size) >= 0 && (int)(pos->rays.nextverttouchy / pos->tile.size) <
	pos->rows)
	{
		if (wall_colision_search_ver(pos, ray_data))
			break ;
	}
}

void	horizontal_intersection(t_game *pos, t_ray *ray_data)
{
	pos->rays.yintercep = (int)(pos->player.pos.y /
	pos->tile.size) * pos->tile.size;
	pos->rays.yintercep += ray_data->israyfacingdown ?
	pos->tile.size : 0;
	pos->rays.xintercep = pos->player.pos.x +
	(pos->rays.yintercep - pos->player.pos.y) / tan(pos->rays.rayangle);
	pos->rays.ystep = pos->tile.size;
	pos->rays.ystep *= ray_data->israyfacingup ? -1 : 1;
	pos->rays.xstep = pos->tile.size / tan(pos->rays.rayangle);
	pos->rays.xstep *= (ray_data->israyfacingleft &&
	pos->rays.xstep > 0) ? -1 : 1;
	pos->rays.xstep *= (ray_data->israyfacingright &&
	pos->rays.xstep < 0) ? -1 : 1;
	pos->rays.nexthoriztouchy = pos->rays.yintercep;
	pos->rays.nexthoriztouchx = pos->rays.xintercep;
	while ((int)(pos->rays.nexthoriztouchx / pos->tile.size) >= 0 &&
	(int)(pos->rays.nexthoriztouchx / pos->tile.size) < pos->columns &&
	(int)(pos->rays.nexthoriztouchy / pos->tile.size) >= 0 &&
	(int)(pos->rays.nexthoriztouchy / pos->tile.size) < pos->rows)
	{
		if (wall_colision_search_hor(pos, ray_data))
			break ;
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
	ray_data->israyfacingdown = pos->rays.rayangle > 0 &&
	pos->rays.rayangle < PI;
	ray_data->israyfacingup = !ray_data->israyfacingdown;
	ray_data->israyfacingright = pos->rays.rayangle < PI * 0.5 ||
	pos->rays.rayangle > PI * 1.5;
	ray_data->israyfacingleft = !ray_data->israyfacingright;
	horizontal_intersection(pos, ray_data);
	vertical_intersection(pos, ray_data);
	pos->rays.horizhitdistance = pos->rays.foundhorizwallhit ?
	distancebetweenpoints(pos->player.pos.x,
	pos->player.pos.y, pos->rays.horizwallhitx,
	pos->rays.horizwallhity) : 2147483647;
	pos->rays.verthitdistance = pos->rays.foundvertwallhit ?
	distancebetweenpoints(pos->player.pos.x,
	pos->player.pos.y, pos->rays.vertwallhitx,
	pos->rays.vertwallhity) : 2147483647;
	dir_colision(pos, ray_data);
	ray_data->ray_angle = pos->rays.rayangle;
}

void	cast_all_rays(t_game *pos)
{
	int id;

	pos->rays.rayangle = 0;
	if (!(pos->ray_data = (t_ray *)malloc((sizeof(t_ray) *
	pos->player.num_rays) + 1)))
		return_error(4);
	ft_memset(pos->ray_data, 0, sizeof(t_ray));
	pos->rays.rayangle = pos->player.player_angle - (pos->player.v_angle / 2);
	pos->rays.rayangle = normalizeangle(pos->rays.rayangle);
	id = 0;
	while (id < pos->player.num_rays)
	{
		reset_rays_data(pos);
		castray(pos, &pos->ray_data[id]);
		pos->rays.rayangle += pos->player.v_angle / pos->player.num_rays;
		id++;
	}
}
