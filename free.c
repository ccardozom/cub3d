/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:39:42 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/21 08:37:03 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	free_map(t_game *pos)
{
	int		i;

	i = 0;
	while (i < pos->rows)
	{
		if (pos->map[i])
			free(pos->map[i]);
		i++;
	}
	if (pos->map)
	{
		free(pos->map);
		pos->map = NULL;
	}
}

void	free_all(t_game *pos)
{
	
	/*if (pos->sp)
	{
		free(pos->sp);
		pos->sp = NULL;
	}*/
	//free(pos->sp);
	//pos->sp = NULL;
	free(pos->ray_data);
	pos->ray_data = NULL;
	
}
