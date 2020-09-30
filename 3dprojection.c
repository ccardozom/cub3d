/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3dprojection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:13:25 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/30 13:56:33 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	wall_position(t_game *pos, int i)
{
	if (pos->ray_data[x].rayangle < (3 * PI) / 4 && pos->ray_data[x].rayangle > PI / 4)
		my_mlx_pixel_put(&pos->img, i, y, 0xFC0B04);
	if (pos->ray_data[x].rayangle > (3 * PI) / 4 && pos->ray_data[x].rayangle < (5 * PI) / 4)
		my_mlx_pixel_put(&pos->img, i, y, 0xFC0B04);
	if (pos->ray_data[x].rayangle < (7 * PI) / 4 && pos->ray_data[x].rayangle > (5 * PI) / 4))
		my_mlx_pixel_put(&pos->img, i, y, 0XF8FC04);
	if (pos->ray_data[x].rayangle > (7 * PI) / 4 || pos->ray_data[x].rayangle < PI / 4)
		my_mlx_pixel_put(&pos->img, i, y, 0xA904FC);
}

void	color_all_wall(t_game *pos, int i)
{
	int y;

	y = pos->player.walltoppixel;
	while (y < pos->player.wallbottompixel)
	{
		wall_position(pos, i)
		y++;
	}
}

void	color_all_buffer(t_game *pos)
{
	int x;
	int y;

	y = 0;
	while (y < pos->winres.window_height)
	{
		x = 0;
		while (x < pos->winres.window_width)
		{
			pos->colorbuffer[(int)(pos->winres.window_width * y) + x] = 0x1FB0E3;
			if (y < pos->winres.window_height / 2)
				my_mlx_pixel_put(&pos->img, x, y, pos->colorbuffer[(int)(pos->winres.window_width * y) + x]);
			else
				my_mlx_pixel_put(&pos->img, x, y, 0x9C4B0D);
			x++;
		}
		y++;
	}
}

void	projection_wall(t_game *pos, int x)
{
	pos->player.perpdistance = pos->ray_data[x].distance *
		cos(pos->ray_data[x].rayangle - pos->player.player_angle) ;
		pos->player.distanceprojplane = (pos->winres.window_width / 2) /
		tan(pos->player.FOV_angle / 2);
		pos->player.projectedwallheight = (pos->tile.size /
		pos->player.perpdistance) * pos->player.distanceprojplane;
		pos->player.wallstripheight = (int)pos->player.projectedwallheight;
		pos->player.walltoppixel = (pos->winres.window_height / 2) -
		(pos->player.wallstripheight / 2);
		pos->player.walltoppixel = pos->player.walltoppixel < 0 ? 0 :
		pos->player.walltoppixel;
		pos->player.wallbottompixel = (pos->winres.window_height / 2) +
		(pos->player.wallstripheight / 2);
		pos->player.wallbottompixel = pos->player.wallbottompixel >
		pos->winres.window_height ? pos->winres.window_height :
		pos->player.wallbottompixel;
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