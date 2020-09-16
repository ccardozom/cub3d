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

void	horizontal_collision(t_game *pos, float init_ray)
{
	if (horizontal_collisionA(pos,init_ray) == TRUE)
		;
	else
	{
		pos->ray.horiz_distA_NEXT.y = (pos->ray.horiz_raydir ==
		TRUE ? pos->tile.size * -1 : pos->tile.size);
    	pos->ray.horiz_distA_NEXT.x = pos->tile.size / tan(init_ray);
		while (!horizontal_collision_next(pos,init_ray))
	}
}

void	vertical_collision(t_game *pos, float init_ray)
{
	if (vertical_collisionA(pos,init_ray) == TRUE)
		;
	else
	{
		pos->ray.vert_distA_NEXT.y = (pos->ray.horiz_raydir ==
		TRUE ? pos->tile.size * -1 : pos->tile.size);
    	pos->ray.horiz_distA_NEXT.x = pos->tile.size / tan(init_ray);
		while (!horizontal_collision_next(pos,init_ray))
	}
}

void	cast_all_rays(t_game *pos, float init_ray)
{
	init_ray = normalizer(init_ray);
	horizontal_collision(pos,init_ray);
	vertical_collision(pos, init_ray);
}