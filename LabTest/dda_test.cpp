#include <graphics.h>
#include <cmath>
#include <iostream>
using namespace std;


int main(){
    initwindow(800, 600);
    int x1, y1, x2, y2;
    std::cout << "Enter the coordinates of the first point (x1, y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Enter the coordinates of the second point (x2, y2): ";
    std::cin >> x2 >> y2;


    int dx = x2 - x1;
    int dy = y2 - y1;

    float m = dx/dy;
    int x = x1;
    int y = y1;


    if (  m >= -1 && m<= 1 )
    {
        cout << "1st condition triggered" <<endl;

        while ( x != x2 && y != y2 )
        {
            cout<< "Drawing the point: " << round(x) << " " << round(y) <<endl ;
            putpixel(round(x), round(y), YELLOW);

            x = x + 1;
            y = y + m;
        }
        cout<< "Drawing the point: " << round(x) << " " << round(y) <<endl ;
        putpixel(round(x), round(y), YELLOW);

    }
    if (m > 1){
        cout << "2nd condition triggered" <<endl;

        while ( x != x2 && y != y2 )
        {
            cout<< "Drawing the point: " << round(x) << " " << round(y) <<endl ;
            putpixel(round(x), round(y), YELLOW);

            x = x + 1/m;
            y = y + 1;
        }
        cout<< "Drawing the point: " << round(x) << " " << round(y) <<endl ;
        putpixel(round(x), round(y), YELLOW);






    }

    

getch();
closegraph();




    return 0; 
}