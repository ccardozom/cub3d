/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:46:20 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/27 14:21:42 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int		open_file(char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (!fd || fd < 0)
	{
		return_error(2);
	}
	return (fd);
}
