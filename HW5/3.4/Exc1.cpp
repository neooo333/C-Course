#include "Line_h.hpp"
#include <iostream>

using namespace std;
using namespace Mikita::CAD;

// Exc 3.4: create a default Line and count Point ctor / dtor / assignment calls.
//  Version A / Version B in Line_functions.cpp to compare assignment vs colon syntax.

int main () {
    cout << "=== Creating Line l; ===" << endl;
    Line l;
    /*
    If using assignment inside Line's default constructor, this sequence runs for Line l;:

        Point default constructor          // member start
        Point default constructor          // member finish
        Default Line constructor was called
        Point default constructor          // temporary from Point()
        Point assignment operator          // start = temporary
        Point destructor (0, 0)            // temporary destroyed
        Point default constructor          // temporary from Point()
        Point assignment operator          // finish = temporary
        Point destructor (0, 0)            // temporary destroyed

    Members start and finish are default-constructed before the Line body runs.
    Then start = Point() / finish = Point() create temporaries and overwrite those
    already-built members via operator=. The members are used; their data is
    reassigned. Colon syntax constructs them once and skips the assign/temp cycle.
    When main ends, start and finish are destroyed as well.
    */

    return 0;
}
