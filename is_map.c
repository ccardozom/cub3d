/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 10:40:00 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/20 14:05:19 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	is_map(char *line, t_game *pos)
{
	int index;
	int control_map;

	control_map = 0;
	if (pos->control == 8 && *line != '\0')
	{
		index = ft_strlen(line);
		if (pos->columns < index)
			pos->columns = index;
		pos->rows++;
		control_map = 1;
	}
	if (control_map == 1 && line == '\0')
		return_error();
}
