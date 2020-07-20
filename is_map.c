/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 10:40:00 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/20 13:16:00 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	is_map(char *line, t_pos_py *pos)
{
	int index;
	
	index = ft_strlen(line);
	if (pos->map == NULL)
	{
		pos->map = ft_strdup(line);
	}
	else
	{
		pos->map = ft_strjoin(pos->map, line);
	}
	
	if (pos->map_c < index)
		pos->map_c = index;
	pos->map_f++;
}