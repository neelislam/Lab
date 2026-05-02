#include <iostream>
#include <cmath>
#include <graphics.h>

int main() {
    initwindow(640, 480);          // Open graphics window

    // Draw a House (rectangle + triangle roof)
    rectangle(100, 300, 250, 400); // walls
    line(100, 300, 175, 220);      // left roof edge
    line(175, 220, 250, 300);      // right roof edge
    rectangle(170, 350, 190, 400); // door
    circle(240, 350, 10);          // window

    // Draw a Simple Car (rectangle + two circles)
    rectangle(350, 350, 500, 400); // body
    circle(380, 410, 20);          // left wheel
    circle(470, 410, 20);          // right wheel
    line(410, 350, 430, 320);      // windshield
    line(430, 320, 480, 320);      // roof
    line(480, 320, 500, 350);      // rear window

    // Draw a Fish (arcs and lines)
    arc(80, 150, 30, 150, 40);     // body (arc)
    line(80, 110, 80, 190);        // connect arc ends
    line(40, 150, 20, 130);        // tail top
    line(40, 150, 20, 170);        // tail bottom
    circle(70, 140, 3);            // eye

    // Draw a Man (circle + lines)
    circle(550, 200, 20);          // head
    line(550, 220, 550, 270);      // body
    line(550, 240, 520, 260);      // left arm
    line(550, 240, 580, 260);      // right arm
    line(550, 270, 530, 300);      // left leg
    line(550, 270, 570, 300);      // right leg

    getch();                       // wait for key press
    closegraph();                  // close graphics window
    return 0;
}