/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 09:36:44 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/01 13:34:49 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_colors(char *line, t_color *color, char param)
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

void	resolution(char *line, t_game *pos, int ptr)
{
	int index;

	index = ptr + 1;
	while (ft_isdigit(line[index]) == 0)
		index++;
	pos->winres.x=ft_atoi(&line[index]);

	while (ft_isdigit(line[index]) == 1)
		index++;
	index++;
	while (ft_isdigit(line[index]) == 0)
		index++;
	pos->winres.y=ft_atoi(&line[index]);	
}

void	check_line(char *line, t_game *pos)
{
	int index;

	index = 0;
	while (line[index] == ' ')
		index++;
	if (line[index] == 'R')
		{
			resolution(line, pos, index);
			pos->control = 1;
		}
	else if (line[index] == 'N' && line[index + 1] == 'O')
	{
		pos->control += 1;
		path_texture_n(pos, line, index + 2);
	}
	else if (line[index] == 'S' && line[index + 1] == 'O')
	{
		pos->control += 1;
		path_texture_s(pos, line, index + 2);
	}
	else if (line[index] == 'W' && line[index + 1] == 'E')
	{
		pos->control += 1;
		path_texture_o(pos, line, index + 2);
	}
	else if (line[index] == 'E' && line[index + 1] == 'A')
	{
		pos->control += 1;
		path_texture_e(pos, line, index + 2);
	}
	else if (line[index] == 'S')
	{
		pos->control += 1;
		path_texture_s(pos, line, index + 1);
	}
	else if (ft_strchr(line, 'F'))
	{
		get_colors((char*)line, &pos->texture.floor, 'F');
		pos->control += 1;
	}
	else if (ft_strchr(line, 'C'))
		{
			get_colors((char*)line, &pos->texture.ceilling, 'C');
			pos->control += 1;
		}
	else
	{
		is_map(line, pos);
	}
}

void		read_map(t_game *pos)
{
	char	*line;
	int fd;
	
	fd = open_file();
	reset_position(pos);
	while (get_next_line(fd, &line) == 1)
	{
		check_line(line, pos);
	}
	check_line(line, pos);
	free(line);
	close(fd);
}
