/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 10:02:03 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/17 10:57:54 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	pos_check(t_game *pos, char *line)
{
	if (line[(int)pos->matriz.x] == '2')
	{
		pos->sprites[pos->spritecount_aux].pos.x =
		(pos->matriz.x * pos->tile.size) + (pos->tile.size / 2);
		pos->sprites[pos->spritecount_aux++].pos.y =
		(pos->matriz.y * pos->tile.size) + (pos->tile.size / 2);
	}
	if (line[(int)pos->matriz.x] == ' ')
		pos->map[(int)pos->matriz.y][(int)pos->matriz.x] = '8';
	else
		pos->map[(int)pos->matriz.y][(int)pos->matriz.x] =
		line[(int)pos->matriz.x];
	if (player(line[(int)pos->matriz.x]) == 0)
	{
		pos->checkplayer = 1;
		pos->player.player_control += 1;
	}
}

void	new_matriz(t_game *pos, char *line)
{
	int	check_end_line;

	check_end_line = 0;
	while (pos->matriz.x < pos->columns)
	{
		if (line[(int)pos->matriz.x] == '\0')
			check_end_line = 1;
		if (check_end_line == 0)
		{
			if (line[(int)pos->matriz.x] == '1' ||
			line[(int)pos->matriz.x] == '2' ||
			player(line[(int)pos->matriz.x]) == 0 ||
			line[(int)pos->matriz.x] == '0' ||
			line[(int)pos->matriz.x] == ' ')
				pos_check(pos, line);
			else
				return_error(16);
		}
		else
			pos->map[(int)pos->matriz.y][(int)pos->matriz.x] = '8';
		pos->matriz.x++;
	}
	pos->map[(int)pos->matriz.y][(int)pos->matriz.x] = '\0';
	pos->matriz.x = 0;
	pos->matriz.y++;
}

void	create_matriz(char *line, t_game *pos)
{
	if ((pos->line_count2 == pos->line_count1) && *line != '\0')
		new_matriz(pos, line);
	if (pos->line_count2 != pos->line_count1)
		pos->line_count2++;
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

void	create_map(t_game *pos, char **argv)
{
	char	*line;
	int		fd;

	reserv_memo(pos);
	if (checker(pos->checking) &&
	pos->control_map == 1)
	{
		rellenar_matriz(pos->map, pos->rows, pos->columns);
		fd = open_file(argv);
		while (get_next_line(fd, &line) == 1)
		{
			reset_sprites(pos);
			create_matriz(line, pos);
			if (line != '\0')
				free(line);
		}
		create_matriz(line, pos);
		free(line);
		close(fd);
	}
	else
		return_error(11);
}
