#include "Shape_h.hpp"
#include "point_h.hpp"
#include "Line_h.hpp"
#include <iostream>

using namespace Mikita::CAD;
using namespace std;


int main (){

    Shape s; // Create shape.
    Point p(10, 20); // Create point.
    Line l(Point(1,2), Point(3, 4)); // Create line.
    cout<<s.ToString()<<endl; // Print shape.
    cout<<p.ToString()<<endl; // Print point.
    cout<<l.ToString()<<endl; // Print line
    cout<<"Shape ID: "<<s.ID()<<endl; // ID of the shape.
    cout<<"Point ID: "<<p.ID()<<endl; // ID of the point. Does this work? 
    // It does, since point inherit all functionality and attributes of the parent class. In this case attrubute ID and method ID ().
    cout<<"Line ID: "<<l.ID()<<endl; // ID of the line. Does this work?
    // Same as for Point. Line class inherits from shape. 
    Shape* sp; // Create pointer to a shape variable.
    sp=&p; // Point in a shape variable. Possible? // Possible since Point is a Shape as well.
    cout<<sp->ToString()<<endl; // What is printed?
    // Shape::ToString() ("ID: ..."), not Point::ToString(). ToString is not virtual,
    // so the call is resolved by the pointer type (Shape*), not the dynamic type.
    // Create and copy Point p to new point.
    Point p2;
    p2=p;
    cout<<p2<<", "<<p2.ID()<<endl; // Is the ID copied if you do not call
    // the base class assignment in point?
    // No. Without Shape::operator= in Point::operator=, only m_x/m_y are copied;
    // p2 keeps the ID it got from its own Shape construction.

    return 0;
}

