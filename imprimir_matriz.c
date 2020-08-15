#include "cub.h"

void imprimir_matriz(t_pos_py *pos)
{
    int x,y;

    x = 0;
    while (x < pos->rows)
    {
        y = 0;
        while (y < pos->columns)
        {
            if (pos->map[x][y] == '8')
                printf("8888");
            else if (pos->map[x][y] == '1')
                printf("||||");
            else if (pos->map[x][y] == '0')
                printf("    ");
            else if (pos->map[x][y] == '2')
                printf(" ** ");
            else if (pos->map[x][y] == 'N')
                printf(" ;) ");
            y++;
        }
        printf("\n");
        x++;
    }
    printf("\n");
}