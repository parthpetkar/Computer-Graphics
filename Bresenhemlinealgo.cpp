#include <stdio.h>
#include "graphics.h"
int DDA(int x0, int y0, int x1, int y1) {
    int dx, dy, p, x, y, steps,i;
    dx = (float)(x1 - x0);
    dy = (float)(y1 - y0);

    float abs_dx = dx >= 0 ? dx : -dx;
    float abs_dy = dy >= 0 ? dy : -dy;

    if (abs_dx >= abs_dy) {
        steps = abs_dx;
    }
    else {
        steps = abs_dy;
    }

    dx = dx / steps;
    dy = dy / steps;

    x = x0;
    y = y0;
    i = 1;

    while (i <= steps) {
        putpixel((int)x, (int)y, WHITE);
        x += dx;
        y += dy;
        i = i + 1;
    }

    getch();
    closegraph();

    return 0;
}

void Bresenhem(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y,m;
    dx = x1 - x0;
    dy = y1 - y0;
    x = x0;
    y = y0;
    m = dy / dx;
    if (m < 1)
    {
        p = 2 * dy - dx;
        while (x <= x1)
        {
            putpixel(x, y, WHITE);
            if (p >= 0)
            {
                y = y + 1;
                p += 2 * dy - 2 * dx;
            }
            else
            {
                p += 2 * dy;
            }
            x++;
        }
    }
    else
    {
        p = 2 * dx - dy;
        while (y <= y1)
        {
            putpixel(x, y, WHITE);
            if (p >= 0)
            {
                y++;
                p += 2 * dy - 2 * dx;
            }
            else
            {
                p += 2 * dy;
            }
            x++;
        }
    }
}

int main()
{
    int gdriver = DETECT, gmode, x0, y0, x1, y1;
    initgraph(&gdriver, &gmode, "");
    printf("Enter coordinates of the first point: ");
    scanf_s("%d%d", &x0, &y0);
    printf("Enter coordinates of the second point: ");
    scanf_s("%d%d", &x1, &y1);
    Bresenhem(x0, y0, x1, y1);
    getch();
    closegraph();
    return 0;
}
