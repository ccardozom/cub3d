/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matriz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:15:12 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/20 14:15:08 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int		player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return (1);
}

void	new_matriz(t_game *pos, char *line)
{
	while (pos->matriz.x < pos->columns)
	{
		if (line[(int)pos->matriz.x] == '1' ||
		line[(int)pos->matriz.x] == '2' ||
		player(line[(int)pos->matriz.x]) == 0 ||
		line[(int)pos->matriz.x] == '0')
			pos->map[(int)pos->matriz.y][(int)pos->matriz.x] =
			line[(int)pos->matriz.x];
		pos->matriz.x++;
	}
	pos->matriz.x = 0;
	pos->matriz.y++;
}
