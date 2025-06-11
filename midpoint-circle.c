#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void main() {
    int gd = DETECT, gm;
    int x, y, r, xc, yc, d;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("**** MIDPOINT Circle Drawing Algorithm ****\n");
    printf("Enter center coordinates (xc, yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter radius: ");
    scanf("%d", &r);

    x = 0;
    y = r;
    d = 1 - r;

    while (x <= y) {
        putpixel(xc + x, yc + y, BLUE);
        putpixel(xc + y, yc + x, BLUE);
        putpixel(xc - y, yc + x, BLUE);
        putpixel(xc - x, yc + y, BLUE);
        putpixel(xc - x, yc - y, BLUE);
        putpixel(xc - y, yc - x, BLUE);
        putpixel(xc + y, yc - x, BLUE);
        putpixel(xc + x, yc - y, BLUE);

        if (d < 0)
            d += 2 * x + 3;
        else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }

    getch();
    closegraph();
}
