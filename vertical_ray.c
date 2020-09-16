/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 11:53:58 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/08 09:54:29 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

 int	find_wall_vert(t_game *pos, float y, float x)
 {
     y = (int)(y / pos->tile.size);
     x = (int)(x / pos->tile.size);
     if (pos->map[y][x] == '1')
        return (TRUE);
     return (FALSE)
 }

 int	vertical_collisionA(t_game *pos, float rayangle)
 {
	pos->ray.vert_raydir = FALSE;
	if (rayangle < PI)
		pos->ray.vert_raydir = TRUE;
	if (pos->ray.vert_raydir == TRUE)
		pos->ray_col.vert_pointA.y = (int)(pos->player.y / pos->tile.size) *
		pos->tile.size - 1;
	else
		pos->ray_col.vert_pointA.y = (int)(pos->player.y / pos->tile.size) *
		pos->tile.size + pos->tile.size;
    pos->ray_col.vert_pointA.x = pos->player.x + (pos->player.y - pos->ray_col.vert_pointA.y) /
    tan(rayangle);
    pos->ray_col.vertNextCol.x = pos->ray_col.vert_pointA.x;
    pos->ray_col.vertNextCol.y = pos->ray_col.vert_pointA.y;
    if (find_wall_vert(pos, pos->ray_col.vert_pointA.y,  pos->ray_col.vert_pointA.x))
        return (TRUE);
    return (FALSE);
}

int    vertontal_collision_next(t_game *pos, float rayangle)
{
    pos->ray_col.vertNextCol.x += pos->ray.vert_distA_NEXT.x;
    pos->ray_col.vertNextCol.y += pos->ray.vert_distA_NEXT.y;
    if (find_wall_vert(pos,  pos->ray_col.vertNextCol.y,   pos->ray_col.vertNextCol.x))
        return (TRUE);
    return (FALSE);
}