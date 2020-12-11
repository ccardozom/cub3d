#include "include/cub.h"

static int
	write_bmp_data(int file, t_window *w, int pad)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					color;
	i = 0;
	while (i < (int)w->size.y)
	{
		j = 0;
		while (j < (int)w->size.x)
		{
			color = get_color(w, j, i);
			if (write(file, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int
	write_bmp_header(int fd, int filesize, t_global *global)
{
	int				i;
	int				tmp;
	unsigned char	bmpfileheader[54];
	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)(‘B’);
	bmpfileheader[1] = (unsigned char)(‘M’);
	set_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	tmp = global->window.size.x;
	set_int_in_char(bmpfileheader + 18, tmp);
	tmp = global->window.size.y;
	set_int_in_char(bmpfileheader + 22, tmp);
	bmpfileheader[27] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

void	save(t_game *pos)
{
	t_data	 	*w;
	int			filesize;
	int			file;
	int			pad;
	w = &pos->img;
	pad = (4 - ((int)w->line_length * 3) % 4) % 4;
	filesize = 54 + (3 * ((int)w->size.x + pad) * (int)w->size.y);
	if ((file = open(“save.bmp”, O_WRONLY | O_CREAT
									| O_TRUNC | O_APPEND)) < 0)
		return (0);
	if (!write_bmp_header(file, filesize, global))
		return (0);
	if (!write_bmp_data(file, w, pad))
		return (0);
	close(file);
	return (1);
}