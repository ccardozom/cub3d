/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:13:51 by ccardozo          #+#    #+#             */
/*   Updated: 2020/11/05 14:08:38 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	angulo_sprites(t_game *pos)
{
	int	i;

	i = 0;
	while (i < pos->spritecount)
	{
		pos->sprites[i].vectx = pos->sprites[i].pos.x - pos->player.pos.x;
		pos->sprites[i].vecty = pos->sprites[i].pos.y - pos->player.pos.y;
		pos->sprites[i].spriteangulo = atan2(pos->sprites[i].vecty, pos->sprites[i].vectx);
		pos->sprites[i].spriteangulo = normalizeangle(pos->sprites[i].spriteangulo);
		pos->sprites[i].anguloplayerobjeto = pos->player.player_angle - pos->sprites[i].spriteangulo;
		if (pos->sprites[i].anguloplayerobjeto < -1 * PI)
			pos->sprites[i].anguloplayerobjeto += 2.0 * PI;
		if (pos->sprites[i].anguloplayerobjeto > PI)
			pos->sprites[i].anguloplayerobjeto -= 2.0 * PI;
		if (pos->sprites[i].anguloplayerobjeto >= -1 * (pos->player.FOV_angle / 2) && pos->sprites[i].anguloplayerobjeto <= pos->player.FOV_angle / 2)
			pos->sprites[i].visible = TRUE;
		else
			pos->sprites[i].visible = FALSE;
		i++;
	}
}

void	color_sprites(t_sprite *sprites, t_game *pos)
{
	int y;
	int distancefromtop;
	int init_spr;

	y = sprites->spr_top;
	distancefromtop = 0;
	while (y < sprites->spr_bottom)
	{
		init_spr = sprites->pos.x - (pos->tile.size / 2);
		while (init_spr < (sprites->pos.x + (pos->tile.size / 2)))
		{
		distancefromtop = y + (sprites->spr_height / 2) -
		(pos->winres.window_height / 2);
		pos->player.textureoffsety = distancefromtop *
		((float)pos->texture.sprite.h / sprites->spr_height);
		pos->player.textureoffsety *= (pos->player.textureoffsety < 0 ? -1 : 1);
		my_mlx_pixel_put(&pos->img, init_spr, y,
		pos->texture.sprite.image[(pos->player.textureoffsety *
		pos->tile.size) + pos->player.textureoffsetx]);
		init_spr++;
		}
		y++;
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
	//float aux_x;

	i = 0;
	id = 0;
	angulo_sprites(pos);
	while (i < pos->spritecount)
	{
		if (pos->sprites[i].visible == TRUE)
		{
			distancia_sprites(pos, i);
			pos->sprites[i].spr_height = (pos->tile.size / pos->sprites[i].distance) * pos->player.distanceprojplane;
			pos->sprites[i].spr_height = (int)pos->sprites[i].spr_height;
			pos->sprites[i].spr_top = (pos->winres.window_height / 2) - (pos->sprites[i].spr_height / 2);
			pos->sprites[i].spr_top = pos->sprites[i].spr_top < 0 ? 0 :
			pos->sprites[i].spr_top;
			pos->sprites[i].spr_bottom = pos->sprites[i].spr_top + pos->tile.size;
			pos->sprites[i].spr_bottom = pos->sprites[i].spr_bottom >
			pos->winres.window_height ? pos->winres.window_height :
			pos->sprites[i].spr_bottom;
			pos->player.textureoffsetx = (int)pos->sprites[i].pos.x %
			pos->tile.size;
			color_sprites(&pos->sprites[i], pos);
		// 	// aux_x = tan(pos->sprites[i].anguloplayerobjeto) * pos->player.distanceprojplane;
		// 	// pos->sprites[i].x = (pos->winres.window_width / 2 + aux_x) - pos->sprites[i].spr_height / 2;
		// 	// while (id < pos->rows)
		// 	// {
		// 	// 	//
		// 	// 	id++;
		// 	// }
		}
		i++;
	}
}