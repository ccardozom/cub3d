/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 09:36:44 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/24 09:50:06 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


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
		resolution(line, pos, index);
	else if (line[index] == 'N' && line[index + 1] == 'O')
	{}
	else if (line[index] == 'S' && line[index + 1] == 'O')
	{}
	else if (line[index] == 'W' && line[index + 1] == 'E')
	{}
	else if (line[index] == 'E' && line[index + 1] == 'A')
	{}
	else if (line[index] == 'S')
	{}
	else if (line[index] == 'F')
	{}
	else if (line[index] == 'C')
	{}
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
