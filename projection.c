/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:13:25 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/27 14:21:54 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	wall_position(t_game *pos, int i, int y)
{
	int index;

	index = ((int)pos->player.textureoffsety * pos->texture.east_text.h) +
	(int)pos->player.textureoffsetx;
	if (pos->ray_data[i].washitvertical == TRUE &&
		pos->ray_data[i].israyfacingright)
		my_mlx_pixel_put(&pos->img, i, y,
		pos->texture.east_text.image[index]);
	if (pos->ray_data[i].washitvertical == TRUE &&
		pos->ray_data[i].israyfacingleft)
		my_mlx_pixel_put(&pos->img, i, y,
		pos->texture.weast_text.image[index]);
	if (pos->ray_data[i].washitvertical == FALSE &&
		pos->ray_data[i].israyfacingdown)
		my_mlx_pixel_put(&pos->img, i, y,
		pos->texture.south_text.image[index]);
	if (pos->ray_data[i].washitvertical == FALSE &&
		pos->ray_data[i].israyfacingup)
		my_mlx_pixel_put(&pos->img, i, y,
		pos->texture.north_text.image[index]);
}

void	color_all_wall(t_game *pos, int x)
{
	float y;
	float distancefromtop;

	y = pos->player.walltoppixel;
	distancefromtop = 0;
	while (y < pos->player.wallbottompixel)
	{
		distancefromtop = y + (pos->player.wallstripheight / 2) -
		(pos->winres.y / 2);
		pos->player.textureoffsety = distancefromtop *
		((float)pos->texture.east_text.h / pos->player.wallstripheight);
		pos->player.textureoffsety *= (pos->player.textureoffsety < 0 ? -1 : 1);
		wall_position(pos, x, y);
		y++;
	}
}

void	projection_wall(t_game *pos, int x)
{
	pos->player.perpdistance = pos->ray_data[x].distance *
	cos(pos->player.player_angle - pos->ray_data[x].ray_angle);
	pos->player.distanceprojplane = (pos->winres.x / 2) /
	tan(pos->player.v_angle / 2);
	pos->player.projectedwallheight = (pos->tile.size /
	pos->player.perpdistance) * pos->player.distanceprojplane;
	pos->player.wallstripheight = pos->player.projectedwallheight;
	pos->player.walltoppixel = (pos->winres.y / 2) -
	(pos->player.wallstripheight / 2);
	pos->player.walltoppixel = pos->player.walltoppixel < 0 ? 0 :
	pos->player.walltoppixel;
	pos->player.wallbottompixel = (pos->winres.y / 2) +
	(pos->player.wallstripheight / 2);
	pos->player.wallbottompixel = pos->player.wallbottompixel >
	pos->winres.y ? pos->winres.y :
	pos->player.wallbottompixel;
	if (pos->ray_data[x].washitvertical)
		pos->player.textureoffsetx = (pos->texture.east_text.h /
		pos->tile.size) * (pos->ray_data[x].wallhit_y -
		(int)(pos->ray_data[x].wallhit_y / pos->tile.size) * pos->tile.size);
	else
		pos->player.textureoffsetx = (pos->texture.east_text.h /
		pos->tile.size) * (pos->ray_data[x].wallhit_x -
		(int)(pos->ray_data[x].wallhit_x / pos->tile.size) * pos->tile.size);
	color_all_wall(pos, x);
}

void	generate_3dprojection(t_game *pos)
{
	int i;

	color_all_buffer(pos);
	i = 0;
	while (i < pos->player.num_rays)
	{
		projection_wall(pos, i);
		i++;
	}
}
