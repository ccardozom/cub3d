/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:43:51 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/21 11:40:46 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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