/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:00:58 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/23 13:18:44 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int main()
{
	
	//t_data 		img;
	t_pos_py	pos;
	//t_tile		tile;
	
	open_file();
	read_map(&pos);
	close(fd);
	create_map(&pos);
	wall_control(pos.map, pos.rows);
	//create_window(&pos, &img);
	//draw_map(&pos, &img, &tile);
	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	//mlx_loop(mlx);
	
	return (0);
}