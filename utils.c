/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:36:24 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/28 12:37:20 by ccardozo         ###   ########.fr       */
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

void	rellenar_matriz(char **matriz, int filas, int columnas)
{
	int i;
	int j;

	j = 0;
	while (filas > j)
	{
		i = 0;
		while (columnas > i)
		{
			matriz[j][i] = '8';
			i++;
		}
		matriz[j][i] = '\0';
		j++;
	}
}