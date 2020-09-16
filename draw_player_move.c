/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:54:35 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/10 17:30:55 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		wall_distance(t_game *pos, float init_ray)
{
	int distance;
	distance = cast_all_rays(pos, init_ray);
	return (distance);

}	
void	draw_player_move(t_game *pos)
{
	float	x;
	float	y;

printf("\nposicion player (%f, %f)\n", pos->player.y, pos->player.x);

	y = pos->player.y;
	x = pos->player.x;
	float	ini_ray;
	float	end_ray;


	int i;
	i = 0;
	ini_ray = pos->move.player_angle - (pos->cast.FOV_angle / 2);
	end_ray = pos->move.player_angle + (pos->cast.FOV_angle / 2);
	while (ini_ray < end_ray)
	{
		while (i < wall_distance(pos, ini_ray))
		{
			my_mlx_pixel_put(&pos->img, x + cos(ini_ray) * i,
			y + sin(ini_ray) * i, 0xFCE904);
			i++;
		}
		ini_ray += 0.1;
	}
}