/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:44:27 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/27 14:23:01 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int		search_wall(t_game *pos, char *line)
{
	int index;

	index = 0;
	while (*line == ' ' || *line == '\t')
		line++;
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
	{
		pos->control_map = 1;
		pos->control_line_empty = 1;
	}
	else
	{
		pos->control_line_empty = 0;
		return (0);
	}
	return (1);
}

int		wall_control(char **m, int rows, int col)
{
	int f;
	int c;

	f = 0;
	while (f < rows)
	{
		c = -1;
		while (++c < col)
		{
			if (m[f][c] == '0' || m[f][c] == '2' || player(m[f][c]) == 0)
			{
				if (f == 0 || f == rows - 1 || c == 0 || c == col - 1 ||
					m[f - 1][c] == '8' || m[f - 1][c + 1] == '8' ||
					m[f][c + 1] == '8' || m[f + 1][c + 1] == '8' ||
					m[f + 1][c] == '8' || m[f + 1][c - 1] == '8' ||
					m[f][c - 1] == '8' || m[f - 1][c - 1] == '8')
				{
					ft_putstr_fd("Error\n El mapa esta abierto", 1);
					exit(0);
				}
			}
		}
		f++;
	}
	return (1);
}
