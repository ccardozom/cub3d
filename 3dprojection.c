/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3dprojection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:13:25 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/13 19:34:46 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	wall_position(t_game *pos, int i, int y)
{
	if (pos->ray_data[i].washitvertical == TRUE && pos->ray_data[i].israyfacingright)
		my_mlx_pixel_put(&pos->img, i, y, 0xFE2F02);
	if (pos->ray_data[i].washitvertical == TRUE && pos->ray_data[i].israyfacingleft)
		my_mlx_pixel_put(&pos->img, i, y, 0xAA10E8);
	if (pos->ray_data[i].washitvertical == FALSE && pos->ray_data[i].israyfacingdown)
		my_mlx_pixel_put(&pos->img, i, y, 0X85F94B);
	if (pos->ray_data[i].washitvertical == FALSE && pos->ray_data[i].israyfacingup)
	 	my_mlx_pixel_put(&pos->img, i, y, 0xF76CC9);
	
}

void	color_all_wall(t_game *pos, int i)
{
	int y;

	y = pos->player.walltoppixel;
	while (y < pos->player.wallbottompixel)
	{
		wall_position(pos, i, y);
		y++;
	}
}

void	projection_wall(t_game *pos, int x)
{
	pos->player.perpdistance = pos->ray_data[x].distance * cos(pos->ray_data[x].ray_angle - pos->player.player_angle);
		pos->player.distanceprojplane = (pos->winres.window_width / 2) / tan(pos->player.FOV_angle / 2);
		pos->player.projectedwallheight = (pos->tile.size / pos->player.perpdistance) * pos->player.distanceprojplane;
		pos->player.wallstripheight = (int)pos->player.projectedwallheight;
		pos->player.walltoppixel = (pos->winres.window_height / 2) - (pos->player.wallstripheight / 2);
		pos->player.walltoppixel = pos->player.walltoppixel < 0 ? 0 : pos->player.walltoppixel;
		pos->player.wallbottompixel = (pos->winres.window_height / 2) + (pos->player.wallstripheight / 2);
		pos->player.wallbottompixel = pos->player.wallbottompixel > pos->winres.window_height ? pos->winres.window_height : pos->player.wallbottompixel;
		color_all_wall(pos, x);
}

void	generate_3dprojection(t_game *pos)
{
	int i;

	if (!(pos->colorbuffer = (unsigned long *)malloc(sizeof(unsigned long) *
	(unsigned long)pos->winres.window_width * (unsigned long)pos->winres.window_height)))
			return_error();
	color_all_buffer(pos);
	i = 0;
	while (i < pos->player.num_rays)
	{
		projection_wall(pos, i);
		i++;
	}
}