#include <iostream>
#include <cmath>
#include <graphics.h>

int main(){
    initwindow(640, 480);
    int x1 = 100, y1 = 200, x2 = 300, y2 = 400;
    // std::cout << "Enter the coordinates of the starting point (x1, y1): ";
    // std::cin >> x1 >> y1;
    // std::cout << "Enter the coordinates of the ending point (x2, y2): ";
    // std::cin >> x2 >> y2;


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
            p = p + 2 * dy - 2;
        }
    }

    getch();
    closegraph();
    return 0;
}