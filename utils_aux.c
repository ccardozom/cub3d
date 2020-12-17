/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:14:24 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/17 11:14:13 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	normalizeresolution(t_game *pos)
{
	pos->winres.window_width = pos->rows*pos->tile.size;//pos->winres.x;
	pos->winres.window_height = pos->rows*pos->tile.size;//pos->winres.y;
	/*if (pos->winres.window_width < 200 || pos->winres.window_height < 200)
	{
		pos->winres.window_width = 680;
		pos->winres.window_height = 460;
		pos->player.movespeed = 12;
		pos->player.rotationspeed = 6 * (PI / 180);
	}
	if (pos->winres.window_width >= 2560 || pos->winres.window_height >= 1395)
	{
		pos->winres.window_width = 2560;
		pos->winres.window_height = 1395;
	}*/
}
