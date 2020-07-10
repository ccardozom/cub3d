/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 09:36:44 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/08 10:06:52 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void read_mapa(int fd)
{
	
	int user;
	int index;
	char buffer[100];
	char *temp;
	size_t nr_bytes;

	user = 0;
	nr_bytes = read(fd, buffer, 100);
	buffer[nr_bytes] = 0;
	index = 0;
	while (buffer[index] != '\0')
	{
		if (buffer[index] == '\n')
			printf(" (salto de linea) ");
		if (buffer[index] == 'N')
			user = 1;
		printf("%c", buffer[index]);
		index++;
	}
	if (user == 1)
		printf("existe usuario");

}





