/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 11:13:36 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/28 16:25:16 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	start(t_game *pos)
{	
	float	x;
	float	y;
	
	x = pos->winres.window_width / 2;
	y = pos->winres.window_height / 2;
	pos->player.num_rays = pos->columns * pos->tile.size;
	pos->proyection_center.x = x;
	pos->proyection_center.y = y;
	pos->mlx = mlx_init();
	pos->mlx_win = mlx_new_window(pos->mlx, pos->winres.window_width, pos->winres.window_height, "Cub3D");
	pos->img.img = mlx_new_image(pos->mlx, pos->winres.window_width * pos->player.minimapscale, pos->winres.window_height * pos->player.minimapscale);
	pos->img.addr = mlx_get_data_addr(pos->img.img,
	&pos->img.bits_per_pixel,
	&pos->img.line_length,
	&pos->img.endian);
	draw_player(pos);
	mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->img.img, 0, 0);
}