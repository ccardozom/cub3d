/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:46:20 by ccardozo          #+#    #+#             */
/*   Updated: 2020/10/20 14:05:19 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int		open_file(void)
{
	int fd;

	fd = open("map.cub", O_RDONLY);
	if (!fd || fd < 0)
	{
		return_error();
	}
	return (fd);
}
