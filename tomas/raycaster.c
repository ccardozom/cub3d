#include "cub3D.h"
​;
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
​
	dst = img->buffer + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
​
void	player_draw(t_all *all, int color)
{
	int		size;
	float	round_x;
	float	round_y;
​
	size = 5;
	round_y = all->pos.py - size;
	while (round_y < all->pos.py + size)
	{
		round_x = all->pos.px - size;
		while (round_x < all->pos.px + size)
		{
			my_mlx_pixel_put(&all->img, round_x, round_y, color);
			round_x++;
		}
		round_y++;
	}
}
​
float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
​
void	vision_line_draw(t_all *all, int color)
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	size_line;
	float	i;
​
	x1 = all->pos.px;
	y1 = all->pos.py;
	x2 = all->pos.px + all->pos.pdx * 5;
	y2 = all->pos.py + all->pos.pdy * 5;
	size_line = distance_between_points(x1, y1, x2, y2);
//	printf("%f %f %f\n", x1, x2, size_line);
	i = 0;
	while (x1 <= x2)
	{
		my_mlx_pixel_put(&all->img, x1, y1, color);
		x1 += 0.1;
		y1 = (x1 - all->pos.px) / (x2 - all->pos.px) * (y2 - all->pos.py) + all->pos.py;
	}
	while (x1 >= x2)
	{
		my_mlx_pixel_put(&all->img, x1, y1, color);
		x1 -= 0.1;
		y1 = (x1 - all->pos.px) / (x2 - all->pos.px) * (y2 - all->pos.py) + all->pos.py;
	}
}
​
void	map2D_draw(t_all *all)
{
	int	x;
	int	y;
	int	xo;
	int	yo;
	int	size_x;
	int	size_y;
​
	y = 0;
	size_y = 0;
	while (y < all->maze.y)
	{
		size_x = 0;
		x = 0;
		while (x < all->maze.x)
		{
			yo = 0;
			while (yo + 1 < all->maze.size)
			{
				xo = 0;
				while (xo < all->maze.size - 1)
				{
					if (all->maze.map[y * all->maze.x + x] == 1)
						my_mlx_pixel_put(&all->img, xo + size_x, yo + size_y, 0xFFFFFF);
					else
						my_mlx_pixel_put(&all->img, xo + size_x, yo + size_y, 0x8E8E8E);
					xo++;
				}
				yo++;
			}
			size_x += all->maze.size;
			x++;
		}
		size_y += all->maze.size;
		y++;
	}
}
​
int		moving_player(t_all *all)
{
	map2D_draw(all);
	player_draw(all, 0xFFFF00);
	vision_line_draw(all, 0xFFFF00);
	mlx_put_image_to_window(all->mlx.mlx_ptr, all->win.win_ptr, all->img.img_ptr, 0, 0);
	return (1);
}
​
int		key_press(int keycode, t_all *all)
{
	player_draw(all, 0x0);
	vision_line_draw(all, 0x0);
	if (keycode == KEY_W)
	{
		all->pos.py -= 10;
	//	all->pos.px += all->pos.pdx;
	//	all->pos.py += all->pos.pdy;
	}
	if (keycode == KEY_A)
	{
		all->pos.px -= 10;
		all->pos.pa -= 0.1;
		if (all->pos.pa < 0)
			all->pos.pa += 2 * M_PI;
		all->pos.pdx = cos(all->pos.pa) * 5;
		all->pos.pdy = sin(all->pos.pa) * 5;
		printf("%f %f %f %f\n", all->pos.pa, all->pos.pdx, all->pos.pdy, cos(all->pos.raya));
	}
	if (keycode == KEY_S)
	{
		all->pos.py += 10;
	//	all->pos.px -= all->pos.pdx;
	//	all->pos.py -= all->pos.pdy;
	}
	if (keycode == KEY_D)
	{
		all->pos.px += 10;
		all->pos.pa += 0.1;
		if (all->pos.pa > 2 * M_PI)
			all->pos.pa -= 2 * M_PI;
		all->pos.pdx = cos(all->pos.pa) * 5;
		all->pos.pdy = sin(all->pos.pa) * 5;
		printf("%f %f %f %f\n", all->pos.pa, all->pos.pdx, all->pos.pdy, cos(all->pos.raya));
	}
	if (keycode == KEY_LEFT)
		all->pos.pa -= 0.1;
	if (keycode == KEY_RIGHT)
		all->pos.pa += 0.1;
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (1);
}
​
void	init(t_all *all)
{
	all->pos.px = 256;
	all->pos.py = 256;
	all->pos.pa = 0;
	all->pos.fova = 66 * (M_PI / 180);
	all->pos.raya = all->pos.pa - (all->pos.fova / 2);
	all->pos.pdx = cos(all->pos.pa) * 5;
	all->pos.pdy = sin(all->pos.pa) * 5;
	all->maze.x = 8;
	all->maze.y = 8;
	all->maze.size = 64;
	int map[64] = {
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 0, 1, 0, 1,
		1, 0, 1, 0, 0, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1
	};
	int i = 0;
	while (i < 64)
	{
		all->maze.map[i] = map[i];
		i++;
	}
	all->maze.map[i] = '\0';
}
​
int		main()
{
	t_all	all;
​
	init(&all);
	all.mlx.mlx_ptr = mlx_init();
	all.win.win_ptr = mlx_new_window(all.mlx.mlx_ptr, 1024, 512, "cub3D");
	all.img.img_ptr = mlx_new_image(all.mlx.mlx_ptr, 1024, 512);
	all.img.buffer = mlx_get_data_addr(all.img.img_ptr, &all.img.bits_per_pixel, &all.img.size_line, &all.img.endian);
	mlx_hook(all.win.win_ptr, 2, 0, &key_press, &all);
	mlx_loop_hook(all.mlx.mlx_ptr, &moving_player, &all);
	mlx_loop(all.mlx.mlx_ptr);
	return (1);
}