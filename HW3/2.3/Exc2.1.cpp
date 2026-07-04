#include "point_h.hpp"
#include <iostream>
using namespace std;


//Include Excersices 1 - 4 for "Improving your Classes"

int main () {

    double x_value_init;
    double y_value_init;

    cout << "Enter the first number: ";
    cin >> x_value_init;

    cout << "Enter the second number: ";
    cin >> y_value_init;
    Point new_point;
    new_point.X(x_value_init);
    new_point.Y(y_value_init);


    cout << "Creating second point with coordinates (-1.5, 1)" << endl;
    Point point2(-1.5, 1);


    // Exc 1 Copy Constructor
    new_point.Distance(point2);


    //Exc 4 Const Functions

        //Creating an instance of const class
    
        const Point const_point;


        // Const Getters
        cout << const_point.X() << endl;
        cout << const_point.Y() << endl;

        //  Const  ToString and Distance 

        cout << const_point.Distance() << endl;
        cout << const_point.ToString() << endl;


    return 0;
}