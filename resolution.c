/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:40:23 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/03 12:58:53 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	resolution(char *line, t_game *pos, int ptr)
{
	int index;

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