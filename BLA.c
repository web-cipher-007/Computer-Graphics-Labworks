#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main()
{
int gd=DETECT,gm,x1,y1,x2,y2,Lx,Ly,dy,dx,pk,i;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

printf("put the value of x1 and y1\n");
scanf("%d%d",&x1,&y1);

printf("put the value of x2 and y2\n");
scanf("%d%d",&x2,&y2);

dx=abs(x2-x1);
dy=abs(y2-y1);

if(x2>x1)
{
Lx=1;
}
else
{
Lx=-1;
}
if(y2>y1)
{
Ly=1;
}
else
{
Ly=-1;
}
putpixel(x1,y1,RED);
if(dx>dy)
{
pk=2*dy-dx;
for(i=0;i<dx;i++)
{
if(pk<0)
{
x1=x1+Lx;
y1=y1;
pk=pk+2*dy;
}

else
{
x1=x1+Lx;
y1=y1+Ly;
pk=pk+2*dy-2*dx;
}
putpixel(x1,y1,RED);
}
}
else
{
pk=2*dx-dy;
for(i=0;i<dy;i++)
{
if(pk<0)
{
x1=x1;
y1=y1+Ly;
pk=pk+2*dx;
}
else
{
x1=x1+Lx;
y1=y1+Ly;

pk=pk+2*dx-2*dy;
}
putpixel(x1,y1,RED);
}
}
getch();
closegraph();
}

