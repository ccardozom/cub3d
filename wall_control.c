#include "cub.h"

void    firts_line(t_wall *wall, char **matriz)
{
    int index;

    index = 0;
    while (matriz[0][index] && matriz[0][index] != '1')
        index++;
    while (matriz[0][index] && matriz[0][index] == '1')
    {
       
        if (matriz[0][index] == '1' && matriz[0][index + 1] == '1' &&
            (matriz[0][index - 1] != '1'))
        {
			wall->posA_x = 0;
			wall->posA_y = index;
        }
        if (matriz[0][index] == '1' && matriz[0][index + 1] != '1')
        {
            wall->posB_x = 0;
            wall->posB_y = index;
        }
        index++;
    }
}

void	next_line(char **matriz, int rows)
{
	int f;
	int c;
	int wall_closeX;
	int wall_closeY;

	f = 1;
	wall_closeX = 0;
	wall_closeY = 0;
	while (matriz[f])
	{
		c = 0;
		if (f == rows)
		{
			f++;
		}
		else
		{	while (matriz[f][c])
			{
				while (matriz[f][c] != '1')
					c++;
				if (c == 0)
				{
					if (matriz[f - 1][c] == '1' || matriz[f - 1][c + 1] == '1')
						wall_closeX = 1;
				}
				else if (matriz[f - 1][c - 1] == '1' || matriz[f - 1][c] == '1' || matriz[f - 1][c + 1] == '1')
				{
					wall_closeX = 1;
				}
				while (matriz[f][c] != '1')
					c++;
				
			}	
			f++;
		}
	}
}

void    wall_control(char **matriz, int rows, int columns)
{
    t_wall  wall;

	if (columns >= 3 && rows >= 3)
	{
    	wall.posA_x = 5;
    	wall.posA_y = 5;
    	wall.posB_x = 3;
    	wall.posB_y = 3;
    	firts_line(&wall, matriz);
		next_line(matriz, rows);
		printf("\n(%d, %d)\n",wall.posA_x, wall.posA_y);
		printf("\n(%d, %d)\n",wall.posB_x, wall.posB_y);
	}
	else
	{
		printf("Error de mapa");
	}
	
}