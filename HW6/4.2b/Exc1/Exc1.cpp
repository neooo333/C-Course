#include "array.hpp"
#include <iostream>

using namespace Mikita::Containers;
using namespace std;

int main (){
    Array<int> intArray1;
    Array<int> intArray2;
    Array<double> doubleArray;

    // Prints 10, 10, 10. Each template specialization starts with its own
    // default_size initialized to 10. Both Array<int> objects share one value,
    //while Array<double> has a separate value
    cout << intArray1.DefaultSize() << endl;
    cout << intArray2.DefaultSize() << endl;
    cout << doubleArray.DefaultSize() << endl;

    // Changes the static default_size shared by every Array<int> object.
    // does not change Array<double>::default_size.
    intArray1.DefaultSize(15);

    // Prints 15, 15, 10. intArray1 and intArray2 see the same shared
    // Array<int>::default_size, but doubleArray reads Array<double>::default_size.
    // The existing arrays' actual sizes remain 10; only the default used for future Array<int> objects has changed.
    cout << intArray1.DefaultSize() << endl;
    cout << intArray2.DefaultSize() << endl;
    cout << doubleArray.DefaultSize() << endl;

    return 0;
}
