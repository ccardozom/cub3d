/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:01:01 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/25 15:14:04 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BONUS_H
# define CUB_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_W				13
# define KEY_S				1
# define KEY_A				0
# define KEY_D				2
# define FALSE				0
# define TRUE				1
# define KEY_ESC				53
# define PI					3.141592653
# define BYTES_PER_PIXEL		3
# define INFO_HEADER_SIZE	40
# define FILE_HEADER_SIZE	14

typedef struct	s_new
{
	float new_player_x;
	float new_player_y;
	float move_step;
	float move_l_r;
}				t_new;

typedef struct	s_position
{
	float		x;
	float		y;
	float		window_w;
	float		window_h;
}				t_pos;

typedef struct	s_color
{
	int			empty;
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_ray
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
	int			idcolumns;
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
	float		wallhit_y;
	float		wallhit_x;
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
	int			l_r;
	float		minimapscale;
	float		player_angle;
	float		movespeed;
	float		rotationspeed;
	float		v_angle;
	int			num_rays;
	int			player_control;
	t_pos		pos;
	float		perpdistance;
	float		distanceprojplane;
	float		projectedwallheight;
	float		wallstripheight;
	float		walltoppixel;
	float		wallbottompixel;
	float		textureoffsetx;
	float		textureoffsety;
	float		wall_x;
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

typedef struct	s_bitmap
{
	char		*fileheader;
	char		*infoheader;
	int			fd;
	int			paddingsize;
	int			width;
	int			heigth;
}				t_bitmap;

typedef struct	s_text
{
	char		*path;
	void		*id;
	int			*image;
	int			data;
	int			w;
	int			h;
	int			endian;
	int			size_line;
}				t_text;

typedef struct	s_sprite
{
	t_pos		pos;
	float		distance;
	float		vectx;
	float		vecty;
	int			visible;
	float		spriteangulo;
	float		anguloini;
	float		angulofin;
	int			spr_bottom;
	int			spr_top;
	float		x;
	float		spr_height;

}				t_sprite;

typedef struct	s_colortextura
{
	float		y;
	float		tex_x;
	float		tex_y;
	float		x;
	float		tex_send;
	float		auxstep;
	int			index;
}				t_colortexture;

typedef struct	s_textures
{
	t_text		north_text;
	t_text		south_text;
	t_text		east_text;
	t_text		weast_text;
	t_text		sprite;
	t_color		floor;
	t_color		ceilling;
}				t_textures;

typedef struct	s_tile_size
{
	float		size;
	int			f;
	int			c;
	int			squa_f;
	int			squa_c;
	int			pos_squa;
}				t_tile;

typedef struct	s_map
{
	int			f;
	int			c;
	int			check_ini;
	int			check_fin;
}				t_checkmap;

typedef struct	s_game
{
	int			fd;
	void		*mlx;
	void		*mlx_win;
	int			rows;
	int			columns;
	char		**map;
	void		*data;
	int			control_map;
	int			first_frame;
	int			color;
	int			sp_count;
	int			spritecount_aux;
	int			pos_id_spr;
	int			line_count1;
	int			line_count2;
	int			checkplayer;
	int			control_row;
	int			control_line_empty;
	t_checkmap	checkmap;
	t_pos		dir;
	t_pos		winres;
	t_pos		matriz;
	t_pos		proyection_center;
	t_player	player;
	t_data		img;
	t_textures	texture;
	t_tile		tile;
	t_rays		rays;
	t_ray		*ray_data;
	t_sprite	*sp;
	int			checking[8];
}				t_game;

void			initialize(t_game *pos, char **argv);
void			read_map(t_game *pos, char **argv);
void			check_line(char *line, t_game *pos);
int				checker(int *checker);
void			screen(t_game *pos);
int				search_wall(t_game *pos, char *line);
void			position_player(t_game *pos, t_pos *tile_pos);
int				player(char c);
void			sprites(t_game *pos);
void			angulo_ini(t_game *pos, int x1, int i);
void			angulo_fin(t_game *pos, int x2, int i);
void			angulo_central(t_game *pos, int i);
void			reset_position(t_game *pos);
void			reset_rays_data(t_game *pos);
void			reset_sprites(t_game *pos);
void			reset_color(t_color *color);
void			resolution(char *buffer, t_game *pos);
int				count_char_in_str(char *str, char c);
void			is_map(char *line, t_game *pos);
int				open_file(char **argv);
void			create_map(t_game *pos, char **argv);
void			create_matriz(char *line, t_game *pos);
void			new_matriz(t_game *pos, char *line);
int				wall_control(char **matriz, int rows, int columns);
int				wall_colision(t_game *pos, float y, float x);
void			start(t_game *pos);
void			save_bmp(t_game *pos);
void			return_error(int x);
float			distancebetweenpoints(float x1, float y1, float x2, float y2);
int				key_press(int keycode, t_game *pos);
int				key_release(int keycode, t_game *pos);
int				wall_colision_search_hor(t_game *pos, t_ray *ray_data);
int				wall_colision_search_ver(t_game *pos, t_ray *ray_data);
void			dir_colision(t_game *pos, t_ray *ray_data);
void			update_player(t_game *pos);
float			normalizeangle(float angle);
void			draw_minimap(t_game *pos);
void			my_mlx_pixel_put(t_data *image, int x, int y, int color);
void			draw_player(t_game *pos);
void			draw_player_move(t_game *pos);
void			cast_all_rays(t_game *pos);
int				control_wall_x(t_game *pos, float new_pos);
int				control_wall_y(t_game *pos, int new_pos);
void			generate_3dprojection(t_game *pos);
void			color_all_buffer(t_game *pos);
void			path_texture_n(t_game *pos, char *line);
void			path_texture_s(t_game *pos, char *line);
void			path_texture_e(t_game *pos, char *line);
void			path_texture_o(t_game *pos, char *line);
void			path_texture_sp(t_game *pos, char *line);
void			charge_textures_main(t_game *pos);
int				charge_textures(t_game *pos, t_text *texture);
int				get_color_bmp(t_data *windows, int x, int y, t_bitmap *w);
#endif
