/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 10:37:44 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/23 13:16:02 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		tile_size(t_pos_py *pos)
{
	int	size;

	size = pos->plane_x / pos->map_c;

	return (size);
}

void    draw_map(t_pos_py *pos, t_data *image, t_tile *tile)
{

	
    while (tile->y < pos->map_f)
    {

        tile->x = 0;
        tile->pos_x = 0;
        while (tile->x < pos->map_c)
		{

            tile->pos_x += assign_pixel(tile->x++, tile, image,pos);
		}
		tile->pos_y++;
        tile->pos_sy++;
        if (tile->pos_sy >= tile_size(pos))
        {
            tile->y++;
            tile->pos_sy = 0;
        }
    }
}

int     assign_pixel(int x, t_tile *tile, t_data *image, t_pos_py * pos)
{

    int     pos_sx;
    pos_sx = 0;
    while (pos_sx < tile_size(pos))
    {
        if (pos->map[tile->y][x] == 1)
            my_mlx_pixel_put(pos, image, tile->pos_x, tile->pos_y, 0x6400);
        else if (pos->map[tile->y][x] == 0)
            my_mlx_pixel_put(pos, image, tile->pos_x, tile->pos_y, 0x0);
        /*else if (map[y][x] == 2)
            my_mlx_pixel_put(pos_x, pos_y, 255);*/
        else
            my_mlx_pixel_put(pos, image, tile->pos_x, tile->pos_y, 0x0);
        pos_sx++;
        tile->pos_x++;
    }
    return(tile_size(pos));
}

void    my_mlx_pixel_put(t_pos_py *pos, t_data *image, int x, int y, int color)
{
    char    *dst;
    dst = image->addr + (y * pos->plane_x + x * (image->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}