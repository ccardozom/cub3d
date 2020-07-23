#include "cub.h"

void imprimir_matriz(t_pos_py *pos)
{
    int x,y;

    x = 0;
    while (x < pos->map_f)
    {
        y = 0;
        while (y < pos->map_c)
        {
            printf("[%c] ", pos->map[x][y]);
            y++;
        }
        printf("\n");
        x++;
    }
}