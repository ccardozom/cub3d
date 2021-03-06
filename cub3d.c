/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:00:58 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/27 14:21:02 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int		program_exit(t_game *all)
{
	mlx_destroy_window(all->mlx, all->mlx_win);
	exit(0);
}

int		main_loop(t_game *pos)
{
	if (pos->player.walk || pos->player.turn || pos->player.l_r ||
	pos->first_frame == 0)
	{
		mlx_clear_window(pos->mlx, pos->mlx_win);
		mlx_destroy_image(pos->mlx, pos->img.img);
		update_player(pos);
		pos->img.img = mlx_new_image(pos->mlx,
		pos->winres.x,
		pos->winres.y);
		pos->img.addr = mlx_get_data_addr(pos->img.img,
		&pos->img.bits_per_pixel,
		&pos->img.line_length,
		&pos->img.endian);
		cast_all_rays(pos);
		generate_3dprojection(pos);
		draw_minimap(pos);
		sprites(pos);
		mlx_put_image_to_window(pos->mlx, pos->mlx_win, pos->img.img, 0, 0);
		free(pos->ray_data);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_game	pos;

	if (argc < 2 || argc > 3)
		return_error(1);
	if (ft_strsearch(argv[1], ".cub"))
		initialize(&pos, argv);
	else
		return_error(2);
	if (argv[2])
	{
		if (ft_strcmp(argv[2], "--save") == 0)
			save_bmp(&pos);
		else
			return_error(10);
	}
	else if (ft_strsearch(argv[1], ".cub") == 1 && !(argv[2]))
	{
		start(&pos);
		mlx_hook(pos.mlx_win, 2, 0, &key_press, &pos);
		mlx_hook(pos.mlx_win, 17, 0, &program_exit, &pos);
		mlx_hook(pos.mlx_win, 3, 0, &key_release, &pos);
		mlx_loop_hook(pos.mlx, &main_loop, &pos);
		mlx_loop(pos.mlx);
	}
	return (0);
}
