/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:07:15 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/17 10:59:03 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int		player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return (1);
}

void	reserv_memo(t_game *pos)
{
	int		i;

	if (!(pos->map = (char **)malloc(pos->rows * sizeof(char *))))
		return_error(4);
	i = 0;
	while (i < pos->rows)
	{
		if (!(pos->map[i] = (char *)malloc((pos->columns + 1)
		* sizeof(char))))
			return_error(4);
		i++;
	}
	if (!(pos->sprites = (t_sprite *)malloc(sizeof(t_sprite)
	* pos->spritecount)))
		return_error(4);
}

int		get_color_bmp(t_data *windows, int x, int y, t_bitmap *w)
{
	int		rgb;
	int		color;

	color = *(int*)(windows->addr + (4 * w->width *
	(w->heigth - 1 - y)) + (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

void	reset_aux(t_sprite *aux)
{
	aux->pos.window_height = 0;
	aux->pos.window_width = 0;
	aux->pos.x = 0;
	aux->pos.y = 0;
	aux->distance = 0;
	aux->vectx = 0;
	aux->vecty = 0;
	aux->visible = 0;
	aux->spriteangulo = 0;
	aux->spr_bottom = 0;
	aux->spr_top = 0;
	aux->x = 0;
	aux->spr_height = 0;
}

void	init_color(t_colorspri *color, t_game *pos, t_sprite *sprites)
{
	color->auxstep = (float)pos->texture.sprite.w / (float)sprites->spr_height;
	color->tx = 0;
	angulo_spr_vision(sprites, pos);
	color->texturasend = sprites->x + sprites->spr_height;
	color->index = 0;
}
