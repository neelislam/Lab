#include <graphics.h>
#include <cmath>
#include <iostream>
using namespace std;

int main(){
    int x1=30, y1=40, x2=60, y2=30, x3=40, y3=80;
    //translation
    int Tx=15, Ty=30;
    initwindow(800, 600);
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);


    int x1_t = x1 + Tx;
    int y1_t = y1 + Ty;
    int x2_t = x2 + Tx;
    int y2_t = y2 + Ty;
    int x3_t = x3 + Tx;
    int y3_t = y3 + Ty;

    setcolor(YELLOW);
    line(x1_t, y1_t, x2_t, y2_t);
    line(x2_t, y2_t, x3_t, y3_t);
    line(x3_t, y3_t, x1_t, y1_t);

    //scaling 
    int Sx=4, Sy=1;
    int x1_s = x1 * Sx;
    int y1_s = y1 * Sy;
    int x2_s = x2 * Sx;
    int y2_s = y2 * Sy;
    int x3_s = x3 * Sx;
    int y3_s = y3 * Sy;
    setcolor(GREEN);
    line(x1_s, y1_s, x2_s, y2_s);
    line(x2_s, y2_s, x3_s, y3_s);
    line(x3_s, y3_s, x1_s, y1_s);


    //rotation

    int midx = getmaxx() / 2;
    int midy = getmaxy() / 2;
    // Draw axes
    setcolor(LIGHTGRAY);
    line(0, midy, getmaxx(), midy); // X-axis
    line(midx, 0, midx, getmaxy()); // Y-axis

    //screen coordinate 
    int sx1 = midx + x1;
    int sy1 = midy - y1;
    int sx2 = midx + x2;
    int sy2 = midy - y2;
    int sx3 = midx + x3;
    int sy3 = midy - y3;
    
    //white original line
    setcolor(CYAN);
    line(sx1, sy1, sx2, sy2);
    line(sx2, sy2, sx3, sy3);
    line(sx3, sy3, sx1, sy1);
  //convert to radian
    float theta= 45.0;

    float rad = theta * 3.1416 / 180;

    int x1_new = x1 * cos(rad) - y1 * sin(rad);
    int y1_new = x1 * sin(rad) + y1 * cos(rad);
    int x2_new = x2 * cos(rad) - y2 * sin(rad);
    int y2_new = x2 * sin(rad) + y2 * cos(rad);
    int x3_new = x3 * cos(rad) - y3 * sin(rad);
    int y3_new = x3 * sin(rad) + y3 * cos(rad);


    int sx1_new = midx + x1_new;
    int sy1_new = midy - y1_new;
    int sx2_new = midx + x2_new;
    int sy2_new = midy - y2_new;
    int sx3_new = midx + x3_new;
    int sy3_new = midy - y3_new;
    

    //holud rotate er por
    setcolor(YELLOW);
    line(sx1_new, sy1_new, sx2_new, sy2_new);
    line(sx2_new, sy2_new, sx3_new, sy3_new);
    line(sx3_new, sy3_new, sx1_new, sy1_new);
    getch();
    closegraph();
    return 0;
}