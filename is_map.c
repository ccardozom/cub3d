/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 10:40:00 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/30 13:16:45 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	is_map(char *line, t_game *pos)
{
	int index;
	index = ft_strlen(line);
	if (line[index] == '\0' && line[index - 1] != '1')
		return_error();
	if (pos->columns < index)
		pos->columns = index;
	pos->rows++;
}