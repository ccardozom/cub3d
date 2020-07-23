/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matriz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:15:12 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/23 09:55:14 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fill_matriz(t_pos_py *pos)
{
	int		f;
	int		c;

	f = 0;
	while (f < pos->map_f)
	{
		c = 0;
		while (c < pos->map_c)
		{
			pos->map[f][c] = relleno;
			c++;
		}
		pos->map[f][c] = '\0';
		f++;
	}
}

void	new_matriz(t_pos_py *pos, char *line)
{
	while (pos->matriz_c < pos->map_c)
	{
		pos->map[pos->matriz_f][pos->matriz_c] = line[pos->matriz_c];
		pos->matriz_c++;
	}
	pos->matriz_c = 0;
	pos->matriz_f++;
}
