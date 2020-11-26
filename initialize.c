/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 11:22:02 by ccardozo          #+#    #+#             */
/*   Updated: 2020/11/26 12:04:33 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	initialize(t_game *pos, char **argv)
{
	read_map(pos, argv);
	create_map(pos, argv);
	if (pos->rows < 4 && pos->columns < 4)
		return_error (12);
	pos->winres.window_width = pos->columns * pos->tile.size;
	pos->winres.window_height = pos->rows * pos->tile.size;
	if (pos->winres.window_width == 2560 || pos->winres.window_height == 1395)
	{
		pos->player.movespeed = 12;
		pos->player.rotationspeed = 6 * (PI / 180);
	}
	else if ((pos->winres.window_width > 1000 || pos->winres.window_width < 2560) && (pos->winres.window_height > 1000 || pos->winres.window_height < 1395))
	{
		pos->player.movespeed = 8;
		pos->player.rotationspeed = 4 * (PI / 180);
	}
}
