/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 09:36:44 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/14 12:35:27 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void read_mapa(int fd, t_pos_py *pos)
{
	
	int user;
	int index_i;
	int index_j;
	char buffer[100];
	char *temp;
	size_t nr_bytes;

	user = 0;
	nr_bytes = read(fd, buffer, 100);
	buffer[nr_bytes] = 0;
	index_i = 0;
	while (buffer[index_i] != '\0')
	{
		if (buffer[index_i] == 'R' && buffer[index_i + 1] == ' ')
		{
			resolution(buffer, pos, index_i + 2);
		}
		if (buffer[index_i] == '\n')
		{
			if (index_i > pos->plane_x)
				pos->plane_x = index_i;
			index_j++;
			printf(" (salto de linea) ");
		}
		if (buffer[index_i] == 'N')
		{
			pos->pos_x = index_i;
			pos->pos_y = index_j;
			user = 1;
		}
		printf("%c", buffer[index_i]);
		index_i++;
	}
	if (user == 1)
		printf("existe usuario");
	
}





