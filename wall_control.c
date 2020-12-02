/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:44:27 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/02 11:42:27 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int	search_wall(t_game *pos, char *line)
{
	int index;

	index = 0;
	while (line[index] != '\0')
	{
		if (line[index] == '1' || line[index] == '0' ||
			line[index] == '2' || line[index] == 'N' || line[index] == ' ' ||
			line[index] == 'W' || line[index] == 'S' || line[index] == 'E')
			index++;
		else
			return (0);
	}
	if (*line != '\0')
		pos->control_map = 1;
	else
	{
		if (pos->control_map == 1)
			return_error (3);
		return (0);
	}
	return (1);
}