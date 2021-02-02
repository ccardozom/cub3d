/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 10:02:03 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/27 14:20:58 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	put_value_in_matriz(t_game *pos, char *line)
{
	if (line[(int)pos->matriz.x] == '1' ||
	line[(int)pos->matriz.x] == '2' ||
	player(line[(int)pos->matriz.x]) == 0 ||
	line[(int)pos->matriz.x] == '0' ||
	line[(int)pos->matriz.x] == ' ')
	{
		if (line[(int)pos->matriz.x] == '2')
		{
			pos->sp[pos->spritecount_aux].pos.x = (pos->matriz.x *
			(int)pos->tile.size) + ((int)pos->tile.size / 2);
			pos->sp[pos->spritecount_aux++].pos.y = (pos->matriz.y *
			(int)pos->tile.size) + ((int)pos->tile.size / 2);
		}
		if (line[(int)pos->matriz.x] == ' ')
			pos->map[(int)pos->matriz.y][(int)pos->matriz.x] = '8';
		else
			pos->map[(int)pos->matriz.y][(int)pos->matriz.x] =
			line[(int)pos->matriz.x];
		if (player(line[(int)pos->matriz.x]) == 0)
			pos->checkplayer += 1;
	}
	else
		return_error(15);
}

void	new_matriz(t_game *pos, char *line)
{
	int	check_end_line;

	check_end_line = 0;
	while ((int)pos->matriz.x < pos->columns)
	{
		if (line[(int)pos->matriz.x] == '\0')
			check_end_line = 1;
		if (check_end_line == 0)
		{
			put_value_in_matriz(pos, line);
		}
		else
		{
			pos->map[(int)pos->matriz.y][(int)pos->matriz.x] =
			'8';
		}
		pos->matriz.x++;
	}
	pos->map[(int)pos->matriz.y][(int)pos->matriz.x] = '\0';
	pos->matriz.x = 0;
	pos->matriz.y++;
}

void	create_matriz(char *line, t_game *pos)
{
	pos->tile.size = pos->winres.x / pos->columns;
	if ((pos->line_count2 == pos->line_count1) && *line != '\0')
		new_matriz(pos, line);
	if (pos->line_count2 != pos->line_count1)
		pos->line_count2++;
}

void	reserv_mem_map(t_game *pos)
{
	int i;

	if (!(pos->map = (char **)malloc(pos->rows * sizeof(char *) + 1)))
		return_error(4);
	ft_memset(pos->map, 0, pos->rows * sizeof(char *) + 1);
	i = 0;
	while (i < pos->rows)
	{
		if (!(pos->map[i] = malloc((pos->columns + 1) * sizeof(char *) + 1)))
			return_error(4);
		ft_memset(pos->map[i], '8', (pos->columns + 1) * sizeof(char *) + 1);
		i++;
	}
}

void	create_map(t_game *pos, char **argv)
{
	char	*line;
	int		fd;

	if (checker(pos->checking) && pos->control_map == 1)
	{
		reserv_mem_map(pos);
		if (!(pos->sp = malloc(sizeof(t_sprite) * pos->sp_count + 1)))
			return_error(4);
		ft_memset(pos->sp, 0, sizeof(t_sprite) * pos->sp_count + 1);
		fd = open_file(argv);
		while (get_next_line(fd, &line) == 1)
		{
			reset_sprites(pos);
			create_matriz(line, pos);
			free(line);
		}
		create_matriz(line, pos);
		free(line);
		close(fd);
	}
	else
		return_error(11);
}
