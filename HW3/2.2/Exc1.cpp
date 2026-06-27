#include "point_h.hpp"
#include <iostream>
using namespace std;


int main () {

    double x_value_init;
    double y_value_init;

    cout << "Enter the first number: ";
    cin >> x_value_init;

    // Ask for the second double
    std::cout << "Enter the second number: ";
    std::cin >> y_value_init;

    //Default constructor
    Point new_point;

    //Set x and Y points
    new_point.SetX(x_value_init);
    new_point.SetY(y_value_init);

    // Print values
    cout << new_point.ToString();

    cout << "The value of X: " << new_point.GetX() << endl;
    cout << "The value of Y: " << new_point.GetY() << endl;
    return 0;
}