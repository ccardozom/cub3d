/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 10:40:00 by ccardozo          #+#    #+#             */
/*   Updated: 2020/11/26 08:46:11 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	is_map(char *line, t_game *pos)
{
	int index;

	if (pos->control == 8 && *line != '\0')
	{
		index = ft_strlen(line);
		if (pos->columns < index)
			pos->columns = index;
		index = 0;
		while (line[index] != '\0')
		{
			if (line[index] == '2')
				pos->spritecount += 1;
			index++;
		}
		pos->rows++;
		pos->control_map = 1;
	}
	if (pos->control_map == 1 && *line == '\0')
		return_error(3);
}
