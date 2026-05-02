#include <graphics.h>
#include <cmath>
#include <iostream>
using namespace std;

void CirclePlot(int xc, int yc, int x, int y) {

    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);

}


int main(){
    initwindow(640, 480);
    // int xc = 320, yc = 240, r = 100;
    int xc, yc, r;
    cout << "Enter the center of the circle (xc, yc): ";
    cin >> xc >> yc;
    cout << "Enter the radius of the circle: ";
    cin >> r;
    int x = 0, y = r;
    float p = 3 - 2 * r;
    CirclePlot(xc, yc, x, y);
    while(x < y) {
        x++;
        if(p < 0) {
            p = p + 4 * x + 6;}
            else{
                y--;
                p = p + 4 * (x - y) + 10;
            }
            CirclePlot(xc, yc, x, y);
        }
    getch();
    closegraph();
    return 0;
}