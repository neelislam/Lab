#include <graphics.h>
#include <cmath>   
#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    cout << "Enter starting coordinates (x1 y1): ";
    cin >> x1 >> y1;
    
    cout << "Enter ending coordinates (x2 y2): ";
    cin >> x2 >> y2;

    initwindow(640, 480);

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int stepx = (x1 < x2) ? 1 : -1;
    int stepy = (y1 < y2) ? 1 : -1;

    int x = x1;
    int y = y1;
    putpixel(x, y, WHITE);

    if (dx > dy) {

        int p = 2 * dy - dx;
        
        for (int i = 0; i < dx; i++) {
            if (p >= 0) {
                y += stepy;
                p -= 2 * dx; 
            }
            x += stepx;
            p += 2 * dy;
            
            putpixel(x, y, WHITE);
        }
    } 
  
    else {
       
        int p = 2 * dx - dy;
        
        for (int i = 0; i < dy; i++) {
            if (p >= 0) {
                x += stepx;
                p -= 2 * dy; 
            }
            y += stepy;
            p += 2 * dx;
            
            putpixel(x, y, WHITE);
        }
    }

    
    getch();
    closegraph();
    return 0;
}