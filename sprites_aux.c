/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:04:51 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/02 21:36:52 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	angulo_ini(t_game *pos, int x1, int i)
{
	x1 = (pos->sp[i].pos.x - pos->tile.size / 2) - pos->player.pos.x;
	pos->sp[i].anguloini = atan2(pos->sp[i].vecty, x1);
	pos->sp[i].anguloini -= pos->player.player_angle;
	pos->sp[i].anguloini = pos->sp[i].anguloini < -1 * PI ?
	pos->sp[i].anguloini + (2.0 * PI) : pos->sp[i].anguloini;
	pos->sp[i].anguloini = pos->sp[i].anguloini > PI ?
	pos->sp[i].anguloini - (2.0 * PI) : pos->sp[i].anguloini;
}

void	angulo_fin(t_game *pos, int x2, int i)
{
	x2 = (pos->sp[i].pos.x + pos->tile.size / 2) - pos->player.pos.x;
	pos->sp[i].angulofin = atan2(pos->sp[i].vecty, x2);
	pos->sp[i].angulofin -= pos->player.player_angle;
	pos->sp[i].angulofin = pos->sp[i].angulofin < -1 * PI ?
	pos->sp[i].angulofin + (2.0 * PI) : pos->sp[i].angulofin;
	pos->sp[i].angulofin = pos->sp[i].angulofin > PI ?
	pos->sp[i].angulofin - (2.0 * PI) : pos->sp[i].angulofin;
}

void	angulo_central(t_game *pos, int i)
{
	pos->sp[i].spriteangulo = atan2(pos->sp[i].vecty, pos->sp[i].vectx);
	pos->sp[i].spriteangulo -= pos->player.player_angle;
	pos->sp[i].spriteangulo = pos->sp[i].spriteangulo < -1 * PI ?
	pos->sp[i].spriteangulo + (2.0 * PI) : pos->sp[i].spriteangulo;
	pos->sp[i].spriteangulo = pos->sp[i].spriteangulo > PI ?
	pos->sp[i].spriteangulo - (2.0 * PI) : pos->sp[i].spriteangulo;
}
