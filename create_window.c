/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:31:50 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/21 09:43:22 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	create_window(t_pos_py *pos)
{
	mlx = mlx_init();

	mlx_win = mlx_new_window(mlx, pos->plane_x, pos->plane_y, "CUB3D");
}