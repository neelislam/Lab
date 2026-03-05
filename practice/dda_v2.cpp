#include<graphics.h>
#include<iostream>

using namespace std;

int main()
{
    int x1, y1, x2, y2 ;
    float dx, dy,  x, y, m ;

    initwindow(640, 480);

    cout<< "enter coordinates sequentially(x1 , y1 , x2 ,y2 ):"<<endl ;
    cin>> x1 >> y1 >> x2 >> y2 ;

    dx = x2 - x1;
    dy = y2 - y1;

    m = dy/dx ;

    x = x1;
    y = y1;



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

    if ( abs(m) > 1)
    {
        cout << "2nd condition triggered" <<endl;

        while ( x != x2 && y != y2 )
        {
            cout<< "Drawing the point: " << round(x) << " " << round(y) <<endl ;
            putpixel(round(x), round(y), YELLOW);

            x = x + (1/m);
            y = y + 1;
        }
        cout<< "Drawing the point: " << round(x) << " " << round(y) <<endl ;
        putpixel(round(x), round(y), YELLOW);

    }



    getch();
    closegraph();
    return 0;
}