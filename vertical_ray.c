/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 11:53:58 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/04 13:05:50 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	find_wall_vert(t_game *pos)
{
	while (pos->ray.nextVertTouchX >= 0 && pos->ray.nextVertTouchX <= pos->winres.x &&
	pos->ray.nextVertTouchY >= 0 && pos->ray.nextVertTouchY <= pos->winres.y)
	{
		pos->ray.xTocheck = pos->ray.nextVertTouchX + (pos->ray.isRayFacingLeft ? -1 : 0);
		pos->ray.yTocheck = pos->ray.nextVertTouchY;
		if (mapHasWall(pos, pos->ray.xTocheck,pos->ray.yTocheck))
		{
			pos->ray.vertWallhitx = pos->ray.nextVertTouchX;
			pos->ray.vertWallhity = pos->ray.nextVertTouchY;
			pos->ray.vertWallcontent = pos->map[(int)floor(pos->ray.yTocheck / pos->tile.size)][(int)floor(pos->ray.yTocheck / pos->tile.size)];
			pos->ray.foundvertWallHit = TRUE;
			break;
		}
		else
		{
			pos->ray.nextVertTouchX += pos->ray.xstep;
			pos->ray.nextVertTouchY += pos->ray.ystep;
		}
	}
	
}

void	vertical_ray(t_game *pos, float rayangle)
{
	pos->ray.foundvertWallHit = FALSE;
	pos->ray.vertWallcontent = 0;
	pos->ray.vertWallhitx = 0;
	pos->ray.vertWallhity = 0;
	pos->ray.xintercep = floor(pos->player.x / pos->tile.size) * pos->tile.size;
	pos->ray.yintercep += pos->ray.isRayFacingRight ? pos->tile.size : 0;
	pos->ray.yintercep = pos->player.y + (pos->ray.xintercep - pos->player.x) / tan(rayangle);
	pos->ray.xstep = pos->tile.size;
	pos->ray.xstep *= pos->ray.isRayFacingLeft ? -1 : 1;
	pos->ray.ystep = pos->tile.size / tan(rayangle);
	pos->ray.ystep *= (pos->ray.isRayFacingUp && pos->ray.xstep > 0) ? -1 : 1;
	pos->ray.ystep *= (pos->ray.isRayFacingDown && pos->ray.xstep < 0) ? -1 : 1;
	pos->ray.nextVertTouchX = pos->ray.xintercep;
	pos->ray.nextVertTouchY = pos->ray.yintercep;
	find_wall_vert(pos);
}