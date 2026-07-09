#include "Line_h.hpp"
#include "point_h.hpp"
#include "Circle_h.hpp"
#include <iostream>
#include <ostream>
using namespace std;



int main (){

    Point default_point;
    Point point (3, 4);

    cout << "Default point: " << default_point << endl;
    cout << "Point (3, 4): " << point << endl;

    Circle default_circle;
    Circle circle (point, 5);

    cout << "Default circle: " << default_circle << endl;
    cout << "Circle at (3, 4) r=5: " << circle << endl;

    Line default_line;
    Line line (Point (0, 0), Point (3, 4));

    cout << "Default line: " << default_line << endl;
    cout << "Line (0,0)-(3,4): " << line << endl;

    return 0;
}