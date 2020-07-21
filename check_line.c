/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:43:51 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/21 09:37:52 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_line(char *line, t_pos_py *pos)
{
	int index;

	index = 0;
	while (ft_isalpha(line[index]) == 0 && ft_isdigit(line[index]) == 0)
		index++;
	if (line[index] == 'R')
	{
		resolution(line, pos, index);
	}
	else if (ft_isdigit(line[index]))
	{
		is_map(line, pos);
	}
	
	
}