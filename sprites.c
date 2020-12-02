/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:04:51 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/02 09:41:18 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"
void reset_aux(t_sprite *aux)
{
	aux->pos.window_height=0;
	aux->pos.window_width=0;
	aux->pos.x=0;
	aux->pos.y=0;
	aux->distance=0;
	aux->vectx=0;
	aux->vecty=0;
	aux->visible=0;
	aux->spriteangulo=0;
	aux->spr_bottom=0;
	aux->spr_top=0;
	aux->x=0;
	aux->spr_height=0;
}

void	ordenar_sprites(t_game *pos)
{
	t_sprite	aux;
	int			index;
	int			cont_sprites;

	index = 0;
	if (pos->spritecount > 1)
		while (index < pos->spritecount)
		{	cont_sprites = index + 1;
			reset_aux(&aux);
			while (cont_sprites < pos->spritecount)
			{
				if (pos->sprites[index].distance > pos->sprites[cont_sprites].distance)
				{
					aux = pos->sprites[cont_sprites];
					pos->sprites[cont_sprites] = pos->sprites[index];
					pos->sprites[index] = aux;
					break;
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
	float	y;
	float	textura_x;
	float	textura_y;
	int		x;
	int		texturasend;
	float	auxstep;

	auxstep = (float)pos->texture.sprite.w / (float)sprites->spr_height;
	textura_x = 0;
	angulo_spr_vision(sprites, pos);
	texturasend = sprites->x + sprites->spr_height;
	x = sprites->x;
	while (x < texturasend)
	{
		if (x >= 0 && x <= (int)pos->winres.window_width &&
		sprites->distance < pos->ray_data[x].distance)
		{
			textura_y = 0;
			y = sprites->spr_top;
			while (y < sprites->spr_bottom)
			{
				if (y > 0 && y < (int)pos->winres.window_height)
					if (pos->texture.sprite.image[((int)textura_y *
					pos->tile.size) + (int)textura_x] != 0x000000)
						my_mlx_pixel_put(&pos->img, x, y,
						pos->texture.sprite.image[((int)textura_y *
						pos->tile.size) + (int)textura_x]);
				y++;
				textura_y += auxstep;
			}
		}
		x++;
		textura_x += auxstep;
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
