/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 11:51:30 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/04 12:34:12 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	find_wall_horiz(t_game *pos)
{
	while (pos->ray.nextHorizTouchX >= 0 && pos->ray.nextHorizTouchX <= pos->winres.x &&
	pos->ray.nextHorizTouchY >= 0 && pos->ray.nextHorizTouchY <= pos->winres.y)
	{
		pos->ray.xTocheck = pos->ray.nextHorizTouchX;
		pos->ray.yTocheck = pos->ray.nextHorizTouchY + (pos->ray.isRayFacingUp ? -1 : 0);
		if (mapHasWall(pos, pos->ray.xTocheck,pos->ray.yTocheck))
		{
			pos->ray.horzWallhitx = pos->ray.nextHorizTouchX;
			pos->ray.horzWallhity = pos->ray.nextHorizTouchY;
			pos->ray.horzWallcontent = pos->map[(int)floor(pos->ray.yTocheck / pos->tile.size)][(int)floor(pos->ray.yTocheck / pos->tile.size)];
			pos->ray.foundHorzWallHit = TRUE;
			break;
		}
		else
		{
			pos->ray.nextHorizTouchX += pos->ray.xstep;
			pos->ray.nextHorizTouchY += pos->ray.ystep;
		}
	}
	
}

void	horizontal_ray(t_game *pos, float rayangle)
{
	pos->ray.foundHorzWallHit = FALSE;
	pos->ray.horzWallcontent = 0;
	pos->ray.horzWallhitx = 0;
	pos->ray.horzWallhity = 0;
	pos->ray.yintercep = floor(pos->player.y / pos->tile.size) * pos->tile.size;
	pos->ray.yintercep += pos->ray.isRayFacingDown ? pos->tile.size : 0;
	pos->ray.xintercep = pos->player.x + (pos->ray.yintercep - pos->player.y) / tan(rayangle);
	pos->ray.ystep = pos->tile.size;
	pos->ray.ystep *= pos->ray.isRayFacingUp ? -1 : 1;
	pos->ray.xstep = pos->tile.size / tan(rayangle);
	pos->ray.xstep *= (pos->ray.isRayFacingLeft && pos->ray.xstep > 0) ? -1 : 1;
	pos->ray.xstep *= (pos->ray.isRayFacingRight && pos->ray.xstep < 0) ? -1 : 1;
	pos->ray.nextHorizTouchX = pos->ray.xintercep;
	pos->ray.nextHorizTouchY = pos->ray.yintercep;
	find_wall_horiz(pos);
}