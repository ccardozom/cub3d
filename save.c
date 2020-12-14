#include "include/cub.h"

int			get_color_bmp(unsigned char *image, int x, int y, t_game *pos)
{
	int	rgb;
	int	color;

	color = *(int*)(image + (4 * (int)pos->winres.window_width *
	((int)pos->winres.window_height - 1 - y)) + (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

unsigned char	*create_bitmap_file_header(t_game *pos)
{
	int						filesize;
	static unsigned char fileheader[] = {
           0,0, /// signature
           0,0,0,0, /// image file size in bytes
           0,0,0,0, /// reserved
           0,0,0,0, /// start of pixel array
       };

	filesize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (BYTES_PER_PIXEL *
	(int)pos->winres.window_width * (int)pos->winres.window_height);
	fileheader[0] = (unsigned char)('B');
	fileheader[1] = (unsigned char)('M');
	fileheader[2] = (unsigned char)(filesize);
	fileheader[3] = (unsigned char)(filesize >> 8);
	fileheader[4] = (unsigned char)(filesize >> 16);
	fileheader[5] = (unsigned char)(filesize >> 24);
	fileheader[10] = (unsigned char)(INFO_HEADER_SIZE + FILE_HEADER_SIZE);
	return (fileheader);
}

unsigned char	*create_bitmap_info_header(t_game *pos)
{
	static unsigned char	infoheader[] = {
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
	infoheader[4] = (unsigned char)((int)pos->winres.window_width);
	infoheader[5] = (unsigned char)((int)pos->winres.window_width >> 8);
	infoheader[6] = (unsigned char)((int)pos->winres.window_width >> 16);
	infoheader[7] = (unsigned char)((int)pos->winres.window_width >> 24);
	infoheader[8] = (unsigned char)((int)pos->winres.window_height);
	infoheader[9] = (unsigned char)((int)pos->winres.window_height >> 8);
	infoheader[10] = (unsigned char)((int)pos->winres.window_height >> 16);
	infoheader[11] = (unsigned char)((int)pos->winres.window_height >> 24);
	infoheader[12] = (unsigned char)(1);
	infoheader[14] = (unsigned char)(BYTES_PER_PIXEL * 8);
	return (infoheader);
}

static int		write_bmp_data(int file, unsigned char *image, t_game *pos)
{
	static unsigned char	zero[4] = {
		0, 0, 0, 0
	};
	int						i;
	int						j;
	int						color;
	int						paddingsize;

	paddingsize = (4 - ((int)pos->winres.window_width * BYTES_PER_PIXEL) % 4) % 4;
	i = (int)pos->winres.window_width * ((int)pos->winres.window_height - 1);
	while (i >= 0)
	{
		j = 0;
		while (j < (int)pos->winres.window_width)
		{
			color = get_color_bmp(image, j, i, pos);
			write(file, &color, 3);
			if (paddingsize > 0)
			{
				write(file, &zero, paddingsize);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void			generate_bitmap_image(unsigned char *image, t_game *pos)
{
	int						paddingsize;
	unsigned char			*fileheader;
	unsigned char			*infoheader;
	int						fd;

	paddingsize = (4 - ((int)pos->winres.window_width * 3) % 4) % 4;
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT
									| O_TRUNC | O_APPEND)) < 0)
		return_error (2);
	ft_putstr_fd("Se esta creando el archivo BMP ...\n", 1);
	fileheader = create_bitmap_file_header(pos);
	infoheader = create_bitmap_info_header(pos);
	write(fd, fileheader, FILE_HEADER_SIZE);
	write(fd, infoheader, INFO_HEADER_SIZE);
	if (!write_bmp_data(fd, image, pos))
		return_error (2);
	close(fd);
}

void	save_bmp(t_game *pos)
{
	start(pos);
	generate_bitmap_image((unsigned char*)pos->img.addr, pos);
	ft_putstr_fd("Image BMP 'screenshot.bmp' create correctly.\n", 1);
	exit(0);
}