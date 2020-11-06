/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:13:51 by ccardozo          #+#    #+#             */
/*   Updated: 2020/11/06 14:00:30 by ccardozo         ###   ########.fr       */
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
	int textura_x, textura_y;
	float x;

	textura_x = 0;
	angulo_spr_vision(sprites, pos);
	x = sprites->x;
	while (x < (sprites->x + sprites->spr_height))
	{
		if (x >= 0 && x < (int)pos->winres.window_width && sprites->distance < pos->ray_data[(int)x].distance)
		{
			textura_y = 0;
			y = sprites->spr_top;
			while (y < sprites->spr_bottom)
			{
				if (pos->texture.sprite.image[(textura_y *
				pos->tile.size) + textura_x] != 0x000000)
					my_mlx_pixel_put(&pos->img, x, y + sprites->spr_top,
					pos->texture.sprite.image[(textura_y *
					pos->tile.size) + textura_x]);
				y++;
				textura_y++;
			}
		}
		x++;
		textura_x++;
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