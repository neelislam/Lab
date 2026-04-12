#include <graphics.h>
#include <cmath>
#include <iostream>
using namespace std;

void cirlceplot(int xc, int yc, int x, int y) {
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
    int xc=200, yc=200, r=100;
    // cout << "Coordinates (xc yc): ";
    // cin >> xc >> yc;
    // cout << "Radius: ";
    // cin >> r;

    initwindow(640, 480);

    int x = 0;
    int y = r;
    int p = 1 - r;  

    cirlceplot(xc, yc, x, y);  

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        cirlceplot(xc, yc, x, y);
    }

    getch();
    closegraph();
    return 0;
}