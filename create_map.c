/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 10:02:03 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/20 14:20:07 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void		create_map(t_game *pos)
{
	char	*line;
	int		i;
	int		fd;

	pos->map = (char **)malloc(pos->rows * sizeof(char *));
	i = 0;
	while (i < pos->rows)
	{
		pos->map[i] = (char *)malloc(pos->columns * sizeof(char) + 1);
		i++;
	}
	fd = open_file();
	while (get_next_line(fd, &line) == 1)
	{
		create_matriz(line, pos);
	}
	create_matriz(line, pos);
	free(line);
}
