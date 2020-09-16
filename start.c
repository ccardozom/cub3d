/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 11:13:36 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/08 12:43:33 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	data(t_game *pos)
{
	float	x;
	float	y;

	x = pos->winres.window_width / 2;
	y = pos->winres.window_height / 2;
	pos->ray.distance = x / tan(pos->cast.FOV_angle / 2);
	pos->cast.num_rays = pos->winres.window_width / pos->cast.FOV_angle;
	pos->proyection_center.x = x;
	pos->proyection_center.y = y;
	pos->ray.rayAngle = pos->cast.FOV_angle / pos->cast.num_rays;
}

void	start(t_game *pos)
{	
	pos->mlx = mlx_init();
	pos->mlx_win = mlx_new_window(pos->mlx, pos->winres.window_width, pos->winres.window_height, "Cub3D");
	pos->img.img = mlx_new_image(pos->mlx, pos->winres.window_width, pos->winres.window_height);
	pos->img.addr = mlx_get_data_addr(pos->img.img,
	&pos->img.bits_per_pixel,
	&pos->img.line_length,
	&pos->img.endian);
	draw_player(pos);
	mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->img.img, 0, 0);
}