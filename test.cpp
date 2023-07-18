/*#include "graphics.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


// Function to implement the DDA algorithm
void drawLineDDA(int x1, int y1, int x2, int y2) {

    int dx = x2 - x1;   //change in x
    int dy = y2 - y1;   //change in y

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    float x = (float)x1;
    float y = (float)y1;

    // Draw the first pixel
    putpixel(x, y, WHITE);

    for (int i = 0; i < steps; i++) {
        x += xIncrement;
        y += yIncrement;
        putpixel(round(x), round(y), 14);
        getch();
    }
}

void draw_line(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps, k;
    float x = x1, y = y1;
    float slope = (float)dy / dx;

    // Determine the number of steps needed
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    // Set the initial point
    putpixel(x, y, WHITE);

    // Draw the line
    if (slope < 1) {
        if (x1 < x2) {
            for (k = 0; k < steps; k++) {
                x += 1;
                y += slope;
                putpixel(round(x), round(y), WHITE);
                getch();
            }
        }
        else {
            for (k = 0; k < steps; k++) {
                x -= 1;
                y -= slope;
                putpixel(round(x), round(y), WHITE);
                getch();
            }
        }
    }
    else {
        if (y1 < y2) {
            for (k = 0; k < steps; k++) {
                x += 1 / slope;
                y += 1;
                putpixel(round(x), round(y), WHITE);
                getch();
            }
        }
        else {
            for (k = 0; k < steps; k++) {
                x -= 1 / slope;
                y -= 1;
                putpixel(round(x), round(y), WHITE);
                getch();
            }
        }
    }
}


int main() {

    int x1 = 20, y1 = 100;   // Starting point coordinates
    int x2 = 50, y2 = 300;   // Ending point coordinates

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    draw_line(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}*/
#include "graphics.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Function to implement Bresenhams line drawing algorithm

void bresenhamline(float x1, float y1, float x2, float y2)
{


    float dx = x2 - x1;   //change in x
    float dy = y2 - y1;   //change in y
    
    float m = dy / dx;

    if (m < 1)
    {
        float x = x1;
        float y = y1;
        float p = 2 * dy - dx;
        while (x <= x2)
        {
            putpixel(x, y, WHITE);
            x++;

            if (p < 0)
            {
                p = p + 2 * dy;
                
            }
            else
            {
                p = p + 2 * dy - 2 * dx;
                y++;
                
            }
        }
    }
    else
    {
        float x = x1;
        float y = y1;
        float p = 2 * dx - dy;
        while (x <= x2)
        {
            putpixel(x, y, WHITE);
            x++;

            if (p < 0)
            {
                p = p + 2 * dy;
             
            }
            else
            {
                p = p + 2 * dy - 2 * dx;
                y++;
                
            }
        }
    }
}
   

int main()
{

    int x1;
    int y1;
    int x2;
    int y2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    printf("Enter the coordinates of the starting and ending points\n");
    scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);

    bresenhamline(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;
}