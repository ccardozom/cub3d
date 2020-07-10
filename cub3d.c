/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:00:58 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/08 13:22:18 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int main()
{
	int fd;
	void    *mlx;
	void	*img;
    

    mlx = mlx_init();

	img = mlx_new_image(mlx, 1920, 1080);
  

	mlx = mlx_init();

	if (!(fd = open ("map.cub", O_RDONLY)))
		return (-1);
	
	read_mapa(fd);

}