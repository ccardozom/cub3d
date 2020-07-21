/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 09:36:44 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/21 12:58:14 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		read_map(int fd, t_pos_py *pos)
{
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		check_line(line, pos);
	}
	free(line);
}
