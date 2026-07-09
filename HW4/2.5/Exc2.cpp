#include "point_h.hpp"
#include <iostream>
using namespace std;


int main (){


    Point** heap_array_point = new Point * [3];

    heap_array_point[0] = new Point ();
    heap_array_point[1] = new Point (2,1);
    heap_array_point[2] = new Point (*heap_array_point[0]);


    for (int i= 0; i<3; i++){
        cout << *heap_array_point[i] << endl;
    }

    // deleting elements
    for (int i= 0; i<3; i++){
         delete heap_array_point[i];
    }

    delete [] heap_array_point;


    return 0;
}