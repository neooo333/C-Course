#include "Point_array.hpp"
#include <iostream>
using namespace std;

int main (){

    Array default_array;

    Array default_array2 (2);

    Point test_point (3,2);

    default_array2.SetElement(0,test_point);

    for (int i = 0; i < default_array2.Size(); i++){
        cout << default_array2.GetElement(i) <<endl;
    }

    Point test_point2 (5,5);

    default_array2[1] = test_point2;

    cout << default_array2[101] <<endl;

    for (int i = 0; i < default_array2.Size(); i++){
        cout << default_array2.GetElement(i) <<endl;
    }

    // Copy constructor test
    Array copied_array = default_array2;
    cout << "Copied array:" << endl;
    for (int i = 0; i < copied_array.Size(); i++){
        cout << copied_array.GetElement(i) <<endl;
    }

    // assignment operator test
    Array assigned_array (2);
    assigned_array = default_array2;
    cout << "Assigned array:" << endl;
    for (int i = 0; i < assigned_array.Size(); i++){
        cout << assigned_array.GetElement(i) <<endl;
    }

    // Self-assignment test
    assigned_array = assigned_array;
    cout << "After self-assignment:" << endl;
    for (int i = 0; i < assigned_array.Size(); i++){
        cout << assigned_array.GetElement(i) <<endl;
    }

    const Array default_array3 (2);

    /* 
    Would not work 
    defaul_array3[0] = test_point2;
    */

    cout << "Const array element: " << default_array3[0] << endl;
    return 0;
}
