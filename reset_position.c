/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 10:46:16 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/14 12:36:21 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void reset_position(t_pos_py *pos)
{
	pos->dir_x = 0;
	pos->dir_y = 0;
	pos->pos_x = 0;
	pos->pos_y = 0;
	pos->plane_x = 0;
	pos->plane_y = 0;
	pos->map_c = 0;
	pos->map_f = 0;
	
}