#include <stdio.h>
#include <math.h>
#define PI 3.145672
void	horizontal_collisionA(float y, float x, float rayangle)
 {
     float Ay, Ax, tile=120; 
     int colX,colY;
     colX = (int)x / tile;
    colY = (int)y / tile;
    printf("A(%d, %d) \n", colY,colX);
	if (rayangle > PI)
		Ay = (int)(y / tile) *
		tile - 1;
	else
		Ay = (int)(y / tile) *
		tile + tile;
   Ax = x + (y - Ay) /
    tan(rayangle);
    colX = (int)Ax / tile;
    colY = (int)Ay / tile;
    printf("A(%d, %d) \n", colY,colX);
}

int main()
{
    float y=300, x=290;
    float angle=PI*1.5;
    horizontal_collisionA(y,x,angle);
    return(0);
}