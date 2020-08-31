/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:44:13 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/31 13:26:21 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	horizontal_ray(t_game *pos)
{
	pos->ray.foundHorzWallHit = FALSE;

	pos->ray.yintercep = floor(pos->player.y / pos->tile.size) * pos->tile.size;
	pos->ray.yintercep += pos->ray.isRayFacingDown ? pos->tile.size ; 0;

	pos->ray.xintercep = pos->player.x +
	(pos->ray.yintercep - pos->player.y) /
	tan(pos->ray.rayAngle);
	
}
float	normalizer(float angle)
{
	float twoPI;

	twoPI = 2 * PI;
	angle = remainder(angle, twoPI);
	if (angle < 0)
		angle = twoPI + angle;
	return (angle);
}

void	castRay(t_game *pos, int stripid)
{
	pos->ray.rayAngle = normalizer(pos->ray.rayAngle);
	pos->ray.isRayFacingDown = pos->ray.rayAngle > 0 &&
	pos->ray.rayAngle < PI;
	pos->ray.isRayFacingUp = !pos->ray.isRayFacingDown;
	pos->ray.isRayFacingRight = pos->ray.rayAngle < 0.5 * PI &&
	pos->ray.rayAngle > 1.5 * PI;
	pos->ray.isRayFacingLeft = !pos->ray.isRayFacingRight;

	horizontal_ray(pos);
}

void	cast_all_rays(t_game *pos)
{
	int stripid;
	
	stripid = 0;
	pos->cast.num_rays = pos->winres.x;
	pos->ray.rayAngle = pos->move.rotationangle - (pos->cast.fov_angle / 2);
	while (stripid < pos->cast.num_rays)
	{
		castRay(pos, stripid);
		pos->ray.rayAngle += pos->cast.fov_angle / pos->cast.num_rays;
		stripid++;
	}
}