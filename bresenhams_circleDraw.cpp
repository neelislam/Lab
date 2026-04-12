#include <graphics.h>
#include <iostream>
using namespace std;

// Plots the 8 symmetric points of a circle
void circlePlot(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, RED);
    putpixel(xc - x, yc + y, BLUE);
    putpixel(xc + x, yc - y, GREEN);
    putpixel(xc - x, yc - y, RED);
    putpixel(xc + y, yc + x, BLUE);
    putpixel(xc - y, yc + x, GREEN);
    putpixel(xc + y, yc - x, BLUE);
    putpixel(xc - y, yc - x, RED);
}

int main() {
    int xc = 200, yc = 200, r = 100;
    // Uncomment for user input:
    // cout << "Enter center (xc yc): ";
    // cin >> xc >> yc;
    // cout << "Enter radius: ";
    // cin >> r;

    initwindow(640, 480);

    int x = 0;
    int y = r;
    int d = 3 - 2 * r;          // Classic Bresenham decision parameter

    circlePlot(xc, yc, x, y);

    while (x <= y) {            // Loop until x exceeds y
        x++;
        if (d < 0) {
            d = d + 4 * x + 6;      // Choose pixel E (x+1, y)
        } else {
            y--;
            d = d + 4 * (x - y) + 10; // Choose pixel SE (x+1, y-1)
        }
        circlePlot(xc, yc, x, y);
    }

    getch();
    closegraph();
    return 0;
}