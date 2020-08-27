/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 10:46:16 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/27 12:01:00 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	reset_pos_move(t_game *pos)
{
	pos->move.left = 0;
	pos->move.rigth = 0;
	pos->move.up = 0;
	pos->move.down = 0;
	pos->move.rotationangle = PI / 2;
	pos->move.movespeed = 3.0;
	pos->move.rotationspeed = 3 * (PI / 180);
}

void	reset_position(t_game *pos)
{
	reset_pos_move(pos);
	pos->dir.x = 0;
	pos->dir.y = 0;
	pos->player.x = 0;
	pos->player.y = 0;
	pos->winres.x = 0;
	pos->winres.y = 0;
	pos->columns = 0;
	pos->rows = 0;
	pos->map = NULL;
	pos->matriz.x = 0;
	pos->matriz.y = 0;
	pos->mlx_win = 0;
	pos->mlx = 0;
}
