#include "point_h.hpp"
#include <iostream>
using namespace std;


int main () {

    double x_value_init;
    double y_value_init;

    cout << "Enter the first number: ";
    cin >> x_value_init;

    cout << "Enter the second number: ";
    cin >> y_value_init;

    // Exercise 1: default constructor + setters
    Point new_point;
    new_point.SetX(x_value_init);
    new_point.SetY(y_value_init);

    cout << new_point.ToString() << endl;
    cout << "The value of X: " << new_point.GetX() << endl;
    cout << "The value of Y: " << new_point.GetY() << endl;

    // Exercise 2: distance to origin and to another point
    cout << "Distance from Origin: " << new_point.DistanceOrigin() << endl;

    cout << "Creating second point with coordinates (-1.5, 1)" << endl;
    Point point2(-1.5, 1);

    cout << "Distance between " << new_point.ToString() << " and " << point2.ToString()
         << " : " << new_point.Distance(point2) << endl;

    return 0;
}