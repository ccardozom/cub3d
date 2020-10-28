/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:13:51 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/28 11:36:21 by ccardozo         ###   ########.fr       */
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
		pos->sprites[i].anguloplayerobjeto = atan2(pos->sprites[i].vecty, pos->sprites[i].vectx);
		pos->sprites[i].diferenciaangulo = pos->player.player_angle - pos->sprites[i].anguloplayerobjeto;
		if (pos->sprites[i].diferenciaangulo < PI)
			pos->sprites[i].diferenciaangulo += 2.0 * PI;
		if (pos->sprites[i].diferenciaangulo > PI)
			pos->sprites[i].diferenciaangulo -= 2.0 * PI;
		pos->sprites[i].diferenciaangulo = fabsf(pos->sprites[i].diferenciaangulo);
		if (pos->sprites[i].diferenciaangulo < pos->player.FOV_angle / 2)
			pos->sprites[i].visible = TRUE;
		else
			pos->sprites[i].visible = FALSE;
		i++;
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
			pos->sprites[i].x0 = tan(pos->sprites[i].diferenciaangulo) * pos->tile.size;
			pos->sprites[i].x = (pos->winres.window_width/2 + pos->sprites[i].x0 - pos->tile.size / 2);
			while (id < pos->columns)
			{
				id++;
			}
		}
		i++;
	}
}