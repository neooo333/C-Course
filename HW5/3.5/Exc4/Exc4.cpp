#include "Circle.hpp"
#include "Point.hpp"
#include "Shape.hpp"
#include "Line.hpp"
#include <iostream>

using namespace Mikita::CAD;
using namespace std;

int main (){

    // Shape std_shape; does not compile 

    Shape* shape_array[3]; //create pointers to Shape

    shape_array[0] = new Point;
    shape_array[1] = new Circle;
    shape_array[2] = new Line;

    for (int i = 0; i < 3; i++) {
        shape_array[i]->Draw(); // Virtual call  (derived Draw)
        cout << endl;
    }

    for (int i = 0; i < 3; i++) delete shape_array[i];

    return 0;
}
