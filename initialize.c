/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 11:22:02 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/21 16:19:10 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	screen(t_game *pos)
{
	int sizex;
	int sizey;
	
	sizex = 2560;
	sizey = 1395;
	pos->winres.x = pos->winres.x > sizex ? sizex : pos->winres.x;
	pos->winres.y = pos->winres.y > sizey ? sizey : pos->winres.y;
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
