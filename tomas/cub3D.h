/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:34:02 by tsierra-          #+#    #+#             */
/*   Updated: 2020/12/06 08:48:37 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
​
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
​
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_UP		126
# define KEY_LEFT	123
# define KEY_DOWN	125
# define KEY_RIGHT	124
​
typedef struct s_mlx
{
	void	*mlx_ptr;
}	t_mlx;
​
typedef struct s_win
{
	void	*win_ptr;
	int		x;
	int		y;
}	t_win;
​
typedef struct s_img
{
	void	*img_ptr;
	char	*buffer;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		offset;
}	t_img;
​
typedef struct s_tex
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*s_path;
	int		f_red;
	int		f_green;
	int		f_blue;
	int		c_red;
	int		c_green;
	int		c_blue;
}	t_tex;
​
typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_color;
​
typedef struct s_map
{
	int	x;
	int y;
	int	size;
	int	map[64];
}	t_map;
​
typedef struct s_pos
{
	double	x;
	double	y;
	float	px;
	float	py;
	float	pdx;
	float	pdy;
	float	pa;
	float	fova;
	float	raya;
}	t_pos;
​
typedef struct s_all
{
	t_mlx	mlx;
	t_win	win;
	t_img	img;
	t_map	maze;
	t_pos	pos;
	t_tex	tex;
	char	**map;
	int		is_map;
	int		bol;
	int		control;		
	int		map_rows;
	int		map_columns;
	int		sprites;
	int		f_c;
	int		rows;
	int		control_player;
}	t_all;
#endif