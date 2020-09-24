/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:00:58 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/24 18:02:11 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	update(t_game *pos)
{
	update_player(pos);
	cast_all_rays(pos);
}

int		main_loop(t_game *pos)
{
	mlx_clear_window(pos->mlx, pos->mlx_win);
	update(pos);
	pos->img.img = mlx_new_image(pos->mlx,
	pos->winres.window_width,
	pos->winres.window_height);
	pos->img.addr = mlx_get_data_addr(pos->img.img,
	&pos->img.bits_per_pixel,
	&pos->img.line_length,
	&pos->img.endian);
	draw_minimap(pos);
	//draw(pos);
	mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->img.img, 0, 0);
	mlx_destroy_image(pos->mlx, pos->img.img);
	free(pos->ray_data);
	return (0);
}

int		main(void)
{
	t_game	pos;

	initialize(&pos);
	start(&pos);
	mlx_hook(pos.mlx_win, 2, 0, &key_press, &pos);
	mlx_hook(pos.mlx_win, 3, 0, &key_release, &pos);
	mlx_loop_hook(pos.mlx, &main_loop, &pos);
	mlx_loop(pos.mlx);
	return (0);
}
