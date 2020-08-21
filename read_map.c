/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 09:36:44 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/21 11:41:39 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		read_map(t_game *pos)
{
	char	*line;
	
	open_file();
	reset_position(pos);
	while (get_next_line(fd, &line) == 1)
	{
		check_line(line, pos);
	}
	check_line(line, pos);
	free(line);
	close(fd);
}
