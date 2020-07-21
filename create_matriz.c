/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matriz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 10:10:36 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/21 13:34:48 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		create_matriz(char *line, t_pos_py *pos)
{
	int		index;
	int		prueba;
	int		f;
	//int		columnas;

	index = 0;
	//filas = 0;
	if (ft_isalpha(line[index]) == 1)
		return_error(-1);
	else
		{	
			while (ft_isalpha(line[index]) == 0 && ft_isdigit(line[index]) == 0)
				index++;
			if (ft_isalnum(line[index]) == 1 || ft_isalnum(line[index]) == 0)
			{
				new_matriz(pos,line);
			}
		}
}
