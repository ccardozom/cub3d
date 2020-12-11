/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:44:27 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/11 12:25:52 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

/*void	check_wall_line(char **mapa, int rows, int columns, t_checkmap *checkmap)
{
	if (checkmap->check_ini == 0 || checkmap->check_fin == 0)
	{
	if (checkmap->check_ini == 1 && mapa[rows][columns] == '1' && (mapa[rows - 1][columns] == '1' ||
		mapa[rows][columns + 1] == '1' || mapa[rows + 1][columns] == '1'))
	checkmap->check_fin = 1;
	if (mapa[rows - 1][columns] == '1' && (mapa[rows][columns + 1] == '0' ||
		mapa[rows][columns + 1] == '2' || player(mapa[rows][columns + 1])) && checkmap->check_ini == 0)
		checkmap->check_ini = 1;	
	}
	if ((mapa[rows][columns + 1] == '1' || mapa[rows][columns + 1] != '\0') && mapa[rows][columns + 1] != '8' &&
	mapa[rows + 1][columns] != '8' && mapa[rows + 1][columns + 1] != '8')
		checkmap->check_fin = 0;
}

void	check_wallup_close(char **mapa, int rows, int columns)
{
	if (mapa[rows][columns] == '1' || mapa[rows][columns] == '8')
	{
		if (mapa[rows][columns] == '8' && mapa[rows + 1][columns] == '1' && mapa[rows][columns + 1] != '1')
		{
			if ((mapa[rows + 1][columns - 1] == '0' ||
			mapa[rows + 1][columns - 1] == '2' || player(mapa[rows + 1][columns - 1])) ||
			(mapa[rows + 1][columns + 1] == '0' ||
			mapa[rows + 1][columns + 1] == '2' || player(mapa[rows + 1][columns + 1])))
			return_error (14);
		}
		;
	}
	else
		return_error (14);
}

void	check_walldown_close(char **mapa, int rows, int columns)
{
	if (mapa[rows][columns] == '1' || mapa[rows][columns] == '8')
	{
		if (mapa[rows][columns] == '8' && mapa[rows - 1][columns] == '1')
		{
			if (((mapa[rows - 1][columns - 1] == '0' ||
			mapa[rows - 1][columns - 1] == '2' || player(mapa[rows - 1][columns - 1])) && mapa[rows - 1][columns + 1] != '8') ||
			(mapa[rows - 1][columns + 1] == '0' ||
			mapa[rows - 1][columns + 1] == '2' || player(mapa[rows - 1][columns + 1])))
			return_error (14);
		}
		;
	}
	else
		return_error (14);
}
*/
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
		/*if (pos->control_map == 1)
			return_error (3);*/
		return (0);
	}
	return (1);
}

int		wall_control(char **matriz, int rows, int columns)
{
	int filas;
	int columnas;

	filas = 0;
	while (filas < rows)
	{
		columnas = 0;
		while (columnas < columns)
		{
			if (matriz[filas][columnas] == '0' || matriz[filas][columnas] == '2')
			{
				if (filas == 0 || filas == rows - 1 || columnas == 0 || columnas == columns - 1)
				{
					ft_putstr_fd("Error\n El mapa esta abierto", 1);
					exit (0);
				}
				if (matriz[filas - 1][columnas] == '8' || matriz[filas - 1][columnas + 1] == '8' ||
					matriz[filas][columnas + 1] == '8' || matriz[filas + 1][columnas + 1] == '8' ||
					matriz[filas + 1][columnas] == '8' || matriz[filas + 1][columnas - 1] == '8' ||
					matriz[filas][columnas - 1] == '8' || matriz[filas - 1][columnas - 1] == '8')
				{
					ft_putstr_fd("Error\n El mapa esta abierto", 1);
					exit (0);
				}
			}
			columnas++;
		}
		filas++;
	}
	return (1);
}