/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:04:51 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/02 21:04:08 by ccardozo         ###   ########.fr       */
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