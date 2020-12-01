/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:44:27 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/01 14:47:42 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int	search_wall(t_game *pos, char *line, char wall)
{
	int check;

	check = 0;
	while (*line)
	{
		if ((unsigned char)*line != (unsigned char)wall && ft_isalpha(*line) == 0)
			line++;
		else if (checker(pos->checking))
		{	
			return (1);
		}
	}
	return (0);
}