/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:44:27 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/02 14:42:44 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	check_wall_close(char **mapa, int rows, int columns)
{
	int c;

	c = 0;
	while (c < columns)
	{
		if (mapa[rows][c + 1] == '1' || mapa[rows + 1][c] == '1')
			break;
		else
			return_error (12);
		c++;
	}
}

int		search_wall(t_game *pos, char *line)
{
	int index;

	index = 0;
	while (line[index] != '\0')
	{
		if (line[index] == '1' || line[index] == '0' ||
			line[index] == '2' || line[index] == 'N' || line[index] == ' ' ||
			line[index] == 'W' || line[index] == 'S' || line[index] == 'E')
			index++;
		else
			return (0);
	}
	if (*line != '\0')
		pos->control_map = 1;
	else
	{
		if (pos->control_map == 1)
			return_error (3);
		return (0);
	}
	return (1);
}

int		wall_control(char **map, int rows, int columns)
{
	int f;
	int c;
	
	f = 0;
	while (f < rows)
	{
		c = 0;
		while (c < columns)
		{
			if (map[f][c] == '1')
			{
				if (f == 0)
				{
					check_wall_close(map, f, columns);
				}
			}
			c++;
		}
		f++;
	}
	return (1);
}