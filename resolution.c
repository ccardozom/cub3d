#include "cub.h"

void	resolution(char *line, t_pos_py *pos, int ptr)
{
	int index;

	index = ptr + 1;
	while (ft_isdigit(line[index]) == 0)
		index++;
	pos->plane_x=ft_atoi(&line[index]);

	while (ft_isdigit(line[index]) == 1)
		index++;
	index++;
	while (ft_isdigit(line[index]) == 0)
		index++;
	pos->plane_y=ft_atoi(&line[index]);
	
}