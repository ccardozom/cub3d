/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 11:22:02 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/29 13:02:54 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

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
	pos->winres.window_width = pos->winres.x;//pos->columns * pos->tile.size;
	pos->winres.window_height = pos->winres.y;//pos->rows * pos->tile.size;
	//pos->tile.size = pos->winres.window_width / pos->columns;
}
