/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:04:51 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/16 12:54:44 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	ordenar_sprites(t_game *pos)
{
	t_sprite	aux;
	int			index;
	int			cont_sprites;

	index = 0;
	if (pos->spritecount > 1)
		while (index < pos->spritecount)
		{
			cont_sprites = index + 1;
			reset_aux(&aux);
			while (cont_sprites < pos->spritecount)
			{
				if (pos->sprites[index].distance >
				pos->sprites[cont_sprites].distance)
				{
					aux = pos->sprites[cont_sprites];
					pos->sprites[cont_sprites] = pos->sprites[index];
					pos->sprites[index] = aux;
					break ;
				}
				cont_sprites++;
			}
			index++;
		}
}

void	angulo_spr_vision(t_sprite *sprites, t_game *pos)
{
	sprites->x = pos->player.distanceprojplane * tan(sprites->spriteangulo);
	sprites->x = (pos->winres.window_width / 2 + sprites->x) -
	sprites->spr_height / 2;
}

void	angulo_sprites(t_game *pos)
{
	int	i;

	i = 0;
	while (i < pos->spritecount)
	{
		pos->sprites[i].vectx = pos->sprites[i].pos.x - pos->player.pos.x;
		pos->sprites[i].vecty = pos->sprites[i].pos.y - pos->player.pos.y;
		pos->sprites[i].spriteangulo = atan2(pos->sprites[i].vecty,
		pos->sprites[i].vectx);
		pos->sprites[i].spriteangulo -= pos->player.player_angle;
		if (pos->sprites[i].spriteangulo < -1 * PI)
			pos->sprites[i].spriteangulo += 2.0 * PI;
		if (pos->sprites[i].spriteangulo > PI)
			pos->sprites[i].spriteangulo -= 2.0 * PI;
		if (pos->sprites[i].spriteangulo >= -1 * (pos->player.FOV_angle / 2) &&
		pos->sprites[i].spriteangulo <= pos->player.FOV_angle / 2)
			pos->sprites[i].visible = TRUE;
		else
			pos->sprites[i].visible = FALSE;
		pos->sprites[i].distance = distancebetweenpoints(pos->player.pos.x,
		pos->player.pos.y, pos->sprites[i].pos.x, pos->sprites[i].pos.y);
		i++;
	}
}

void	color_sprites(t_sprite *sprites, t_game *pos)
{
	t_colorS	color;
	int			x;
	float		y;

	init_color(&color, pos, sprites);
	x = sprites->x - 1;
	while (++x < color.texturasend)
	{
		if (x >= 0 && x <= (int)pos->winres.window_width &&
		sprites->distance < pos->ray_data[x].distance)
		{
			color.ty = 0;
			y = sprites->spr_top - 1;
			while (++y < sprites->spr_bottom)
			{
				color.index = ((int)color.ty * pos->tile.size) + (int)color.tx;
				if (y > 0 && y < (int)pos->winres.window_height)
					if (pos->texture.sprite.image[color.index] != 0x0)
						my_mlx_pixel_put(&pos->img, x, y,
						pos->texture.sprite.image[color.index]);
				color.ty += color.auxstep;
			}
		}
		color.tx += color.auxstep;
	}
}

void	sprites(t_game *pos)
{
	int i;
	int id;

	i = pos->spritecount;
	id = 0;
	angulo_sprites(pos);
	ordenar_sprites(pos);
	while (id < pos->spritecount)
	{
		i--;
		if (pos->sprites[i].visible == TRUE)
		{
			pos->sprites[i].spr_height = (pos->tile.size /
			pos->sprites[i].distance) * pos->player.distanceprojplane;
			pos->sprites[i].spr_top = (pos->winres.window_height / 2) -
			(pos->sprites[i].spr_height / 2);
			pos->sprites[i].spr_bottom = pos->sprites[i].spr_top +
			pos->sprites[i].spr_height;
			color_sprites(&pos->sprites[i], pos);
		}
		id++;
	}
}
