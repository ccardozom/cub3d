/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:00:58 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/20 09:59:41 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//#include "position_player.c"
// #include "reset_position.c"
// #include "resolution.c"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	
	t_data 	image;
	t_pos_py	pos;
	//int		offset;

	fd = open ("map.cub", O_RDONLY);
	if (!fd || fd < 0)
	{
		printf("\033[1;31mCould not open file %s\n", "map.cub"); 
		return 0; 
	}
	
	
	
	//reset_position(&pos);
	read_map(fd, &pos);
	
	mlx = mlx_init();

	mlx_win = mlx_new_window(mlx, pos.plane_x, pos.plane_y, "Pintando Pixel");
	
	image.img = mlx_new_image(mlx, pos.plane_x, pos.plane_y);

	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	
	//position_player(&pos);
	
	my_mlx_pixel_put(&image, 500, 500, 0x4169e1);

	mlx_put_image_to_window(mlx, mlx_win, image.img, 50, 50);
	
	// offset = (pos.pos_y * image.line_length + pos.pos_x * (image.bits_per_pixel / 8));

	mlx_loop(mlx);

	

}