#include "point_h.hpp"
#include "Shape_h.hpp"
#include "iostream"

using namespace Mikita::CAD;
using namespace std;

int main () {


    Shape* default_shape; //Creating Shape pointer
    Point default_point; // Creating default Point 

    default_shape = &default_point; //Assigning Point address to Shape pointer 

    cout<< default_shape->ToString() <<endl; // Checking that ToString is called from Point class

    return 0;
}