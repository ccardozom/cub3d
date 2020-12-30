/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:35:31 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/30 11:51:14 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

char			*create_bitmap_file_header(t_bitmap *w)
{
	int				filesize;
	static char		fileheader[14];

	ft_bzero(fileheader, 14);
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

char			*create_bitmap_info_header(t_bitmap *w)
{
	static char	infoheader[40];

	ft_bzero(infoheader, 40);
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
	t_bitmap	w;
	t_data		*windows;
	char		*name;

	name = "save.bmp";
	w.fd = open(name, O_CREAT | O_RDWR, 00600);
	if (w.fd < 0)
		return_error(2);
	windows = &pos->img;
	w.width = (int)pos->winres.window_w;
	w.heigth = (int)pos->winres.window_h;
	w.paddingsize = (4 - (w.width * 3) % 4) % 4;
	ft_putstr_fd("Se esta creando el archivo BMP ...\n", 1);
	w.fileheader = create_bitmap_file_header(&w);
	w.infoheader = create_bitmap_info_header(&w);
	write(w.fd, w.fileheader, FILE_HEADER_SIZE);
	write(w.fd, w.infoheader, INFO_HEADER_SIZE);
	if (!write_bmp_data(&w, windows))
		return_error(2);
	close(w.fd);
}

void			save_bmp(t_game *pos)
{
	start(pos);
	generate_bitmap_image(pos);
	ft_putstr_fd("Image BMP 'screenshot.bmp' create correctly.\n", 1);
	exit(0);
}
