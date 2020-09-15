/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:54:35 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/15 15:06:43 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void	draw_player_move(t_game *pos)
{
	float	x;
	float	y;

printf("\nposicion player (%f, %f)\n", pos->player.y, pos->player.x);

	y = pos->player.y;
	x = pos->player.x;

	int i;
	i = 0;
	
	while (i < 50)
	{
		printf("%f %f ",x + cos(pos->move.player_angle) * i,y + sin(pos->move.player_angle) * i);
		my_mlx_pixel_put(&pos->img, x + cos(pos->move.player_angle) * i,
		y + sin(pos->move.player_angle) * i, 0xFCE904);
		i++;
	}
}