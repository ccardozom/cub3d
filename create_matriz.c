/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matriz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 10:10:36 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/20 14:05:19 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void		create_matriz(char *line, t_game *pos)
{
	int		index;

	index = 0;
	while (line[index] == ' ')
		index++;
	if (line[index] == 'R')
		pos->control = 1;
	else if (line[index] == 'N' && line[index + 1] == 'O')
		pos->control += 1;
	else if (line[index] == 'S' && line[index + 1] == 'O')
		pos->control += 1;
	else if (line[index] == 'W' && line[index + 1] == 'E')
		pos->control += 1;
	else if (line[index] == 'E' && line[index + 1] == 'A')
		pos->control += 1;
	else if (line[index] == 'S')
		pos->control += 1;
	else if (ft_strchr(line, 'F'))
		pos->control += 1;
	else if (ft_strchr(line, 'C'))
		pos->control += 1;
	else if (pos->control == 8 && *line != '\0')
		new_matriz(pos, line);
}
