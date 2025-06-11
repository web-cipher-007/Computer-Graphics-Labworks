#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int dx, dy, pk, i;
    int Lx, Ly;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter x1 and y1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter x2 and y2: ");
    scanf("%d %d", &x2, &y2);

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    Lx = (x2 > x1) ? 1 : -1;
    Ly = (y2 > y1) ? 1 : -1;

    putpixel(x1, y1, RED);

    if (dx > dy)
    {
        pk = 2 * dy - dx;
        for (i = 0; i < dx; i++)
        {
            if (pk < 0)
            {
                x1 += Lx;
                pk += 2 * dy;
            }
            else
            {
                x1 += Lx;
                y1 += Ly;
                pk += 2 * dy - 2 * dx;
            }
            putpixel(x1, y1, RED);
        }
    }
    else
    {
        pk = 2 * dx - dy;
        for (i = 0; i < dy; i++)
        {
            if (pk < 0)
            {
                y1 += Ly;
                pk += 2 * dx;
            }
            else
            {
                x1 += Lx;
                y1 += Ly;
                pk += 2 * dx - 2 * dy;
            }
            putpixel(x1, y1, RED);
        }
    }

    getch();
    closegraph();
}
