/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3dprojection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:13:25 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/14 14:08:46 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	wall_position(t_game *pos, int i, int y)
{
	if (pos->ray_data[i].washitvertical == TRUE && pos->ray_data[i].israyfacingright)
		my_mlx_pixel_put(&pos->img, i, y, pos->texture.east_text.image[(pos->player.textureoffsety * pos->tile.size) + pos->player.textureoffsetx]);
// la matriz pos->texture.image de cada lado contiene los colores en formato int por lo que se puede pasar directamente a my_mlx_pixel_put
// antes de pasar tenemos que saber las coordenadas del muro y ubicarlas en la textura
	if (pos->ray_data[i].washitvertical == TRUE && pos->ray_data[i].israyfacingleft)//oeste
		my_mlx_pixel_put(&pos->img, i, y, pos->texture.weast_text.image[(pos->player.textureoffsety * pos->tile.size) + pos->player.textureoffsetx]);
	if (pos->ray_data[i].washitvertical == FALSE && pos->ray_data[i].israyfacingdown)//sur
		my_mlx_pixel_put(&pos->img, i, y, pos->texture.south_text.image[(pos->player.textureoffsety * pos->tile.size) + pos->player.textureoffsetx]);
	if (pos->ray_data[i].washitvertical == FALSE && pos->ray_data[i].israyfacingup) //norte
	 	my_mlx_pixel_put(&pos->img, i, y, pos->texture.north_text.image[(pos->player.textureoffsety * pos->tile.size) + pos->player.textureoffsetx]);

	
}

void	color_all_wall(t_game *pos, int x)
{
	int y;

	y = pos->player.walltoppixel;
	while (y < pos->player.wallbottompixel)
	{
		pos->player.textureoffsety = (y - pos->player.wallbottompixel) * ((float)pos->texture.east_text.h / pos->player.wallstripheight);
	 	pos->player.textureoffsety *= (pos->player.textureoffsety < 0 ? -1 : 1);
		wall_position(pos, x, y);
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
		if (pos->ray_data[x].washitvertical)
			pos->player.textureoffsetx = (int)pos->ray_data[x].wallhitY % pos->tile.size;
		else
			pos->player.textureoffsetx = (int)pos->ray_data[x].wallhitX % pos->tile.size;
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