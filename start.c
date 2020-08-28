/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 11:13:36 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/27 11:27:27 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	start(t_game *pos)
{	
	pos->mlx = mlx_init();
	pos->mlx_win = mlx_new_window(pos->mlx, pos->winres.x, (pos->winres.x/pos->columns)*pos->rows, "Cub3D");
	pos->img.img = mlx_new_image(pos->mlx, pos->winres.x, (pos->winres.x/pos->columns)*pos->rows);
	pos->img.addr = mlx_get_data_addr(pos->img.img,
	&pos->img.bits_per_pixel,
	&pos->img.line_length,
	&pos->img.endian);
	draw_player(pos);
	mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->img.img, 0, 0);
}