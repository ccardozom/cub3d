/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:44:13 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/04 13:04:43 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	castRay(t_game *pos, float rayangle)
{
	float	two_PI;
	float	angle;
	
	two_PI = PI * 2;
	angle = remainder(rayangle, two_PI);
	if (angle < 0)
		angle = two_PI + angle;
	rayangle = angle;
	pos->ray.isRayFacingDown = rayangle > 0 && rayangle < PI;
	pos->ray.isRayFacingUp = !pos->ray.isRayFacingDown;
	pos->ray.isRayFacingRight = rayangle * 0.5 || rayangle > 1.5 * PI;
	pos->ray.isRayFacingLeft = !pos->ray.isRayFacingRight;

	horizontal_ray(pos, rayangle);
	vertical_ray(pos, rayangle);
}
void	cast_all_rays(t_game *pos)
{
	float	rayangle;
	int		ray_id;
	
	ray_id = 0;
	rayangle = pos->move.player_angle - (pos->cast.fov_angle / 2);
	pos->cast.num_rays = pos->winres.x;
	while (ray_id < pos->cast.num_rays)
	{
		castRay(pos, rayangle);
		rayangle += pos->cast.fov_angle / pos->cast.num_rays;
		ray_id++;
	}
}