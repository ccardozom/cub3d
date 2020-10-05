/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 10:40:00 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/01 10:46:16 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	is_map(char *line, t_game *pos)
{
	int index;

	if (pos->control == 8)
	{
		index = ft_strlen(line);
		if (pos->columns < index)
			pos->columns = index;
		pos->rows++;
	}
}