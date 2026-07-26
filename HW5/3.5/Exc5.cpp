#include "Circle_h.hpp"
#include "point_h.hpp"
#include "Line_h.hpp"
// #include <iostream>
using namespace Mikita::CAD;
using namespace std;

int main (){

    // Cheking that Print will be caleed from child class

    // Creating default objects
    Point std_point;
    Line std_line;
    Circle std_cirlce;

    //Checking Print functionlaity 

    std_point.Print();
    std_line.Print ();
    std_cirlce.Print ();

    // Output of the Print function is child specific even though there is no implementation in these classes.
    // Since ToString is virtual the implementatio is taken from child classes 

    return 0;
}