/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 10:46:16 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/23 11:40:45 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	reset_position(t_pos_py *pos, t_tile *tile)
{
	pos->dir_x = 0;
	pos->dir_y = 0;
	pos->pos_x = 0;
	pos->pos_y = 0;
	pos->plane_x = 0;
	pos->plane_y = 0;
	pos->map_c = 0;
	pos->map_f = 0;
	pos->map = NULL;
	pos->matriz_c = 0;
	pos->matriz_f = 0;
	tile->x = 0;
	tile->y = 0;
	tile->pos_x = 0;
	tile->pos_y = 0;
	tile->pos_sy = 0;
}
