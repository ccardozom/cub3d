/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:40:23 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/21 11:39:37 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	resolution(char *line, t_game *pos, int ptr)
{
	int index;

	check_resolution = 1;
	index = ptr + 1;
	while (ft_isdigit(line[index]) == 0)
		index++;
	pos->winres.x=ft_atoi(&line[index]);

	while (ft_isdigit(line[index]) == 1)
		index++;
	index++;
	while (ft_isdigit(line[index]) == 0)
		index++;
	pos->winres.y=ft_atoi(&line[index]);	
}