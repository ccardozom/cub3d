#include "cub.h"

void	resolution(char *buffer, t_pos_py *pos, int ptr)
{
	int		i;
	int		j;
	char	width[6];
	char	tall[6];

	i = ptr;
	j = 0;
	while (buffer[i] != '\n')
	{
		while (buffer[i] != ' ' && buffer[i] >= 0 && buffer[i] <= 9)
		{
			printf("\n%c\n",width[j]);
			width[j] = buffer[i];
			pos->map_c = (pos->map_c * 10) + width[j] - '0';
			i++;
			j++;
		}
		width[j] = '\0';
		i++;
		j = 0;
		while (buffer[i] != ' ' && buffer[i] >= 0 && buffer[i] <= 9)
		{
			tall[j] = buffer[i];
			pos->map_f = (pos->map_f * 10) + tall[j] - '0';
			i++;
			j++;
		}
		tall[j] = '\0';
	}

}