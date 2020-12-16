/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:39:42 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/16 09:51:02 by ccardozo         ###   ########.fr       */
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
	if (pos)
		free_map(pos);
	if (pos->sprites)
	{
		free(pos->sprites);
		pos->sprites = NULL;
	}
}
