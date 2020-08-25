/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:54:35 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/25 10:44:48 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void	draw_player_move(t_game *pos)
{
	float	x;
	float	y;
	float cont;

printf("posicion player (%f, %f)\n", pos->player.x, pos->player.y);

	y = pos->player.y;
	cont = 12;	
	while (y < pos->player.y + cont)
	{
		x = pos->player.x;
		while ( x < pos->player.x + cont)
		{
			my_mlx_pixel_put(&pos->img, x, y, 0xBBCC00);
			x++;
		}
		y++;
	}
}