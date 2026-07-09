#include "point_h.hpp"
#include "Line_h.hpp"
#include "iostream"
using namespace std;



int main (){

    // Checking frined functo that has access to private members 

    Point default_point (2);

    cout << default_point << endl;

    Line default_line (Point (1), Point (2));

    cout << default_line << endl;

    return 0;
}