#include "Line_h.hpp"
#include "point_h.hpp"
#include "Circle_h.hpp"
#include <iostream>
#include <ostream>
using namespace std;



int main (){

    Point default_point (1,1);
    Point default_point2 (2, 2);

    cout << "Default Point: " << default_point.ToString() << endl;

    cout << "Default point after '-' operator: " << (-default_point).ToString() << endl;

    cout << "Default point after '*' operator with value 5 "
        << endl << (default_point * 5).ToString() <<endl;

    cout << "Default point after '+' operator with default point 2: "
        << endl << (default_point + default_point2).ToString() <<endl;

    cout << "Comparing defualt point against default point 2. The values are " 
        << ((default_point == default_point2) ? "matching " : "not matching ") << endl;

    cout << "Assigning value default point2 values to default point: " 
        << (default_point = default_point2).ToString() <<endl;

    cout << "Scale the coordinates and assign with value 6: "
        << (default_point *= 6).ToString() << endl;

    Circle circle1 (default_point, 5);
    Circle circle2 (default_point2, 7);

    cout << "Circle2 values assigned to Circel1: " 
        << (circle1 = circle2).ToString() << endl; 

    Line line1 (Point (3,4), Point (1,2));
    Line line2 (Point (3,2), Point (1,2));

    cout << "Line2 values assigned to Line1: " 
        << (line1 = line2).ToString() << endl;   
    return 0;
}