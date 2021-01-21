/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 11:22:02 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/12 23:02:07 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	screen(t_game *pos)
{
	int sizex;
	int sizey;
	
	sizex = 2560;
	sizey = 1395;
	if ((pos->winres.x < sizex && pos->winres.y >= sizey) ||
	(pos->winres.x > sizex && pos->winres.y < sizey) ||
	(pos->winres.x > sizex && pos->winres.y > sizey))
	{
		pos->winres.window_h = sizey;
		pos->winres.window_w = sizex;
	}
	else if (pos->winres.x < pos->tile.size * pos->columns || pos->winres.y < pos->tile.size * pos->rows)
	{
		pos->winres.window_w = pos->tile.size * pos->columns;
		pos->winres.window_h = pos->tile.size * pos->rows;
	}
	else
	{
		pos->winres.window_w = pos->winres.x;
		pos->winres.window_h = pos->winres.y;
	}
}

void	map_controll(t_game *pos)
{
	if (checker(pos->checking) && pos->rows < 4 && pos->columns < 4)
		return_error(12);
	if (!checker(pos->checking))
		return_error(11);
	if (!wall_control(pos->map, pos->rows, pos->columns))
		return_error(12);
	if (pos->checkplayer != 1)
		return_error(12);
}

void	initialize(t_game *pos, char **argv)
{
	read_map(pos, argv);
	create_map(pos, argv);
	map_controll(pos);
	screen(pos);
}
