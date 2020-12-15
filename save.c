#include "include/cub.h"

int			get_color_bmp(t_data *windows, int x, int y, t_bitmap *w)
{
	int	rgb;
	int	color;

	color = *(int*)(windows->addr + (4 * w->width *
	(w->heigth - 1 - y)) + (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

char	*create_bitmap_file_header(t_bitmap *w)
{
	int						filesize;
	static char fileheader[] = {
           0,0, /// signature
           0,0,0,0, /// image file size in bytes
           0,0,0,0, /// reserved
           0,0,0,0, /// start of pixel array
       };

	filesize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (BYTES_PER_PIXEL *
	w->width * w->heigth);
	fileheader[0] = (unsigned char)('B');
	fileheader[1] = (unsigned char)('M');
	fileheader[2] = (unsigned char)(filesize);
	fileheader[3] = (unsigned char)(filesize >> 8);
	fileheader[4] = (unsigned char)(filesize >> 16);
	fileheader[5] = (unsigned char)(filesize >> 24);
	fileheader[10] = (unsigned char)(INFO_HEADER_SIZE + FILE_HEADER_SIZE);
	return (fileheader);
}

char	*create_bitmap_info_header(t_bitmap *w)
{
	static char	infoheader[] = {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
	};

	infoheader[0] = (unsigned char)(INFO_HEADER_SIZE);
	infoheader[4] = (unsigned char)w->width;
	infoheader[5] = (unsigned char)(w->width >> 8);
	infoheader[6] = (unsigned char)(w->width >> 16);
	infoheader[7] = (unsigned char)(w->width >> 24);
	infoheader[8] = (unsigned char)w->heigth;
	infoheader[9] = (unsigned char)(w->heigth >> 8);
	infoheader[10] = (unsigned char)(w->heigth >> 16);
	infoheader[11] = (unsigned char)(w->heigth >> 24);
	infoheader[12] = (unsigned char)(1);
	infoheader[14] = (unsigned char)(BYTES_PER_PIXEL * 8);
	return (infoheader);
}

static int		write_bmp_data(t_bitmap *w, t_data *windows)
{
	static unsigned char	zero[4] = {
		0, 0, 0, 0
	};
	int						i;
	int						j;
	int						color;

	i = 0;
	while (i < w->heigth)
	{
		j = 0;
		while (j < w->width)
		{
			color = get_color_bmp(windows, j, i, w);
			write(w->fd, &color, 3);
			if (w->paddingsize > 0)
			{
				write(w->fd, &zero, w->paddingsize);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void			generate_bitmap_image(t_game *pos)
{
	t_bitmap w;
	t_data *windows;
	char	*name;

	name = "screenshot.bmp";
	w.fd = open(name, O_CREAT | O_RDWR, 00600);
	//w = NULL;
	windows = &pos->img;
	w.width = (int)pos->winres.window_width;
	w.heigth = (int)pos->winres.window_height;
	w.paddingsize = (4 - (w.width * 3) % 4) % 4;
//	if ((w->fd = open("screenshot.bmp", O_WRONLY | O_CREAT
//									| O_TRUNC | O_APPEND) < 0)
//		return_error (2);
	ft_putstr_fd("Se esta creando el archivo BMP ...\n", 1);
	w.fileheader = create_bitmap_file_header(&w);
	w.infoheader = create_bitmap_info_header(&w);
	write(w.fd, w.fileheader, FILE_HEADER_SIZE);
	write(w.fd, w.infoheader, INFO_HEADER_SIZE);
	if (!write_bmp_data(&w, windows))
		return_error (2);
	close(w.fd);
}
/*
void	bitmap_info_header(t_all *a, int fd)
{
	int header_info_size;
	int plane_nbr;
	int o_count;
​
	header_info_size = 40;
	plane_nbr = 1;
	write(fd, &header_info_size, 4);
	write(fd, &a->mlx.win_width, 4);
	write(fd, &a->mlx.win_height, 4);
	write(fd, &plane_nbr, 2);
	write(fd, &a->img.bits_per_pixel, 2);
	o_count = 0;
	while (o_count < 28)
	{
		write(fd, "\0", 1);
		o_count++;
	}
}
​
void	mir_verti(t_all *a)
{
	int		line_cnt;
	int		e;
	int		f;
​
	line_cnt = 0;
	while ((unsigned int)line_cnt < a->mlx.win_height)
	{
		e = 0;
		f = a->img.line_length;
		while (e < f && e != f)
		{
			mir_verti_pixel(a, line_cnt, &e, f);
			f -= 4;
		}
		line_cnt++;
	}
}
​
void	mir_verti_pixel(t_all *a, int line_cnt, int *e, int f)
{
	char	save;
	int		k;
​
	k = 3;
	while (k >= 0)
	{
		save = a->img.addr[*e + (line_cnt * a->img.line_length)];
		a->img.addr[*e + (line_cnt * a->img.line_length)] =
			a->img.addr[f - k + (line_cnt * a->img.line_length - 1)];
		a->img.addr[f - k + (line_cnt * a->img.line_length - 1)] =
			save;
		k--;
		*e = *e + 1;
	}
}
​
void	data_to_bitmap(t_all *a, int fd)
{
	int i;
​
	i = a->mlx.win_width * a->mlx.win_height - 1;
	while (i >= 0)
	{
		write(fd, &a->img.addr[i * a->img.bits_per_pixel / 8], 4);
		i--;
	}
}*/

void	save_bmp(t_game *pos)
{
	start(pos);
	generate_bitmap_image(pos);
	ft_putstr_fd("Image BMP 'screenshot.bmp' create correctly.\n", 1);
	exit(0);
/*
		int		fd;
	int		file_size;
	int		first_pix;
	char	*name;
​
	name = "first_image.bmp";
	fd = open(name, O_CREAT | O_RDWR, 00600);
	file_size = 14 + 40 + 4 + (pos->windows.
	 * a->mlx.win_height) * 4;
	first_pix = 14 + 40 + 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
	bitmap_info_header(a, fd);
	mir_verti(a);
	data_to_bitmap(a, fd);
	close(fd);
	exit_game(a);*/
}