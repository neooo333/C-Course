#include "point_h.hpp"
#include <iostream>
using namespace std;



int main () {

    //Constructor with variables
    Point* test_point = new Point (1, 1);

    //Default constructor 
    Point* test_point2 = new Point ();

    //Copy Constructor

    Point* test_point3 = new Point (*test_point);

    // Output Point pointers (dereference before sending to cout)
    cout << *test_point << endl;
    cout << *test_point2 << endl;
    cout << *test_point3 << endl;

    //call distance function to cout 
    cout << (*test_point).Distance() << endl;
    cout << (*test_point2).Distance() << endl;
    cout << (*test_point3).Distance() << endl;



    //Asking for imput 
     int size;
     cout << "Input size of an array (int): ";
     cin >> size;

     /* error since size should be set at compile time 
       Point stack_array [size];
     */
    // creating the heap arra. Expecting no errors.

    Point* stack_array = new Point [size];

    for (int i = 0; i < size; i++){
        stack_array[i] = Point (i);
    }

    for (int i = 0; i < size; i++){
        cout << stack_array [i] << endl;
    }

    // Deleteing from the heap
    delete [] stack_array;
    delete test_point;
    delete test_point2;
    delete test_point3;

    return 0;
}