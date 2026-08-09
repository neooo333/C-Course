#include "point.hpp"
#include "pointarray.hpp"
#include "array_exception.hpp"
#include <iostream>

using namespace Mikita::Containers;
using Mikita::CAD::Point;
using namespace std;

int main(){
    // Default constructor (size = DefaultSize)
    PointArray test_array;
    cout << "Default PointArray size: " << test_array.Size() << endl;

    // Size constructor
    PointArray pts(4);
    pts[0] = Point(0.0, 0.0);
    pts[1] = Point(3.0, 0.0);
    pts[2] = Point(3.0, 4.0);
    pts[3] = Point(0.0, 4.0);
    cout << "Points: ";
    for (int i = 0; i < pts.Size(); i++) {
        cout << pts[i] << " ";
    }
    cout << endl;

    // Length
    cout << "Length(): " << pts.Length() << endl;

    // Copy constructor
    PointArray copy(pts);
    cout << "Copy Length(): " << copy.Length() << endl;

    // Assignment
    PointArray assigned;
    assigned = pts;
    cout << "Assigned Length(): " << assigned.Length() << endl;

    // Single-point array: Length should be 0
    PointArray one(1);
    one[0] = Point(1.0, 1.0);
    cout << "Single-point Length(): " << one.Length() << endl;

    //Inherited Array access still throws on bad index
    try {
        cout << pts[10] << endl;
    } catch (const ArrayException& e) {
        cout << e.GetMessage() << endl;
    }

    return 0;
}
