/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:54:27 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/17 08:44:54 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	path_texture_n(t_game *pos, char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == 'N' && *(++line) == 'O')
	{
		pos->texture.check_n += 1;
		if (pos->texture.check_n != 1)
			return_error(15);
		line++;
		while ((*line == ' ' || *line == '\t') && *line != '\0')
			line++;
		if (*line == '\0')
			return_error(11);
		pos->texture.north_text.path = ft_strdup(line);
		pos->checking[1] = 1;
	}
}

void	path_texture_s(t_game *pos, char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == 'S' && *(++line) == 'O')
	{
		pos->texture.check_s += 1;
		if (pos->texture.check_s != 1)
			return_error(15);
		line++;
		while ((*line == ' ' || *line == '\t') && *line != '\0')
			line++;
		if (*line == '\0')
			return_error(11);
		pos->texture.south_text.path = ft_strdup(line);
		pos->checking[2] = 1;
	}
}

void	path_texture_o(t_game *pos, char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == 'W' && *(++line) == 'E')
	{
		pos->texture.check_o += 1;
		if (pos->texture.check_o != 1)
			return_error(15);
		line++;
		while ((*line == ' ' || *line == '\t') && *line != '\0')
			line++;
		if (*line == '\0')
			return_error(11);
		pos->texture.weast_text.path = ft_strdup(line);
		pos->checking[3] = 1;
	}
}

void	path_texture_e(t_game *pos, char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == 'E' && *(++line) == 'A')
	{
		pos->texture.check_e += 1;
		if (pos->texture.check_e != 1)
			return_error(15);
		line++;
		while ((*line == ' ' || *line == '\t') && *line != '\0')
			line++;
		if (*line == '\0')
			return_error(11);
		pos->texture.east_text.path = ft_strdup(line);
		pos->checking[4] = 1;
	}
}

void	path_texture_sp(t_game *pos, char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == 'S' && *(++line) != 'O')
	{
		pos->texture.check_sp += 1;
		if (pos->texture.check_sp != 1)
			return_error(15);
		line++;
		while ((*line == ' ' || *line == '\t') && *line != '\0')
			line++;
		if (*line == '\0')
			return_error(11);
		pos->texture.sprite.path = ft_strdup(line);
		pos->checking[5] = 1;
	}
}
