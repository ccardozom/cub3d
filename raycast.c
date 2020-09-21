/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:44:13 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/22 00:21:09 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

float	distancebetweenpoints(float Ay, float Ax, float By, float Bx)
{
	return (sqrt((By - Ay) * (By - Ay) + (Bx - Ax) * (Bx - Ax)));
}

float	normalizer(float angle)
{
	float two_PI = 2 * PI;
	angle = remainder(angle, two_PI);
	if (angle < 0)
		return (two_PI + angle);
	return (angle);
}

void	horizontal_collision(t_game *pos, float init_ray)
{
	horizontal_collisionA(pos,init_ray);
	if (wall_colision(pos, pos->ray_col.horizNextCol.y, (int)pos->ray_col.horizNextCol.x) == 0)
	{
		if (init_ray > PI)
			pos->ray.horiz_distA_NEXT.y = pos->tile.size * -1;
		else
			pos->ray.horiz_distA_NEXT.y = pos->tile.size;
    	pos->ray.horiz_distA_NEXT.x = pos->tile.size / tan(init_ray);
	}
	//horizontal_collision_next(pos);
}

void	vertical_collision(t_game *pos, float init_ray) //todas las funciones verticales hay que revisarlas
{
	vertical_collisionA(pos,init_ray);
	if (wall_colision(pos, (int)pos->ray_col.vertNextCol.y, pos->ray_col.vertNextCol.x) == 0)
	{
		if (init_ray > PI / 2 && init_ray < PI * 1.5)
			pos->ray.vert_distA_NEXT.x = pos->tile.size * -1;
		else
			pos->ray.vert_distA_NEXT.x = pos->tile.size;
    	pos->ray.vert_distA_NEXT.y = pos->tile.size * tan(init_ray);
	}
	//vertical_collision_next(pos, init_ray);
}

float	cast_all_rays(t_game *pos, float init_ray)
{
	float distance;
	
	init_ray = normalizer(init_ray);
	horizontal_collision(pos,init_ray);
	vertical_collision(pos, init_ray);
	pos->ray_col.horizdistance = distancebetweenpoints(pos->player.y, pos->player.x, pos->ray_col.horizNextCol.y, pos->ray_col.horizNextCol.x);
	pos->ray_col.vertdistance = distancebetweenpoints(pos->player.y, pos->player.x, pos->ray_col.vertNextCol.y, pos->ray_col.vertNextCol.x);
	if (pos->ray_col.horizdistance > pos->ray_col.vertdistance)
		distance = pos->ray_col.vertdistance;
	else
		distance = pos->ray_col.horizdistance;
	return (distance);
}