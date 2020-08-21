/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matriz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 10:10:36 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/21 11:40:52 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		create_matriz(char *line, t_game *pos)
{
	int		index;

	index = 0;
	while (line[index] == ' ')
		index++;
	if (ft_isalpha(line[index]) == 0)
		{	
			new_matriz(pos,line);
		}
}
