/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 10:02:03 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/01 11:35:37 by ccardozo         ###   ########.fr       */
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
			{
				if (line[(int)pos->matriz.x] == '2')
				{
					pos->sprites[pos->spritecount_aux].pos.x = (pos->matriz.x * pos->tile.size) + (pos->tile.size / 2);
					pos->sprites[pos->spritecount_aux++].pos.y = (pos->matriz.y * pos->tile.size) + (pos->tile.size / 2);
				}
				pos->map[(int)pos->matriz.y][(int)pos->matriz.x] =
				line[(int)pos->matriz.x];
			}
		pos->matriz.x++;
	}
	pos->matriz.x = 0;
	pos->matriz.y++;
}

void		create_matriz(char *line, t_game *pos)
{
	int		index;

	index = 0;
	while (line[index] == ' ')
		index++;
	if (line[index] == 'R')
		pos->control = 1;
	else if (line[index] == 'N' && line[index + 1] == 'O')
		pos->control += 1;
	else if (line[index] == 'S' && line[index + 1] == 'O')
		pos->control += 1;
	else if (line[index] == 'W' && line[index + 1] == 'E')
		pos->control += 1;
	else if (line[index] == 'E' && line[index + 1] == 'A')
		pos->control += 1;
	else if (line[index] == 'S')
		pos->control += 1;
	else if (ft_strchr(line, 'F'))
		pos->control += 1;
	else if (ft_strchr(line, 'C'))
		pos->control += 1;
	else if (pos->control == 8 && *line != '\0')
		new_matriz(pos, line);
}

void		create_map(t_game *pos, char **argv)
{
	char	*line;
	int		i;
	int		fd;
	if (pos->control == 8 && pos->control_map == 1)
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
