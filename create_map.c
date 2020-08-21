/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 10:02:03 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/21 11:40:40 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		create_map(t_game *pos)
{
	char	*line;
	int		i;

	pos->map = (char **)malloc(pos->rows * sizeof(char *));
	i = 0;
	while (i < pos->rows)
	{
		pos->map[i] = (char *)malloc(pos->columns * sizeof(char) + 1);
		i++;
	}
	fill_matriz(pos);
	imprimir_matriz(pos);
	open_file();
	while (get_next_line(fd, &line) == 1)
	{
		create_matriz(line, pos);
	}
	create_matriz(line, pos);
	imprimir_matriz(pos);
	
	free(line);
}
