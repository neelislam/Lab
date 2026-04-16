#include<graphics.h>
#include<math.h>
#include<iostream>
using namespace std;


int main(){
    // int gd=DETECT, gm;
    // initgraph(&gd , &gm , "");
    initwindow(640, 480);

    int midx = getmaxx() / 2;
    int midy = getmaxy() / 2;



    // darw axis
    setcolor(RED);
    line(0, midy, getmaxx() , midy); // X-axis
    line(midx, 0, midx , getmaxy()); // Y-axis


    int x1 = 0, y1 = 0; // ALWAYS BY FORMULA --> SINCE ABOUT ORIGIN
    int x2 = 150, y2 = 0;

    //convert screen coordinates
    int sx1 = midx + x1; 
    int sy1 = midy - y1;
    int sx2 = midx + x2;
    int sy2 = midy - y2;

    //now draw this line
    line(sx1, sy1, sx2, sy2);


    return 0;
}