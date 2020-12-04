/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:44:27 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/04 10:57:14 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	check_wall_line(char **mapa, int rows, int columns, t_checkmap *checkmap)
{ //aqui hay que mirar el fallo para el mapa de la derech
	if (checkmap->check_ini == 0 || checkmap->check_fin == 0)
	{
	if (checkmap->check_ini == 1 && mapa[rows][columns] == '1' && (mapa[rows - 1][columns] == '1' ||
		mapa[rows][columns + 1] == '1' || mapa[rows + 1][columns] == '1'))
		checkmap->check_fin = 1;
	if (mapa[rows - 1][columns] == '1' && (mapa[rows][columns + 1] == '0' ||
		mapa[rows][columns + 1] == '2' || player(mapa[rows][columns + 1])) && checkmap->check_ini == 0)
		checkmap->check_ini = 1;	
	}
	if (mapa[rows][columns + 1] == '1' && mapa[rows + 1][columns] != '8' && mapa[rows][columns + 1] != '\0')
		checkmap->check_fin = 0;
}

void	check_wallup_close(char **mapa, int rows, int columns)
{
	if (mapa[rows][columns] != '1' && mapa[rows + 1][columns] != '1' &&
		(mapa[rows + 1][columns] == '0' ||
		mapa[rows + 1][columns] == '2' || player(mapa[rows + 1][columns])))
		return_error (14);
	if (mapa[rows][columns + 1] == '1' || mapa[rows + 1][columns] == '1')
		;
	else
		return_error (14);
}

void	check_walldown_close(char **mapa, int rows, int columns)
{
	if (mapa[rows][columns] != '1' && (mapa[rows - 1][columns] == '0' ||
		mapa[rows - 1][columns] == '2' || player(mapa[rows - 1][columns])))
		return_error (14);
	if (mapa[rows][columns - 1] == '1' || mapa[rows - 1][columns] == '1')
		;
	else
		return_error (14);
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

int		wall_control(char **map, int rows, int columns, t_checkmap *checkmap)
{
	checkmap->f = 0;
	while (checkmap->f < rows)
	{
		checkmap->c = 0;
		checkmap->check_ini = 0;
		checkmap->check_fin = 0;
		while (checkmap->c < columns)
		{
			if (checkmap->f == 0)
			{
				check_wallup_close(map, checkmap->f, checkmap->c);
			}
			if (checkmap->f != 0 && checkmap->f != rows - 1)
			{
				check_wall_line(map, checkmap->f, checkmap->c, checkmap);
			}
			if (checkmap->f == rows - 1)
			{
				check_walldown_close(map, checkmap->f, checkmap->c);
			} 
			checkmap->c++;
		}
		if (checkmap->f != 0 && checkmap->f != rows - 1)
			if (checkmap->check_ini == 0 || checkmap->check_fin == 0)
				return_error (14);
		checkmap->f++;
	}
	return (1);
}