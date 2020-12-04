/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 10:02:03 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/03 10:02:37 by ccardozo         ###   ########.fr       */
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
		line[(int)pos->matriz.x] == '0' ||
		line[(int)pos->matriz.x] == ' ')
		{
			if (line[(int)pos->matriz.x] == '2')
			{
				pos->sprites[pos->spritecount_aux].pos.x = (pos->matriz.x * pos->tile.size) + (pos->tile.size / 2);
				pos->sprites[pos->spritecount_aux++].pos.y = (pos->matriz.y * pos->tile.size) + (pos->tile.size / 2);
			}
			pos->map[(int)pos->matriz.y][(int)pos->matriz.x] =
			line[(int)pos->matriz.x];
			if (player(line[(int)pos->matriz.x]) == 0)
				pos->checkplayer = 1;
		}
		else
		{
			pos->map[(int)pos->matriz.y][(int)pos->matriz.x] =
			'8';
		}
		
		pos->matriz.x++;
	}
	pos->matriz.x = 0;
	pos->matriz.y++;
}

void		create_matriz(char *line, t_game *pos)
{
	if ((pos->line_count2 == pos->line_count1) && *line != '\0')
		new_matriz(pos, line);
	if (pos->line_count2 != pos->line_count1)
		pos->line_count2++;
}

void		create_map(t_game *pos, char **argv)
{
	char	*line;
	int		i;
	int		fd;
	if (checker(pos->checking) &&
	pos->control_map == 1)
	{
	if (!(pos->map = (char **)malloc(pos->rows * sizeof(char *))))
		return_error (4);
	i = 0;
	while (i < pos->rows)
	{
		if (!(pos->map[i] = (char *)malloc(pos->columns * sizeof(char) + 1)))
			return_error (4);
		i++;
	}
	if (!(pos->sprites = (t_sprite *)malloc(sizeof(t_sprite) * pos->spritecount)))
		return_error (4);
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
		return_error (11);
}
