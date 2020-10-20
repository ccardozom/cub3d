/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:54:27 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/20 14:05:19 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	path_texture_n(t_game *pos, char *line)
{
	int index;

	index = 0;
	while (line[index] == ' ')
		index++;
	if (line[index] == 'N' && line[index + 1] == 'O')
	{
		pos->control += 1;
		while (*line == ' ' || *line == 'N' || *line == 'O')
			line++;
		pos->texture.north_text.path = ft_strdup(line);
	}
}

void	path_texture_s(t_game *pos, char *line)
{
	int index;

	index = 0;
	while (line[index] == ' ')
		index++;
	if (line[index] == 'S' && line[index + 1] == 'O')
	{
		pos->control += 1;
		while (*line == ' ' || *line == 'S' || *line == 'O')
			line++;
		pos->texture.south_text.path = ft_strdup(line);
	}
}

void	path_texture_o(t_game *pos, char *line)
{
	int index;

	index = 0;
	while (line[index] == ' ')
		index++;
	if (line[index] == 'W' && line[index + 1] == 'E')
	{
		pos->control += 1;
		while (*line == ' ' || *line == 'W' || *line == 'E')
			line++;
		pos->texture.weast_text.path = ft_strdup(line);
	}
}

void	path_texture_e(t_game *pos, char *line)
{
	int index;

	index = 0;
	while (line[index] == ' ')
		index++;
	if (line[index] == 'E' && line[index + 1] == 'A')
	{
		pos->control += 1;
		while (*line == ' ' || *line == 'E' || *line == 'A')
			line++;
		pos->texture.east_text.path = ft_strdup(line);
	}
}

void	path_texture_sp(t_game *pos, char *line)
{
	int index;

	index = 0;
	while (line[index] == ' ')
		index++;
	if (line[index] == 'S' && line[index + 1] != 'O')
	{
		pos->control += 1;
		while (*line == ' ' || *line == 'S')
			line++;
		pos->texture.sprite.path = ft_strdup(line);
	}
}
