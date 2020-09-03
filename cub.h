/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:01:01 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/03 12:58:16 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "mlx/mlx.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

#define	relleno	'8'

# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_UP 		126
# define KEY_DOWN		125
# define KEY_W			13
# define KEY_S			1
# define KEY_Q			12
# define KEY_E			14
# define FALSE			0
# define TRUE			1
# define KEY_ESC		53
# define PI 			3.141592

typedef struct	s_Ray
{
	float		xray;
	float		yray;
	float		rayAngle;
	//float		wallHitX;
	//float		wallHitY;
	float		distance;
	float		height;
	//int			wasHitVertical;
	//int			isRayFacingUp;
	//int			isRayFacingDown;
	//int			isRayFacingLeft;
	//int			isRayFacingRight;
	//int			wallHitContent;
	//int			foundHorzWallHit;
	//float		horzWallhitx;
	//float		horzWallhity;
	//int			horzWallcontent;
	//float		xintercep;
	//float		yintercep;
	float		xincrement;
	float		yincrement;
}				t_rays;

typedef struct	s_raycast
{
	float		fov_angle;
	int			num_rays;
	int 		idcolumns;
}				t_cast;

typedef struct	s_control
{
	int			ok_player;
	int 		player_count;
	int			check_resolution;
}				t_control;


typedef struct	s_position
{
	float		x;
	float		y;
}				t_pos;

typedef struct	s_move_player
{
	int			turn;
	int			walk;
	float		rotationangle;
	float		movespeed;
	float		rotationspeed;
	float		lasttime;
	float		delta;
}				t_move;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			offset;
}				t_data;

typedef struct		s_tile_size
{
	int			size;
	int			f;
	int			c;
	int			squa_f;
	int			squa_c;
	int			pos_squa;
}					t_tile;

typedef struct	s_wall_control
{
	t_pos		posA;
	t_pos		posB;

}				t_wall;

typedef struct	s_game
{
	int			fd;
	void		*mlx;
	void		*mlx_win;
	int			rows;
	int			columns;
	char		**map;
	t_pos		player;
	t_pos		dir;
	t_pos		winres;
	t_pos		matriz;
	t_move		move;
	t_data		img;
	t_tile		tile;
	t_control	control;
	t_cast		cast;
	t_rays		ray;
}				t_game;

void imprimir_matriz(t_game *pos);

void	initialize(t_game *pos);
void	read_map(t_game *pos);
void	check_line(char *line, t_game *pos);
void	position_player(t_game *pos, t_pos *tile_pos);
void	reset_position(t_game *pos);
void	resolution(char *buffer, t_game *pos, int ptr);
void	is_map(char *line, t_game *pos);
void	create_window(t_game *pos, t_data *img);
int		open_file();
void	create_map(t_game *pos);
void	create_matriz(char *line, t_game *pos);
void	fill_matriz(t_game *pos);
int		return_error(int x);
void	new_matriz(t_game *pos, char *line);
void	wall_control(char **matriz, int rows, int columns);
void	start(t_game *pos);

int		key_press(int keycode, t_game *pos);
int		key_release(int keycode, t_game *pos);

void	update_player(t_game *pos);
void	draw_minimap(t_game *pos);
int		assign_pixel(int x, t_tile *tile, t_data *image, t_game *pos);
void	my_mlx_pixel_put(t_data *image, int x, int y, int color);
void	draw_player(t_game *pos);
void	draw_player_move(t_game *pos);
void	cast_all_rays(t_game *pos);

#endif