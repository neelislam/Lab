#include <graphics.h>
#include <cmath>
#include <iostream>
using namespace std;

void circlePoints(int xc, int yc, int x, int y){
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
}

int main(){
    initwindow(640, 480);
    int xc = 320, yc = 240,  r = 100;
    

    int x = 0 , y = r;
    int p = 1 - r;

    circlePoints(xc, yc, x, y);
    while(x < y) {
        x++;
        if(p < 0){
            p +=  2 * x + 1;

        }

        else {
            y--;
            p += 2*(x-y) + 1;
        }
        circlePoints(xc, yc, x, y);
      

}
    getch();
    closegraph();
    return 0;
}