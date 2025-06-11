#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main()
{
    int g_driver = DETECT, g_mode;
    long x_center, y_center;
    long a, b;
    long x, y;
    long a_sqr, b_sqr;
    long fx, fy;
    float d;
    float tmp1, tmp2;

    clrscr();
    initgraph(&g_driver, &g_mode, "C:\\TURBOC3\\BGI");

    printf("*** MID POINT ELLIPSE ALGORITHM ***\n");
    printf("\nEnter coordinates x and y: ");
    scanf("%ld%ld", &x_center, &y_center);
    printf("Enter constants a and b: ");
    scanf("%ld%ld", &a, &b);

    x = 0;
    y = b;
    a_sqr = a * a;
    b_sqr = b * b;
    fx = 2 * b_sqr * x;
    fy = 2 * a_sqr * y;

    d = b_sqr - (a_sqr * b) + (0.25 * a_sqr);

    // Region 1
    while (fx < fy)
    {
        putpixel(x_center + x, y_center + y, WHITE);
        putpixel(x_center - x, y_center + y, WHITE);
        putpixel(x_center + x, y_center - y, WHITE);
        putpixel(x_center - x, y_center - y, WHITE);

        if (d < 0)
        {
            d = d + fx + b_sqr;
        }
        else
        {
            y = y - 1;
            fy = fy - (2 * a_sqr);
            d = d + fx - fy + b_sqr;
        }

        x = x + 1;
        fx = fx + (2 * b_sqr);
        delay(10);
    }

    // Region 2
    tmp1 = (x + 0.5) * (x + 0.5);
    tmp2 = (y - 1) * (y - 1);
    d = (b_sqr * tmp1) + (a_sqr * tmp2) - (a_sqr * b_sqr);

    while (y > 0)
    {
        putpixel(x_center + x, y_center + y, WHITE);
        putpixel(x_center - x, y_center + y, WHITE);
        putpixel(x_center + x, y_center - y, WHITE);
        putpixel(x_center - x, y_center - y, WHITE);

        if (d >= 0)
        {
            d = d - fy + a_sqr;
        }
        else
        {
            x = x + 1;
            fx = fx + (2 * b_sqr);
            d = d + fx - fy + a_sqr;
        }

        y = y - 1;
        fy = fy - (2 * a_sqr);
        delay(10);
    }

    getch();
    closegraph();
}
