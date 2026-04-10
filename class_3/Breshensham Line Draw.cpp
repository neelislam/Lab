#include <graphics.h>
#include <cmath>   

int main() {
    initwindow(640, 480);
    int x1 = 100, y1 = 100;
    int x2 = 500, y2 = 300; 
    
    int dx = x2 - x1;
    int dy = y2 - y1;

    int p = 2 * dy - dx;
    int x = x1;
    int y = y1;
    while (x <= x2) {
        putpixel(x, y, WHITE);
        x++; 
        if (p < 0) {
            p = p + 2 * dy;
        } else {
            y++; 
            p = p + 2 * dy - 2 * dx; 
        }
    }

    getch();

    closegraph();
    
    return 0;
}