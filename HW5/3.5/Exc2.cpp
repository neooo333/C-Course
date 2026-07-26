#include "point_h.hpp"
#include "Shape_h.hpp"
#include "Line_h.hpp"
#include "Circle_h.hpp"
#include <iostream>
using namespace Mikita::CAD;
using namespace std;

int main (){

    // Caling default cinstructors 
    Point std_point;
    Line std_line;
    Circle std_circle;
    //Checking that ToString got updated with Shape functionality 
    cout << std_point.ToString() << endl;
    cout << std_line.ToString() << endl;
    cout << std_circle.ToString() << endl;
    // IDs will be printed for all instances

    return 0;
}