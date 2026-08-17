#include "Point.hpp"
#include "Shape.hpp"
#include <iostream>

using namespace Mikita::CAD;
using namespace std;

int main () {

    Shape* default_shape; // creating Shape pointer
    Point default_point; // Creating default Point

    default_shape = &default_point; // Assigning Point address to Shape pointer


    cout << default_shape->ToString() << endl; //will return ToString from Point class as ToString is virtual now

    return 0;
}
