#include <graphics.h>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Original triangle points
    int x1 = 100, y1 = 100;
    int x2 = 150, y2 = 50;
    int x3 = 200, y3 = 100;

    // Draw original triangle (WHITE)
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Scaling factors
    float sx = 123.5, sy = 123.5;
    // cout << "Enter scaling factors (sx, sy): ";
    // cin >> sx >> sy;

    // Apply scaling
    int x1_new = x1 * sx;
    int y1_new = y1 * sy;

    int x2_new = x2 * sx;
    int y2_new = y2 * sy;

    int x3_new = x3 * sx;
    int y3_new = y3 * sy;

    // Draw scaled triangle (YELLOW)
    setcolor(YELLOW);
    line(x1_new, y1_new, x2_new, y2_new);
    line(x2_new, y2_new, x3_new, y3_new);
    line(x3_new, y3_new, x1_new, y1_new);



    getch();
    closegraph();
    return 0;
}