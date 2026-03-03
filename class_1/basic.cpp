#include <graphics.h>
#include <stdio.h>
int main()
{
    // Creates a 640x480 window
    initwindow(640, 480); // initialise graphics window

    line(100, 100, 200, 200);  // draw a line
    circle(100, 300, 30);       // draw a circle
    rectangle(50, 200, 300, 400); // draw a rectangle

    getch(); // wait for a key press
    closegraph();
    return 0;
}