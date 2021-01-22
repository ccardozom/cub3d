/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 10:37:44 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/21 15:33:16 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		put_color_pixel(t_game *pos)
{
	int		pos_sx;
	int		pos_x;

	pos_x = pos->tile.squa_c;
	pos_sx = 0;
	while (pos_sx < pos->tile.size)
	{
		my_mlx_pixel_put(&pos->img, pos_x * pos->player.minimapscale,
		pos->tile.squa_f * pos->player.minimapscale, 0xFFFFFF);
		if (pos->map[pos->tile.f][pos->tile.c] == '1' ||
		pos->map[pos->tile.f][pos->tile.c] == '8')
			my_mlx_pixel_put(&pos->img, pos_x * pos->player.minimapscale,
			pos->tile.squa_f * pos->player.minimapscale, 0x0101DF);
		if (pos->map[pos->tile.f][pos->tile.c] == '2')
		{
			my_mlx_pixel_put(&pos->img, pos_x * pos->player.minimapscale,
			pos->tile.squa_f * pos->player.minimapscale, 0x28A108);
		}
		pos_sx++;
		pos_x++;
	}
	return (pos->tile.size);
}

void	draw_minimap(t_game *pos)
{
	pos->tile.squa_f = 0;
	pos->tile.pos_squa = 0;
	pos->tile.f = 0;
	while (pos->tile.f < pos->rows)
	{
		pos->tile.c = 0;
		pos->tile.squa_c = 0;
		while (pos->tile.c < pos->columns)
		{
			pos->tile.squa_c += put_color_pixel(pos);
			pos->tile.c++;
		}
		pos->tile.squa_f++;
		pos->tile.pos_squa++;
		if (pos->tile.pos_squa >= pos->tile.size)
		{
			pos->tile.f++;
			pos->tile.pos_squa = 0;
		}
	}
	draw_player_move(pos);
}
