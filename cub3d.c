/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:00:58 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/21 13:11:56 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		main_loop(t_game *pos)
{
	mlx_clear_window(mlx, mlx_win);
	//update_player(pos);
	pos->img.img = mlx_new_image(mlx, pos->winres.x, pos->winres.y);
	pos->img.addr = mlx_get_data_addr(pos->img.img,
	&pos->img.bits_per_pixel,
	&pos->img.line_length,
	&pos->img.endian);
	draw_minimap(pos);
	draw_player(pos);
	mlx_put_image_to_window(mlx, mlx_win, pos->img.img, 0, 0);
	mlx_destroy_image(mlx, pos->img.img);

	return(0);
}

int main()
{
	t_game	pos;
	
	initialize(&pos);
	//wall_control(pos.map, pos.rows, pos.columns);
	start(&pos);
	
	mlx_hook(mlx_win, 2, 0, &key_press, &pos);
	mlx_hook(mlx_win, 3, 0, &key_release, &pos);
	mlx_loop_hook(mlx, &main_loop, &pos);
	//mlx_destroy_window(mlx, mlx_win);
	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}