/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:01:01 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/01 14:47:03 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "../mlx/mlx.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"


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
# define PI 			3.141592653

typedef struct s_bmpFileHeader
{
  /* 2 bytes de identificación */
  unsigned int size;        /* Tamaño del archivo */
  unsigned short resv1;       /* Reservado */
  unsigned short resv2;       /* Reservado */
  unsigned int offset;      /* Offset hasta hasta los datos de imagen */
} t_bmpFileHeader;

typedef struct s_bmpInfoHeader
{
  unsigned int headersize;      /* Tamaño de la cabecera */
  unsigned int width;               /* Ancho */
  unsigned int height;          /* Alto */
  unsigned short planes;                  /* Planos de color (Siempre 1) */
  unsigned short bpp;             /* bits por pixel */
  unsigned int compress;        /* compresión */
  unsigned int imgsize;     /* tamaño de los datos de imagen */
  unsigned int bpmx;                /* Resolución X en bits por metro */
  unsigned int bpmy;                /* Resolución Y en bits por metro */
  unsigned int colors;              /* colors used en la paleta */
  unsigned int imxtcolors;      /* Colores importantes. 0 si son todos */
} t_bmpInfoHeader;

typedef struct	s_position
{
	float		x;
	float		y;
	float		window_width;
	float		window_height;
}				t_pos;

typedef struct	s_color
{
	int				empty;
	int				r;
	int				g;
	int				b;
}				t_color;

typedef struct	s_Ray
{
	float		xintercep;
	float		yintercep;
	float		xstep;
	float		ystep;
	float		rayangle;
	float		horizwallhitx;
	float		horizwallhity;
	float		nexthoriztouchx;
	float		nexthoriztouchy;
	float		xtocheck;
	float		ytocheck;
	int 		idcolumns;
	int			foundhorizwallhit;
	int			horizwallcontent;
	int			foundvertwallhit;
	float		vertwallhitx;
	float		vertwallhity;
	int			vertwallcontent;
	float		nextverttouchx;
	float		nextverttouchy;
	float		horizhitdistance;
	float		verthitdistance;
}				t_rays;

typedef struct	s_ray_allocated
{
	float		distance;
	float		wallhitY;
	float		wallhitX;
	int			wallhitcontent;
	int			washitvertical;
	float		ray_angle;
	int			israyfacingup;
	int			israyfacingdown;
	int			israyfacingleft;
	int			israyfacingright;
}				t_ray;

typedef struct	s_move_player
{
	int			turn;
	int			walk;
	float		minimapscale;
	float		player_angle;
	float		movespeed;
	float		rotationspeed;
	float		FOV_angle;
	int			num_rays;
	int			player_control;
	t_pos		pos;
	float		perpdistance;
	float		distanceprojplane;
	float		projectedwallheight;
	int			wallstripheight;
	int			walltoppixel;
	int			wallbottompixel;
	int			textureoffsetx;
	int			textureoffsety;
}				t_player;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			offset;
}				t_data;

typedef struct	s_text
{
	char			*path;
	void			*id;
	int				*image;
	int				data;
	int				w;
	int				h;
	int				endian;
	int				size_line;
}				t_text;

typedef struct	s_sprite
{
	t_pos			pos;
	float			distance;
	float			vectx;
	float			vecty;
	int				visible;
	float			spriteangulo;
	int				spr_bottom;
	int				spr_top;
	int				x;
	int				spr_height;

}				t_sprite;

typedef struct	s_textures
{
	t_text			north_text;
	t_text			south_text;
	t_text			east_text;
	t_text			weast_text;
	t_text			sprite;
	t_color			floor;
	t_color			ceilling;
}				t_textures;

typedef struct		s_tile_size
{
	int				size;
	int				f;
	int				c;
	int				squa_f;
	int				squa_c;
	int				pos_squa;
}					t_tile;

typedef struct	s_game
{
	int				fd;
	void			*mlx;
	void			*mlx_win;
	int				rows;
	int				columns;
	char			**map;
	void			*data;
	int				control;
	int				control_map;
	int				first_frame;
	int				color;
	int				spritecount;
	int				spritecount_aux;
	int				pos_id_spr;
	t_pos			dir;
	t_pos			winres;
	t_pos			matriz;
	t_pos			proyection_center;
	t_player		player;
	t_data			img;
	t_textures		texture;
	t_tile			tile;
	t_rays			rays;
	t_ray			*ray_data;
	t_sprite		*sprites;
	int				checking[8];
}					t_game;

void imprimir_matriz(t_game *pos);

void	initialize(t_game *pos, char **argv);
void	read_map(t_game *pos, char **argv);
void	check_line(char *line, t_game *pos);
int		checker(int *checker);
int		search_wall(t_game *pos, char *line, char wall);
void	position_player(t_game *pos, t_pos *tile_pos);
void	sprites(t_game *pos);
void	reset_position(t_game *pos);
void	reset_rays_data(t_game *pos);
void	reset_sprites(t_game *pos);
void	resolution(char *buffer, t_game *pos);
void	is_map(char *line, t_game *pos);
void	create_window(t_game *pos, t_data *img);
int		open_file(char **argv);
void	create_map(t_game *pos, char **argv);
void	create_matriz(char *line, t_game *pos);
void	fill_matriz(t_game *pos);
void	new_matriz(t_game *pos, char *line);
void	wall_control(char **matriz, int rows, int columns);
int     wall_colision(t_game *pos, float y, float x);
void	start(t_game *pos);
void	return_error(int x);
float   distancebetweenpoints(float x1, float y1, float x2, float y2);
int		key_press(int keycode, t_game *pos);
int		key_release(int keycode, t_game *pos);
int		wall_colision_search_hor(t_game *pos, t_ray *ray_data);
int		wall_colision_search_ver(t_game *pos, t_ray *ray_data);
void	dir_colision(t_game *pos, t_ray *ray_data);
void	update_player(t_game *pos);
float	normalizeangle(float angle);
void	draw_minimap(t_game *pos);
int		assign_pixel(int x, t_tile *tile, t_data *image, t_game *pos);
void	my_mlx_pixel_put(t_data *image, int x, int y, int color);
void	draw_player(t_game *pos);
void	draw_player_move(t_game *pos);
void	cast_all_rays(t_game *pos);
void	horizontal_collisionA(t_game *pos, float rayangle);
void    horizontal_collision_next(t_game *pos);
void    vertical_collision_next(t_game *pos, float rayangle);
void	vertical_collisionA(t_game *pos, float rayangle);
int		control_wall_x(t_game *pos, float new_pos);
int		control_wall_y(t_game *pos, int new_pos);
void	generate_3dprojection(t_game *pos);
void	color_all_buffer(t_game *pos);
void	path_texture_n(t_game *pos, char *line);
void	path_texture_s(t_game *pos, char *line);
void	path_texture_e(t_game *pos, char *line);
void	path_texture_o(t_game *pos, char *line);
void	path_texture_sp(t_game *pos, char *line);
void	color_all_buffer(t_game *pos);
void	charge_textures_main(t_game *pos);
int		charge_textures(t_game *pos, t_text *texture);

#endif