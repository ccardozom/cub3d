/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:44:13 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/07 13:47:00 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

float	normalizer(float angle)
{
	float two_PI = 2 * PI;
	angle = remainder(angle, two_PI);
	if (angle < 0)
		return (two_PI + angle);
	return (angle);
}

void	castRay(float rayangle, int stripid, void *ray_cast, t_game *pos)
{
	t_rays ray;
	
	rayangle = normalizer(rayangle);
	ray.isRayFacingDown = rayangle > 0 && rayangle < PI;
	ray.isRayFacingUp = !ray.isRayFacingDown;
	ray.isRayFacingRight = rayangle < 0.5 * PI || rayangle > 1.5 * PI;
	ray.isRayFacingLeft = !ray.isRayFacingRight;
	pos->rayB.yintercep = floor(pos->player.y / pos->tile.size) * pos->tile.size;
	pos->rayB.yintercep += ray.isRayFacingDown ? pos->tile.size : 0;
	pos->rayB.xintercep = pos->player.x + (pos->rayB.yintercep - pos->player.y) / tan(rayangle);
	pos->rayB.ystep = pos->tile.size;
	pos->rayB.ystep *= ray.isRayFacingUp ? -1 : 1;
	pos->rayB.xstep = pos->tile.size / tan(rayangle);
	pos->rayB.xstep *= (ray.isRayFacingLeft && pos->rayB.xstep > 0) ? -1 : 1;
	pos->rayB.xstep *= (ray.isRayFacingRight && pos->rayB.xstep < 0) ? -1 : 1;
	pos->rayB.nextHorizTouchX = pos->rayB.xintercep;
	pos->rayB.nextHorizTouchY = pos->rayB.yintercep;
	while (pos->rayB.nextHorizTouchX >= 0 && pos->rayB.nextHorizTouchX <= pos->winres.x &&
	pos->rayB.nextHorizTouchY >= 0 && pos->rayB.nextHorizTouchY <= pos->winres.y)
	{
		pos->rayB.xTocheck = pos->rayB.nextHorizTouchX;
		pos->rayB.yTocheck = pos->rayB.nextHorizTouchY * (ray.isRayFacingUp ? -1 : 0);
		if (mapHasWall(pos, pos->rayB.xTocheck, pos->rayB.yTocheck))
		{
			pos->rayB.horzWallhitx = pos->rayB.nextHorizTouchX;
			pos->rayB.horzWallhity = pos->rayB.nextHorizTouchY;
			pos->rayB.horzWallcontent = ft_atoi(&pos->map[(int)floor(pos->rayB.yTocheck /
			pos->tile.size)][(int)floor(pos->rayB.xTocheck /
			pos->tile.size)]);
			printf("%d ", pos->rayB.horzWallcontent);
			pos->rayB.foundHorzWallHit = TRUE;
		}
		else
		{
			pos->rayB.nextHorizTouchX += pos->rayB.xstep;
			pos->rayB.nextHorizTouchY += pos->rayB.ystep;
		}
	}
	ray_cast[stripid] = ray;   //verificar desde aqui ....?????????????????????????????
}
void	cast_all_rays(t_game *pos)
{
	void *ray_cast;
	float	rayangle;
	int		stripid;
	
	ray_cast = malloc(sizeof(t_rays) * pos->winres.x);
	rayangle = pos->move.player_angle - (pos->cast.player_visualangle / 2);
	stripid = 0;
	while (stripid < pos->winres.x)
	{
		casRay(rayangle, stripid, &ray_cast, pos);
		stripid++;
	}
}