/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 09:36:44 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/17 10:11:46 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

char		*control_space_final(char *line)
{
	if (ft_isdigit(*line) == 0 && *line != '\0')
		while (ft_isdigit(*line) == 0 && *line != '\0')
			line++;
	if ((*line == ' ' || *line == '\t' ||
	ft_isdigit(*line) == 0) && *line != '\0')
		while ((*line == ' ' || *line == '\t' ||
		ft_isdigit(*line) == 0) && *line != '\0')
			line++;
	return (line);
}

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
	if (color->r == -1 || color->g == -1 || color->b == -1)
	{
		ft_putstr_fd("Error\n Faltan datos del juego", 1);
		exit(0);
	}
}

void		resolution(char *line, t_game *pos)
{
	if (*line == 'R')
	{
		line = control_space_final(line);
		if (*line == '\0')
			return_error(11);
		pos->winres.x = ft_atoi(line);
		line = control_space_final(line);
		while (ft_isdigit(*line) == 1)
			line++;
		line++;
		line = control_space_final(line);
		pos->winres.y = ft_atoi(line);
		while (ft_isdigit(*line) == 1)
			line++;
		while (*line != '\0')
		{
			if (*line != ' ' || *line == '\t')
				return_error(13);
			line++;
		}
		if (!(pos->winres.x) || !(pos->winres.y))
			return_error(11);
		pos->checking[0] = 1;
	}
}

void		check_line(char *line, t_game *pos)
{
	while (*line == ' ' || *line == '\t')
		line++;
	resolution(line, pos);
	path_texture_n(pos, line);
	path_texture_s(pos, line);
	path_texture_o(pos, line);
	path_texture_e(pos, line);
	path_texture_sp(pos, line);
	if (ft_strchr(line, 'F'))
	{
		pos->checking[6] = 1;
		get_colors((char*)line, &pos->texture.floor, 'F');
	}
	else if (ft_strchr(line, 'C'))
	{
		pos->checking[7] = 1;
		get_colors((char*)line, &pos->texture.ceilling, 'C');
	}
	else if (search_wall(pos, line))
		is_map(line, pos);
	if (pos->control_map == 0)
		pos->line_count1++;
}

void		read_map(t_game *pos, char **argv)
{
	char	*line;
	int		fd;
	int		i;

	fd = open_file(argv);
	reset_position(pos);
	i = 0;
	while (pos->checking[i])
	{
		pos->checking[i] = 0;
		i++;
	}
	pos->checking[i] = '\0';
	while (get_next_line(fd, &line) == 1)
	{
		check_line(line, pos);
		free(line);
	}
	check_line(line, pos);
	if (pos->control_line_empty == 0)
		return_error(3);
	free(line);
	close(fd);
}
