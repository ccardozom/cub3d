/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 11:54:27 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/07 16:05:40 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	path_texture_n(t_game *pos, char *line, int i)
{
	int len;
	int cont;

	while (line[i] == ' ')
		i++;
	len = ft_strlen(&line[i]);
	pos->texture.north_text.path = NULL;
	pos->texture.north_text.path = (char *)malloc(sizeof(char)*len);
	cont = 0;
	while (line[i] != ' ' && line[i] != '\0')
	{
		pos->texture.north_text.path[cont] = line[i];
		cont++;
		i++;
	}
	pos->texture.north_text.path[cont] = '\0';
}

void	path_texture_s(t_game *pos, char *line, int i)
{
	int len;
	int cont;

	while (line[i] == ' ')
		i++;
	len = ft_strlen(&line[i]);
	pos->texture.south_text.path = NULL;
	pos->texture.south_text.path = (char *)malloc(sizeof(char)*len);
	cont = 0;
	while (line[i] != ' ' && line[i] != '\0')
	{
		pos->texture.south_text.path[cont] = line[i];
		cont++;
		i++;
	}
	pos->texture.south_text.path[cont] = '\0';
}

void	path_texture_e(t_game *pos, char *line, int i)
{
	int len;
	int cont;

	while (line[i] == ' ')
		i++;
	len = ft_strlen(&line[i]);
	pos->texture.east_text.path = NULL;
	pos->texture.east_text.path = (char *)malloc(sizeof(char)*len);
	cont = 0;
	while (line[i] != ' ' && line[i] != '\0')
	{
		pos->texture.east_text.path[cont] = line[i];
		cont++;
		i++;
	}
	pos->texture.south_text.path[cont] = '\0';
}

void	path_texture_o(t_game *pos, char *line, int i)
{
	int len;
	int cont;

	while (line[i] == ' ')
		i++;
	len = ft_strlen(&line[i]);
	pos->texture.weast_text.path = NULL;
	pos->texture.weast_text.path = (char *)malloc(sizeof(char)*len);
	cont = 0;
	while (line[i] != ' ' && line[i] != '\0')
	{
		pos->texture.weast_text.path[cont] = line[i];
		cont++;
		i++;
	}
	pos->texture.south_text.path[cont] = '\0';
}

void	path_texture_sp(t_game *pos, char *line, int i)
{
	int len;
	int cont;

	while (line[i] == ' ')
		i++;
	len = ft_strlen(&line[i]);
	pos->texture.sprite.path = NULL;
	pos->texture.sprite.path = (char *)malloc(sizeof(char)*len);
	cont = 0;
	while (line[i] != ' ' && line[i] != '\0')
	{
		pos->texture.sprite.path[cont] = line[i];
		cont++;
		i++;
	}
	pos->texture.sprite.path[cont] = '\0';
}