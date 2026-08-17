#include "Circle.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include <iostream>

using namespace Mikita::CAD;
using namespace std;

int main (){
    // Creating default objects
    Point std_point;
    Line std_line;
    Circle std_circle;

    // Print is only defined in Shape, but uses virtual ToString
    std_point.Print();
    std_line.Print();
    std_circle.Print();




    return 0;
}
