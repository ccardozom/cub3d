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

 void	vertical_collisionA(t_game *pos, float rayangle)
 {
	if (rayangle > PI)
		pos->ray_col.vert_pointA.y = (int)(pos->player.y / pos->tile.size) *
		pos->tile.size - 1;
	else
		pos->ray_col.vert_pointA.y = (int)(pos->player.y / pos->tile.size) *
		pos->tile.size + pos->tile.size;
    pos->ray_col.vert_pointA.x = pos->player.x + (pos->player.y - pos->ray_col.vert_pointA.y) /
    tan(rayangle);
    pos->ray_col.vertNextCol.x = pos->ray_col.vert_pointA.x;
    pos->ray_col.vertNextCol.y = pos->ray_col.vert_pointA.y;
}

void    vertical_collision_next(t_game *pos, float rayangle)
{
    while (wall_colision(pos, pos->ray_col.vertNextCol.y, pos->ray_col.vertNextCol.x) == 0)
    {
        pos->ray_col.vertNextCol.x += pos->ray.vert_distA_NEXT.x;
        pos->ray_col.vertNextCol.y += pos->ray.vert_distA_NEXT.y;
    }
}
