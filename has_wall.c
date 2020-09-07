/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:23:32 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/07 13:28:06 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		mapHasWall(t_game *pos, float x,float y)
{
	int mapGridIndexX;
	int mapGridIndexY;

	mapGridIndexX = (int)floor(x / pos->tile.size);
	mapGridIndexY = (int)floor(y / pos->tile.size);
	if (x < 0 || x > pos->winres.x || y < 0 || y > pos->winres.y)
		return (FALSE);
	//printf("%f %f %d %d ",y,x,mapGridIndexY,mapGridIndexX);
	return (pos->map[mapGridIndexY][mapGridIndexX] != 0);
}
