/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:23:32 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/25 11:21:19 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int		wall_colision(t_game *pos, float y, float x)
{
	int		coly;
	int		colx;

	coly = (int)y / (int)pos->tile.size;
	colx = (int)x / (int)pos->tile.size;
	if (pos->map[coly][colx] == '1')
		return (1);
	return (0);
}
