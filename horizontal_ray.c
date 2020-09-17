/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 11:51:30 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/08 09:54:11 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

 int	find_wall_horiz(t_game *pos, float y, float x)
 {
     y = (int)(y / pos->tile.size);
     x = (int)(x / pos->tile.size);
     if (pos->map[y][x] == '1')
        return (TRUE);
     return (FALSE)
 }

 int	horizontal_collisionA(t_game *pos, float rayangle)
 {
	pos->ray.horiz_raydir = FALSE;
	if (rayangle < PI)
		pos->ray.horiz_raydir = TRUE;
	if (pos->ray.horiz_raydir == TRUE)
		pos->ray_col.horiz_pointA.y = (int)(pos->player.y / pos->tile.size) *
		pos->tile.size - 1;
	else
		pos->ray_col.horiz_pointA.y = (int)(pos->player.y / pos->tile.size) *
		pos->tile.size + pos->tile.size;
    pos->ray_col.horiz_pointA.x = pos->player.x + (pos->player.y - pos->ray_col.horiz_pointA.y) /
    tan(rayangle);
    pos->ray_col.horizNextCol.x = pos->ray_col.horiz_pointA.x;
    pos->ray_col.horizNextCol.y = pos->ray_col.horiz_pointA.y;
    if (find_wall_horiz(pos, pos->ray_col.horiz_pointA.y,  pos->ray_col.horiz_pointA.x))
        return (TRUE);
    return (FALSE);
}

int    horizontal_collision_next(t_game *pos, float rayangle)
{
    pos->ray_col.horizNextCol += pos->ray.horiz_distA_NEXT.x;
    pos->ray_col.horizNextCol.y += pos->ray.horiz_distA_NEXT.y;
    if (find_wall_horiz(pos,  pos->ray_col.horizNextCol.y,   pos->ray_col.horizNextCol.x))
        return (TRUE);
    return (FALSE);
}