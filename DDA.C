#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, steps;
    float dx, dy, x, y, xinc, yinc;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Digital Differential Analyzer (DDA) Line Drawing Algorithm\n");

    printf("Enter x1 and y1: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter x2 and y2: ");
    scanf("%d%d", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    xinc = dx / steps;
    yinc = dy / steps;

    x = x1;
    y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel((int)(x + 0.5), (int)(y + 0.5), RED);
        x += xinc;
        y += yinc;
    }

    getch();
    closegraph();
}
