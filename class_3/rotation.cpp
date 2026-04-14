#include <graphics.h>
#include <math.h>
#include <iostream>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Origin (shifted to center of screen for better visualization)
    int midx = getmaxx() / 2;
    int midy = getmaxy() / 2;

    // Draw axes
    setcolor(LIGHTGRAY);
    line(0, midy, getmaxx(), midy); // X-axis
    line(midx, 0, midx, getmaxy()); // Y-axis

    // Original points A and B (relative to origin)
    int x1 = 0, y1 = 0; // ALWAYS BY FORMULA --> SINCE ABOUT ORIGIN
    int x2 = 150, y2 = 0;

    // Convert to screen coordinates
    int sx1 = midx + x1;
    int sy1 = midy - y1;
    int sx2 = midx + x2;
    int sy2 = midy - y2;

    // Draw original line (WHITE)
    setcolor(CYAN);
    line(sx1, sy1, sx2, sy2);

    // Rotation angle (in degrees)
    float theta;
    std::cout << "Enter angle (in degrees): ";
    std::cin >> theta;

    // Convert to radians
    float rad = theta * 3.1416 / 180;

    // Apply rotation formula
    int x1_new = x1 * cos(rad) - y1 * sin(rad);
    int y1_new = x1 * sin(rad) + y1 * cos(rad);

    int x2_new = x2 * cos(rad) - y2 * sin(rad);
    int y2_new = x2 * sin(rad) + y2 * cos(rad);

    // Convert rotated points to screen coordinates
    int sx1_new = midx + x1_new;
    int sy1_new = midy - y1_new;
    int sx2_new = midx + x2_new;
    int sy2_new = midy - y2_new;

    // Draw rotated line (YELLOW)
    setcolor(YELLOW);
    line(sx1_new, sy1_new, sx2_new, sy2_new);



    getch();
    closegraph();
    return 0;
}
