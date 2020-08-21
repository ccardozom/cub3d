/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:31:50 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/21 11:48:13 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	create_window(t_game *pos, t_data *img)
{
	mlx = mlx_init();

	mlx_win = mlx_new_window(mlx, pos->winres.x, pos->winres.y, "CUB3D");
	img->img = mlx_new_image(mlx, pos->winres.x, pos->winres.y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,&img->endian);
}