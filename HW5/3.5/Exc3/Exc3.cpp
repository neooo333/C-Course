#include "Point.hpp"
#include "Shape.hpp"
#include "Line.hpp"
#include <iostream>

using namespace Mikita::CAD;
using namespace std;

int main (){

    /*Without virtual ~Shape(), only Shape's destructor runs when deleting
    through Shape*. With virtual, Point and Line destructors are called first.
    */
    Shape* shapes[3];
    shapes[0] = new Shape;
    shapes[1] = new Point;
    shapes[2] = new Line;

    for (int i = 0; i < 3; i++) delete shapes[i];

    /*
    After making Shape destructor virtual: 
     Point: Point destructor, then Shape destructor
     Line: Line destructor, then Point/Shape for each endpoint Point, then Shape
    */ 

    return 0;
}
