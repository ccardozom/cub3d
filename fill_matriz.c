/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matriz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:15:12 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/21 11:46:54 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fill_matriz(t_game *pos)
{
	int		f;
	int		c;

	f = 0;
	while (f < pos->rows)
	{
		c = 0;
		while (c < pos->columns)
		{
			pos->map[f][c] = relleno;
			c++;
		}
		pos->map[f][c] = '\0';
		f++;
	}
}

void	new_matriz(t_game *pos, char *line)
{
	while (pos->matriz.x < pos->columns)
	{
		if (line[(int)pos->matriz.x] == '1' ||
		line[(int)pos->matriz.x] == '2' ||
		line[(int)pos->matriz.x] == 'N' ||
		line[(int)pos->matriz.x] == '0')
			pos->map[(int)pos->matriz.y][(int)pos->matriz.x] =
			line[(int)pos->matriz.x];
		pos->matriz.x++;
	}
	pos->matriz.x = 0;
	pos->matriz.y++;
}
