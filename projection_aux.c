/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:00:37 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/27 14:21:50 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int			get_color(t_color pixel)
{
	int		color;

	color = pixel.r;
	color = (color << 8) | pixel.g;
	color = (color << 8) | pixel.b;
	return (color);
}

int			charge_textures(t_game *pos, t_text *texture)
{
	if (texture->path)
		if (!(texture->id = mlx_xpm_file_to_image(pos->mlx,
			texture->path, &texture->w, &texture->h)))
			return (0);
	if (!(texture->image = (int*)mlx_get_data_addr(texture->id, &texture->data,
		&texture->size_line, &texture->endian)))
		return (0);
	return (1);
}

void		charge_textures_main(t_game *pos)
{
	if (!(charge_textures(pos, &pos->texture.north_text)))
		return_error(5);
	if (!(charge_textures(pos, &pos->texture.south_text)))
		return_error(6);
	if (!(charge_textures(pos, &pos->texture.weast_text)))
		return_error(7);
	if (!(charge_textures(pos, &pos->texture.east_text)))
		return_error(8);
	if (!(charge_textures(pos, &pos->texture.sprite)))
		return_error(9);
}

void		color_all_buffer(t_game *pos)
{
	int x;
	int y;

	y = 0;
	charge_textures_main(pos);
	while (y < pos->winres.y)
	{
		x = 0;
		while (x < pos->winres.x)
		{
			if (y < pos->winres.y / 2)
			{
				my_mlx_pixel_put(&pos->img, x, y,
				get_color(pos->texture.ceilling));
			}
			else
				my_mlx_pixel_put(&pos->img, x, y,
				get_color(pos->texture.floor));
			x++;
		}
		y++;
	}
}
