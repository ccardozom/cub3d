/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:01:01 by ccardozo          #+#    #+#             */
/*   Updated: 2020/07/21 13:04:59 by ccardozo         ###   ########.fr       */
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
	char		**map;
}				t_pos_py;

typedef struct  s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	read_map(int fd, t_pos_py *pos);
void	check_line(char *line, t_pos_py *pos);
//void	position_player (t_pos_py *data);
//void	reset_position(t_pos_py *pos);
void	resolution(char *buffer, t_pos_py *pos, int ptr);
void	is_map(char *line, t_pos_py *pos);
void	create_window(t_pos_py *pos);
int		open_file(void);
void	create_map(t_pos_py *pos);
void	create_matriz(char *line, t_pos_py *pos);
void	fill_matriz(t_pos_py *pos);
int		return_error(int x);

#endif