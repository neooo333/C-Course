#include "Line.hpp"
#include <iostream>

using namespace std;
using namespace Mikita::CAD;

//  Version A / Version B in Line.cpp to compare assignment vs colon syntax.

int main () {
    cout << "=== Creating Line l; ===" << endl;
    Line l;
    /*
    If using assignment inside Line's default constructor, the follwing sequence runs for Line l;:
    Point default constructor -  start
    Point default constructor -   finish
    Default Line constructor was called
    Point default constructor    // temporary from Point()
     Point assignment operator     // start = temporary
    Point destructor (0, 0)      // temporary destroyed
    Point default constructor      // temporary from Point()
    Point assignment operator     // finish = temporary
    Point destructor (0, 0)   // temporary destroyed

    Members start and finish are default-constructed before the Line body runs.
    Then start = Point() / finish = Point() create temporaries and overwrite those
    already built members via = operator . Colon syntax constructs them once and skips the assign/temp cycle.
    When main ends, start and finish are destroyed as well.
    */

    return 0;
}
