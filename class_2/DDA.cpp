#include <graphics.h>
#include <cmath>   
#include <iostream>
#include <algorithm>  

using namespace std;

int main() {
    int x0, y0, x1, y1;

    
    cout << "Enter starting coordinates (x0 y0): ";
    cin >> x0 >> y0;
    
    cout << "Enter ending coordinates (x1 y1): ";
    cin >> x1 >> y1;

    // 2. Now initialize graphics window (640 x 480 pixels)
    initwindow(640, 480);

    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = std::max(std::abs(dx), std::abs(dy));


    if (steps == 0) {
        putpixel(x0, y0, WHITE);
        getch();
        closegraph();
        return 0;
    }

    float x_inc = dx / static_cast<float>(steps);
    float y_inc = dy / static_cast<float>(steps);

    float x_curr = x0;
    float y_curr = y0;

    for (int i = 0; i <= steps; ++i) {
        putpixel(static_cast<int>(std::round(x_curr)),
                 static_cast<int>(std::round(y_curr)), WHITE);
        x_curr += x_inc;
        y_curr += y_inc;
    }
   
    getch();
    closegraph();
    return 0;
}