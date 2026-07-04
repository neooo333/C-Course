#include "point_h.hpp"
#include "Line_h.hpp"
#include <iostream>
using namespace std;


//Include Excersices 5 for "Improving your Classes"

int main () {

    // Assigning values to a Line
    double x_value_first_point = 0, y_value_first_point = 5;
    double x_value_second_point = 3, y_value_second_point = 10;

    // Instance of a line created
    Line test_line (Point (x_value_first_point, y_value_first_point),
                    Point (x_value_second_point, y_value_second_point));

    // Funcstions Test

    cout << test_line.start_point().ToString() <<endl;
    cout << test_line.end_point().ToString() <<endl;

    //Reassigning values

    Point start_new (2.5,1);
    Point end_new (10,15.65);


    test_line.start_point (start_new);
    test_line.end_point(end_new);

    // Testing ToString
    cout << test_line.ToString() << endl;

    //Line Length

    cout<<test_line.Length() << endl;
    return 0;
}