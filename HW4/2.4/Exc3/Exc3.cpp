#include "Point.hpp"
#include <iostream>
using namespace std;


int main (){

/* Works, given implicit constructor
    Point p(1.0, 1.0);
    if (p==1.0) cout<<"Equal!"<<endl;
    else cout<<"Not equal"<<endl;
*/

// explicit constructor 

Point p(1.0, 1.0);
if (p==  (Point) 1.0) cout<<"Equal!"<<endl;

    return 0;
}