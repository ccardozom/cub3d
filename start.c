/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 11:13:36 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/11 16:01:31 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	start(t_game *pos, char **argv)
{
	initialize(pos, argv);
	pos->player.num_rays = pos->winres.window_width;
	pos->mlx = mlx_init();
	pos->mlx_win = mlx_new_window(pos->mlx,
	pos->winres.window_width, pos->winres.window_height, "Cub3D");
	pos->img.img = mlx_new_image(pos->mlx,
	pos->winres.window_width, pos->winres.window_height);
	pos->img.addr = mlx_get_data_addr(pos->img.img,
	&pos->img.bits_per_pixel,
	&pos->img.line_length,
	&pos->img.endian);
	draw_player(pos);
	sprites(pos);
	mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->img.img, 0, 0);
}
