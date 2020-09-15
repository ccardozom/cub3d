/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 11:22:02 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/08 12:50:38 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	initialize(t_game *pos)
{
	read_map(pos);
	create_map(pos);
	//wall_control(pos.map, pos.rows, pos.columns);
	pos->tile.size = pos->winres.x / pos->columns;
	pos->winres.window_width = pos->columns * pos->tile.size;
	pos->winres.window_height = pos->rows * pos->tile.size;
}
