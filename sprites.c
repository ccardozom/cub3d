/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:13:51 by ccardozo          #+#    #+#             */
/*   Updated: 2020/11/09 19:24:16 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	angulo_spr_vision(t_sprite *sprites, t_game *pos)
{
	sprites->x = pos->player.distanceprojplane * tan(sprites->spriteangulo);
	sprites->x = (pos->winres.window_width / 2 + sprites->x) - sprites->spr_height / 2;
	
}

void	angulo_sprites(t_game *pos)
{
	int	i;

	i = 0;
	while (i < pos->spritecount)
	{
		pos->sprites[i].vectx = pos->sprites[i].pos.x - pos->player.pos.x;
		pos->sprites[i].vecty = pos->sprites[i].pos.y - pos->player.pos.y;
		pos->sprites[i].spriteangulo = atan2(pos->sprites[i].vecty, pos->sprites[i].vectx);
		pos->sprites[i].spriteangulo -= pos->player.player_angle;
		//pos->sprites[i].anguloplayerobjeto =  - pos->sprites[i].spriteangulo;
		if (pos->sprites[i].spriteangulo < -1 * PI)
			pos->sprites[i].spriteangulo += 2.0 * PI;
		if (pos->sprites[i].spriteangulo > PI)
			pos->sprites[i].spriteangulo -= 2.0 * PI;
		if (pos->sprites[i].spriteangulo >= -1 * (pos->player.FOV_angle / 2) && pos->sprites[i].spriteangulo <= pos->player.FOV_angle / 2)
			pos->sprites[i].visible = TRUE;
		else
			pos->sprites[i].visible = FALSE;
		i++;
	}
}

void	color_sprites(t_sprite *sprites, t_game *pos) //revisar esta funcion
{
	float y;
	float textura_x, textura_y;
	int x, texturasend;
	float auxstep;

	auxstep = (float)pos->texture.sprite.w / (float)sprites->spr_height;
	textura_x = 0;
	angulo_spr_vision(sprites, pos);
	texturasend = sprites->x + sprites->spr_height;
	x = sprites->x;
	while (x < texturasend)
	{
		if (x >= 0 && x < (int)pos->winres.window_width && sprites->distance < pos->ray_data[x].distance)
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

void	distancia_sprites(t_game *pos, int i)
{
	pos->sprites[i].distance = distancebetweenpoints(pos->player.pos.x, pos->player.pos.y, pos->sprites[i].pos.x, pos->sprites[i].pos.y);
}

void	sprites(t_game *pos)
{
	int i;
	int id;

	i = 0;
	id = 0;
	angulo_sprites(pos);
	while (i < pos->spritecount)
	{
		if (pos->sprites[i].visible == TRUE)
		{
			distancia_sprites(pos, i);
			pos->sprites[i].spr_height = (pos->tile.size / pos->sprites[i].distance) * pos->player.distanceprojplane;
			pos->sprites[i].spr_top = (pos->winres.window_height / 2) - (pos->sprites[i].spr_height / 2);
			pos->sprites[i].spr_bottom = pos->sprites[i].spr_top + pos->sprites[i].spr_height;
			color_sprites(&pos->sprites[i], pos);
		}
		i++;
	}
}