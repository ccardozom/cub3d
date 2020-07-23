/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:01:01 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/23 13:17:12 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "mlx/mlx.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

#define	relleno	'8'

int fd;
void	*mlx;
void	*img;
void	*mlx_win;

typedef struct	s_position
{
	int		pos_x;
	int		pos_y;
	int		dir_x;
	int		dir_y;
	int		plane_x;
	int		plane_y;
	int		map_f;
	int		map_c;
	int		matriz_c;
	int		matriz_f;
	char		**map;
}				t_pos_py;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		offset;
}				t_data;

typedef struct s_tile_size
{
	int x;
	int y;
	int pos_x;
	int pos_y;
	int pos_sy;
}				t_tile;

void imprimir_matriz(t_pos_py *pos);

void	read_map(int fd, t_pos_py *pos);
void	check_line(char *line, t_pos_py *pos);
//void	position_player (t_pos_py *data);
void	reset_position(t_pos_py *pos, t_tile *tile);
void	resolution(char *buffer, t_pos_py *pos, int ptr);
void	is_map(char *line, t_pos_py *pos);
void	create_window(t_pos_py *pos, t_data *img);
int		open_file(void);
void	create_map(t_pos_py *pos);
void	create_matriz(char *line, t_pos_py *pos);
void	fill_matriz(t_pos_py *pos);
int		return_error(int x);
void	new_matriz(t_pos_py *pos, char *line);

void    draw_map(t_pos_py *pos, t_data *image, t_tile *tile);
int     assign_pixel(int x, t_tile *tile, t_data *image, t_pos_py * pos);
void    my_mlx_pixel_put(t_pos_py *pos, t_data *image, int x, int y, int color);

#endif