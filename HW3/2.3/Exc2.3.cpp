#include "point_h.hpp"
#include "Circle_h.hpp"
#include <iostream>
using namespace std;


//Include Excersices 6 for "Improving your Classes"

int main () {

    // Create a circle with a center point and a radius
    Point test_point (0, 5);
    Circle new_circle (test_point, 5.0);

    // Getters
    cout << "Radius: " << new_circle.radius() << endl;
    cout << "Center: " << new_circle.center().ToString() << endl;

    // Metrics
    cout << "Diameter: " << new_circle.diameter() << endl;
    cout << "Area: " << new_circle.area() << endl;
    cout << "Circumference: " << new_circle.circumference() << endl;
    // ToString
    cout << new_circle.ToString() << endl;

    //Setters
    new_circle.radius(10.0);
    new_circle.center(Point(-1.5, 1));

    cout << "After changing radius and center:" << endl;
    cout << new_circle.ToString() << endl;

    return 0;
}
