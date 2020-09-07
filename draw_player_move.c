/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:54:35 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/07 10:48:56 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void	draw_player_move(t_game *pos)
{
	float	x;
	float	y;

printf("posicion player (%f, %f)\n", pos->player.x, pos->player.y);

	y = pos->player.y;
	x = pos->player.x;

	int i;
	i = 0;
	while (i < 50)
	{
		my_mlx_pixel_put(&pos->img, x + cos(pos->move.player_angle) * i,
		y + sin(pos->move.player_angle) * i, 0xF1ED08);
		i++;
	}
}