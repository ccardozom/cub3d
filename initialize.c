/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 11:22:02 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/27 14:21:10 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	screen(t_game *pos)
{
	float max_sizex;
	float max_sizey;

	max_sizex = 2560;
	max_sizey = 1395;
	pos->player.movespeed = (pos->winres.x / pos->winres.y) * 1.5;
	pos->player.rotationspeed = pos->player.movespeed * (PI / 180);
	if (pos->winres.x > max_sizex || pos->winres.y > max_sizey)
	{
		pos->winres.x = max_sizex;
		pos->winres.y = max_sizey;
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
}
