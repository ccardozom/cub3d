/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:44:13 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/08 12:44:26 by ccardozo         ###   ########.fr       */
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

// t_rays	castRay(float rayangle, int stripid, rays *rays, t_game *pos)
// {	
// 	rayangle = normalizer(rayangle);
// 	rays[stripid]->isRayFacingDown = rayangle > 0 && rayangle < PI;
// 	rays->isRayFacingUp = !rays->isRayFacingDown;
// 	rays->isRayFacingRight = rayangle < 0.5 * PI || rayangle > 1.5 * PI;
// 	rays->isRayFacingLeft = !rays->isRayFacingRight;
// 	horizontal_ray(pos,rays);
// 	pos->rayB.yintercep = floor(pos->player.y / pos->tile.size) * pos->tile.size;
// 	pos->rayB.yintercep += rays->isRayFacingDown ? pos->tile.size : 0;
// 	pos->rayB.xintercep = pos->player.x + (pos->rayB.yintercep - pos->player.y) / tan(rayangle);
// 	pos->rayB.ystep = pos->tile.size;
// 	pos->rayB.ystep *= rays->isRayFacingUp ? -1 : 1;
// 	pos->rayB.xstep = pos->tile.size / tan(rayangle);
// 	pos->rayB.xstep *= (rays->isRayFacingLeft && pos->rayB.xstep > 0) ? -1 : 1;
// 	pos->rayB.xstep *= (rays->isRayFacingRight && pos->rayB.xstep < 0) ? -1 : 1;
// 	pos->rayB.nextHorizTouchX = pos->rayB.xintercep;
// 	pos->rayB.nextHorizTouchY = pos->rayB.yintercep;
// 	while (pos->rayB.nextHorizTouchX >= 0 && pos->rayB.nextHorizTouchX <= pos->winres.x &&
// 	pos->rayB.nextHorizTouchY >= 0 && pos->rayB.nextHorizTouchY <= pos->winres.y)
// 	{
// 		pos->rayB.xTocheck = pos->rayB.nextHorizTouchX;
// 		pos->rayB.yTocheck = pos->rayB.nextHorizTouchY * (rays->isRayFacingUp ? -1 : 0);
// 		if (mapHasWall(pos, pos->rayB.xTocheck, pos->rayB.yTocheck))
// 		{
// 			pos->rayB.horzWallhitx = pos->rayB.nextHorizTouchX;
// 			pos->rayB.horzWallhity = pos->rayB.nextHorizTouchY;
// 			pos->rayB.horzWallcontent = ft_atoi(&pos->map[(int)floor(pos->rayB.yTocheck /
// 			pos->tile.size)][(int)floor(pos->rayB.xTocheck /
// 			pos->tile.size)]);
// 			//printf("%d ", pos->rayB.horzWallcontent);
// 			pos->rayB.foundHorzWallHit = TRUE;
// 			break;
// 		}
// 		else
// 		{
// 			pos->rayB.nextHorizTouchX += pos->rayB.xstep;
// 			pos->rayB.nextHorizTouchY += pos->rayB.ystep;
// 		}
// 	}
// 	rays[stripid] = rays;
// }
void	cast_all_rays(t_game *pos)
{
	//typedef t_rays rays[(int)pos->winres.x];
	//rays	rays_cast;
	float	rayangle;
	int		stripid;
	 
	rayangle = pos->move.player_angle - (pos->cast.FOV_angle / 2);
	stripid = 0;
	while (stripid < pos->winres.x)
	{
		//castRay(rayangle, stripid, rays_cast, pos);
		stripid++;
	}
}