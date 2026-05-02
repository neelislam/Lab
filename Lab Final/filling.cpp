#include <iostream>
#include <graphics.h>

// Flood Fill (4‑connected) – replaces interior color (here: BLACK) with fill color
void floodFill(int x, int y, int fillColor, int interiorColor) {
    if (getpixel(x, y) == interiorColor) {
        putpixel(x, y, fillColor);
        floodFill(x + 1, y, fillColor, interiorColor);
        floodFill(x - 1, y, fillColor, interiorColor);
        floodFill(x, y + 1, fillColor, interiorColor);
        floodFill(x, y - 1, fillColor, interiorColor);
    }
}

// Boundary Fill (4‑connected) – fills until boundary color is met
void boundaryFill(int x, int y, int fillColor, int boundaryColor) {
    if (getpixel(x, y) != boundaryColor && getpixel(x, y) != fillColor) {
        putpixel(x, y, fillColor);
        boundaryFill(x + 1, y, fillColor, boundaryColor);
        boundaryFill(x - 1, y, fillColor, boundaryColor);
        boundaryFill(x, y + 1, fillColor, boundaryColor);
        boundaryFill(x, y - 1, fillColor, boundaryColor);
    }
}

int main() {
    initwindow(640, 480);

    // Draw a rectangular boundary
    rectangle(150, 100, 350, 300);
    // Set boundary color (WHITE) for both algorithms
    setcolor(WHITE);

    // Fill using Flood Fill – interior is BLACK (default background)
    floodFill(160, 110, RED, BLACK);
    // Wait a moment to see the flood fill
    delay(1500);

    // Clear the window and draw the same rectangle again
    cleardevice();
    rectangle(150, 100, 350, 300);
    setcolor(WHITE);

    // Fill using Boundary Fill – stops at WHITE boundary
    boundaryFill(160, 110, GREEN, WHITE);

    getch();
    closegraph();
    return 0;
}