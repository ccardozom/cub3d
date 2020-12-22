/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:04:51 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/22 14:20:26 by ccardozo         ###   ########.fr       */
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
			ft_bzero(&aux, sizeof(t_sprite));
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

void	angulo_spr_vision(t_sprite *sprites, t_game *pos, t_colortexture *t)
{
	sprites->x = pos->player.distanceprojplane * tan(sprites->spriteangulo);
	sprites->x = (pos->winres.window_width / 2 + sprites->x) -
	sprites->spr_height / 2;
	t->tex_x = 0;
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
	t_colortexture	t;

	t.auxstep = (float)pos->texture.sprite.w / (float)sprites->spr_height;
	angulo_spr_vision(sprites, pos, &t);
	t.tex_send = sprites->x + sprites->spr_height;
	t.x = sprites->x - 1;
	while (++t.x < t.tex_send)
	{
		if (t.x >= 0 && t.x <= (int)pos->winres.window_width &&
		sprites->distance < pos->ray_data[t.x].distance)
		{
			t.tex_y = 0;
			t.y = sprites->spr_top - 1;
			while (t.y < sprites->spr_bottom)
			{
				t.index = ((int)t.tex_y * pos->tile.size) + (int)t.tex_x;
				if (++t.y > 0 && t.y < (int)pos->winres.window_height)
					if (pos->texture.sprite.image[t.index] != 0x0)
						my_mlx_pixel_put(&pos->img, t.x, t.y,
						pos->texture.sprite.image[t.index]);
				t.tex_y += t.auxstep;
			}
		}
		t.tex_x += t.auxstep;
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
