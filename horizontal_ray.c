/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 11:51:30 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/21 22:50:02 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	horizontal_collisionA(t_game *pos, float rayangle)
 {
	if (rayangle > PI)
		pos->ray_col.horiz_pointA.y = ((int)(pos->player.y / pos->tile.size) *
		pos->tile.size) - 1;
	else
		pos->ray_col.horiz_pointA.y = ((int)(pos->player.y / pos->tile.size) *
		pos->tile.size) + pos->tile.size;
   if (rayangle > PI / 2 && rayangle < PI * 1.5)
      pos->ray_col.horiz_pointA.x = pos->player.x - (pos->player.y - pos->ray_col.horiz_pointA.y) /
      tan(rayangle);
   else
      pos->ray_col.horiz_pointA.x = pos->player.x + (pos->player.y - pos->ray_col.horiz_pointA.y) /
      tan(rayangle);
    pos->ray_col.horizNextCol.x = pos->ray_col.horiz_pointA.x;
    pos->ray_col.horizNextCol.y = pos->ray_col.horiz_pointA.y;
}

void    horizontal_collision_next(t_game *pos)
{
   while (wall_colision(pos, pos->ray_col.horizNextCol.y, (int)pos->ray_col.horizNextCol.x / pos->tile.size) == 0)
   {
        pos->ray_col.horizNextCol.x += pos->ray.horiz_distA_NEXT.x;
        pos->ray_col.horizNextCol.y += pos->ray.horiz_distA_NEXT.y;
   }
}
