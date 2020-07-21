/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 10:02:03 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/21 12:48:55 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		create_map(t_pos_py *pos)
{
	char	*line;
	int		i;

	pos->map = (char **)malloc(pos->map_f * sizeof(char *));
	i = 0;
	while (i < pos->map_f)
	{
		pos->map[i] = (char *)malloc(pos->map_c * sizeof(char) + 1);
		i++;
	}
	fill_matriz(pos);
	fd = open_file();
	while (get_next_line(fd, &line) == 1)
	{
		create_matriz(line, pos);
	}
	free(line);
}
