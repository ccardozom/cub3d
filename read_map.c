/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 09:36:44 by ccardozo          #+#    #+#             */
/*   Updated: 2020/11/26 12:42:24 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void		get_colors(char *line, t_color *color, char param)
{
	color->empty = 0;
	while (*line == ' ' || *line == param)
		line++;
	color->r = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ' || *line == ',')
		line++;
	color->g = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ' || *line == ',')
		line++;
	color->b = ft_atoi(line);
}

void		resolution(char *line, t_game *pos)
{
	while (*line == ' ')
		line++;
	if (*line == 'R')
	{	pos->control = 1;
		line++;
		while (ft_isdigit(*line) == 0)
			line++;
		pos->winres.x = ft_atoi(line);
		while (ft_isdigit(*line) == 1)
			line++;
		line++;
		while (ft_isdigit(*line) == 0)
			line++;
		pos->winres.y = ft_atoi(line);
	}
	if (!(pos->winres.x) || !(pos->winres.y))
		return_error (11);
}

void		check_line(char *line, t_game *pos)
{
	int index;

	index = 0;
	while (line[index] == ' ')
		index++;
	resolution(line, pos);
	path_texture_n(pos, line);
	path_texture_s(pos, line);
	path_texture_o(pos, line);
	path_texture_e(pos, line);
	path_texture_sp(pos, line);
	if (ft_strchr(line, 'F'))
	{
		pos->control += 1;
		get_colors((char*)line, &pos->texture.floor, 'F');
	}
	else if (ft_strchr(line, 'C'))
	{
		pos->control += 1;
		get_colors((char*)line, &pos->texture.ceilling, 'C');
	}
	else if (pos->control == 8)
		is_map(line, pos);
}

void		read_map(t_game *pos, char **argv)
{
	char	*line;
	int		fd;

	fd = open_file(argv);
	reset_position(pos);
	while (get_next_line(fd, &line) == 1)
	{
		check_line(line, pos);
		free(line);
	}
	check_line(line, pos);
	free(line);
	close(fd);
}
