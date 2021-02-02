/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 10:37:44 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/27 14:20:27 by ccardozo         ###   ########.fr       */
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
	while (pos_sx < (int)pos->tile.size)
	{
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
		if (pos->tile.pos_squa >= (int)pos->tile.size)
		{
			pos->tile.f++;
			pos->tile.pos_squa = 0;
		}
	}
}
