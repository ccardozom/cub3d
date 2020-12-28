/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:04:51 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/28 10:25:14 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	ordenar_sprites(t_game *pos)
{
	t_sprite	aux;
	int			index;
	int			cont_sprites;

	index = 0;
	if (pos->sp_count > 1)
		while (index < pos->sp_count)
		{
			cont_sprites = index + 1;
			ft_bzero(&aux, sizeof(t_sprite));
			while (cont_sprites < pos->sp_count)
			{
				if (pos->sp[index].distance >
				pos->sp[cont_sprites].distance)
				{
					aux = pos->sp[cont_sprites];
					pos->sp[cont_sprites] = pos->sp[index];
					pos->sp[index] = aux;
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
	while (i < pos->sp_count)
	{
		pos->sp[i].vectx = pos->sp[i].pos.x - pos->player.pos.x;
		pos->sp[i].vecty = pos->sp[i].pos.y - pos->player.pos.y;
		pos->sp[i].spriteangulo = atan2(pos->sp[i].vecty,
		pos->sp[i].vectx);
		pos->sp[i].spriteangulo -= pos->player.player_angle;
		if (pos->sp[i].spriteangulo < -1 * PI)
			pos->sp[i].spriteangulo += 2.0 * PI;
		if (pos->sp[i].spriteangulo > PI)
			pos->sp[i].spriteangulo -= 2.0 * PI;
		if (pos->sp[i].spriteangulo >= -1 * (pos->player.fov_angle / 2) &&
		pos->sp[i].spriteangulo <= pos->player.fov_angle / 2)
			pos->sp[i].visible = TRUE;
		else
			pos->sp[i].visible = FALSE;
		pos->sp[i].distance = distancebetweenpoints(pos->player.pos.x,
		pos->player.pos.y, pos->sp[i].pos.x, pos->sp[i].pos.y);
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

	i = pos->sp_count;
	id = 0;
	angulo_sprites(pos);
	ordenar_sprites(pos);
	while (id < pos->sp_count)
	{
		i--;
		if (pos->sp[i].visible == TRUE)
		{
			pos->sp[i].spr_height = (pos->tile.size /
			pos->sp[i].distance) * pos->player.distanceprojplane;
			pos->sp[i].spr_top = (pos->winres.window_height / 2) -
			(pos->sp[i].spr_height / 2);
			pos->sp[i].spr_bottom = pos->sp[i].spr_top +
			pos->sp[i].spr_height;
			color_sprites(&pos->sp[i], pos);
		}
		id++;
	}
}
