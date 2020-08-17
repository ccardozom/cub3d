/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 11:13:36 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/17 12:08:42 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	start(t_pos_py *pos)
{
	t_data		img;
	int	i;
	i = pos->columns;

	void	*mlx;
	void	*mlx_win;
	
	mlx = mlx_init();
	img.img = mlx_new_image(mlx, pos->winres_x, pos->winres_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	mlx_win = mlx_new_window(mlx, pos->winres_x, pos->winres_y, "Cub3D");
	mlx_loop(mlx);
}