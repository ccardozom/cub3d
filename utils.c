/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:36:24 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/21 14:46:27 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int		get_color_bmp(t_data *windows, int x, int y, t_bitmap *w)
{
	int	rgb;
	int	color;

	color = *(int*)(windows->addr + (4 * w->width *
	(w->heigth - 1 - y)) + (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

int		player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return (1);
}

void	reset_color(t_color *color)
{
	color->empty = 0;
	color->r = -1;
	color->g = -1;
	color->b = -1;
}
