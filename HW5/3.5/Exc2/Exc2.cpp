#include "Point.hpp"
#include "Shape.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>

using namespace Mikita::CAD;
using namespace std;

int main (){

    // Calling default constructors
    Point std_point;
    Line std_line;
    Circle std_circle;

    // Calling ToString
    cout << std_point.ToString() << endl;
    cout << std_line.ToString() << endl;
    cout << std_circle.ToString() << endl;
    // IDs will be printed for all instances

    return 0;
}
