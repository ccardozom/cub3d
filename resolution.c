/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:40:23 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/21 09:40:24 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	resolution(char *line, t_pos_py *pos, int ptr)
{
	int index;

	index = ptr + 1;
	while (ft_isdigit(line[index]) == 0)
		index++;
	pos->plane_x=ft_atoi(&line[index]);

	while (ft_isdigit(line[index]) == 1)
		index++;
	index++;
	while (ft_isdigit(line[index]) == 0)
		index++;
	pos->plane_y=ft_atoi(&line[index]);
	
}