#include <graphics.h>
#include <cmath>   
#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2;

    // 1. Take input BEFORE initializing the graphics window
    cout << "Enter starting coordinates (x1 y1): ";
    cin >> x1 >> y1;
    
    cout << "Enter ending coordinates (x2 y2): ";
    cin >> x2 >> y2;

    // 2. Initialize graphics window (640 x 480 pixels)
    initwindow(640, 480);

    // Calculate absolute differences
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    
    // Determine the direction to step in (either +1 or -1)
    int stepx = (x1 < x2) ? 1 : -1;
    int stepy = (y1 < y2) ? 1 : -1;

    int x = x1;
    int y = y1;

    // Plot the very first pixel
    putpixel(x, y, WHITE);

    // CASE 1: Gentle slope (dx > dy)
    if (dx > dy) {
        // Your decision parameter: p = 2dy - dx
        int p = 2 * dy - dx;
        
        for (int i = 0; i < dx; i++) {
            if (p >= 0) {
                y += stepy;
                p -= 2 * dx; // Same as p = p + 2dy - 2dx (we add 2dy below)
            }
            x += stepx;
            p += 2 * dy;
            
            putpixel(x, y, WHITE);
        }
    } 
    // CASE 2: Steep slope (dy >= dx)
    else {
        // Decision parameter flips because y is growing faster than x
        int p = 2 * dx - dy;
        
        for (int i = 0; i < dy; i++) {
            if (p >= 0) {
                x += stepx;
                p -= 2 * dy; 
            }
            y += stepy;
            p += 2 * dx;
            
            putpixel(x, y, WHITE);
        }
    }

    // Keep window open until a key is pressed
    getch();
    closegraph();
    return 0;
}