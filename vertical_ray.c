/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 11:53:58 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/22 01:31:54 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

 void	vertical_collisionA(t_game *pos, float rayangle) //revisar el error aqui
 {
	if (rayangle > PI / 2 && rayangle < PI * 1.5)
		pos->ray_col.vert_pointA.x = ((int)(pos->player.x / pos->tile.size) *
		pos->tile.size) - 1;
	else
		pos->ray_col.vert_pointA.x = ((int)(pos->player.x / pos->tile.size) *
		pos->tile.size) + pos->tile.size;
    if (rayangle > PI && rayangle < PI * 1.5)
        pos->ray_col.vert_pointA.y = pos->player.y - (pos->player.x - pos->ray_col.vert_pointA.x) *
        tan(rayangle);
    else
        pos->ray_col.vert_pointA.y = pos->ray_col.vert_pointA.y + (pos->ray_col.vert_pointA.x - pos->player.x) *
        tan(rayangle);
    pos->ray_col.vertNextCol.x = pos->ray_col.vert_pointA.x;
    if (pos->ray_col.vert_pointA.y > 0)
        pos->ray_col.vertNextCol.y = pos->ray_col.vert_pointA.y;
    else
    {
        pos->ray_col.vert_pointA.y *=  -1;
        pos->ray_col.vertNextCol.y = pos->ray_col.vert_pointA.y - pos->tile.size;
    }
    
}

void    vertical_collision_next(t_game *pos, float rayangle)
{
    while (wall_colision(pos, pos->ray_col.vertNextCol.y, pos->ray_col.vertNextCol.x) == 0)
    {
        pos->ray_col.vertNextCol.x += pos->ray.vert_distA_NEXT.x;
        if (rayangle > PI)
            pos->ray_col.vertNextCol.y -= pos->ray.vert_distA_NEXT.y;
        else
            pos->ray_col.vertNextCol.y -= pos->ray.vert_distA_NEXT.y;
    }
}
