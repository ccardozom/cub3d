/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3dprojection_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:00:37 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/07 11:00:37 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	charge_textures(t_game *pos, t_text *texture)
{
	if (texture->path)
		if (!(texture->id = mlx_xpm_file_to_image(player->mlx_ptr,
			texture->path, &texture->w, &texture->h)))
			return_error();
	if (!(texture->image = (int*)mlx_get_data_addr(texture->id, &texture->data,
		&texture->size_line, &texture->endian)))
		return_error();
	// free(texture->path);
	// return (1);
}

void		charge_textures_main(t_game *pos)
{
	if (!(charge_textures(pos, &pos->texture.north_text)))
		return_error();
	if (!(charge_textures(pos, &pos->texture.south_text)))
		return_error();
	if (!(charge_textures(pos, &pos->texture.weast_text)))
		return_error();
	if (!(charge_textures(pos, &pos->texture.east_text)))
		return_error();
	if (!(charge_textures(pos, &pos->texture.sprite)))
		return_error();
}

void	color_all_buffer(t_game *pos)
{
	int x;
	int y;

	y = 0;
	charge_textures_main(pos);
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