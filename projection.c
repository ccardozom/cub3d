/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:13:25 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/30 11:51:14 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	wall_position(t_game *pos, int i, int y)
{
	if (pos->ray_data[i].washitvertical == TRUE &&
		pos->ray_data[i].israyfacingright)
		my_mlx_pixel_put(&pos->img, i, y,
		pos->texture.east_text.image[(pos->player.textureoffsety *
		pos->tile.size) + pos->player.textureoffsetx]);
	if (pos->ray_data[i].washitvertical == TRUE &&
		pos->ray_data[i].israyfacingleft)
		my_mlx_pixel_put(&pos->img, i, y,
		pos->texture.weast_text.image[(pos->player.textureoffsety *
		pos->tile.size) + pos->player.textureoffsetx]);
	if (pos->ray_data[i].washitvertical == FALSE &&
		pos->ray_data[i].israyfacingdown)
		my_mlx_pixel_put(&pos->img, i, y,
		pos->texture.south_text.image[(pos->player.textureoffsety *
		pos->tile.size) + pos->player.textureoffsetx]);
	if (pos->ray_data[i].washitvertical == FALSE &&
		pos->ray_data[i].israyfacingup)
		my_mlx_pixel_put(&pos->img, i, y,
		pos->texture.north_text.image[(pos->player.textureoffsety *
		pos->tile.size) + pos->player.textureoffsetx]);
}

void	color_all_wall(t_game *pos, int x)
{
	int y;
	int distancefromtop;

	y = pos->player.walltoppixel;
	distancefromtop = 0;
	while (y < pos->player.wallbottompixel)
	{
		distancefromtop = y + (pos->player.wallstripheight / 2) -
		(pos->winres.window_h / 2);
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
	cos(pos->ray_data[x].ray_angle - pos->player.player_angle);
	pos->player.distanceprojplane = (pos->winres.window_w / 2) /
	tan(pos->player.v_angle / 2);
	pos->player.projectedwallheight = (pos->tile.size /
	pos->player.perpdistance) * pos->player.distanceprojplane;
	pos->player.wallstripheight = (int)pos->player.projectedwallheight;
	pos->player.walltoppixel = (pos->winres.window_h / 2) -
	(pos->player.wallstripheight / 2);
	pos->player.walltoppixel = pos->player.walltoppixel < 0 ? 0 :
	pos->player.walltoppixel;
	pos->player.wallbottompixel = (pos->winres.window_h / 2) +
	(pos->player.wallstripheight / 2);
	pos->player.wallbottompixel = pos->player.wallbottompixel >
	pos->winres.window_h ? pos->winres.window_h :
	pos->player.wallbottompixel;
	if (pos->ray_data[x].washitvertical)
		pos->player.textureoffsetx = (int)pos->ray_data[x].wallhit_y %
		pos->tile.size;
	else
		pos->player.textureoffsetx = (int)pos->ray_data[x].wallhit_x %
		pos->tile.size;
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
