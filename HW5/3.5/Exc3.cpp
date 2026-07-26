#include "point_h.hpp"
#include "Shape_h.hpp"
#include "Line_h.hpp"
// #include <iostream>
using namespace Mikita::CAD;
using namespace std;

int main (){

    /*
    The following code calls only Shape destructor but does not destroys Line, and Point objects on the heap 
    */ 
    Shape* shapes[3];
    shapes[0]=new Point; // Changed object from Shape to Point since for next excersice Shape class will become abstract. Does not complie if I leave it as Shape. 
    shapes[1]=new Point;
    shapes[2]=new Line;

    for (int i=0; i!=3; i++) delete shapes[i];

    // After updating Shape distructor with virtual. Destructors of other classes are called as well
    // in the case of Point: destrutor Point is called and then Shape 
    // In the case of Line: Line destructor called fist, then two sets of Point and Shape destructors are called for two Points instances in Line class

    return 0;
}