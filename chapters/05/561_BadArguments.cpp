#include "../../std_lib_facilities.h"

class Bad_area{};   // a type specifically for reporting errors from area()

// calculate area of a rectangle;
// throw a Bad_area expection in case of a bad argument

int area(int length, int width)
{
    if (length <= 0 || width <= 0) throw Bad_area{};
    return length*width;
}

int framed_area(int x, int y)    // calculate area within frame
{
    return area(x-2,y-2);
}

int main()
try{
    int x = -1;
    int y = 2;
    int z = 4;
    //...
    int area1 = area(x,y);
    int area2 = framed_area(1,z);
    int area3 = framed_area(y,z);
    double ratio = area1/area3;
}

catch (Bad_area){
    cout << "Oops! bad arguments to area()\n";
}