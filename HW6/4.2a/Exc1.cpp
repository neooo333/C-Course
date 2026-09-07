#include "Point.hpp"
#include "Array.hpp" // this .hpp file includes array.cpp that is why I am including array.hpp and not array.cpp
#include "iostream"
#include "ArrayException.hpp"
using namespace Mikita::Containers;
using Mikita::CAD::Point;
using namespace std;

int main (){

    Array<Point> test_point_array; //default instantiation 
    Array<Point> test_point_array2 (5); 

    try{
    test_point_array2.GetElement(10); // checking exception handling
    }catch (const OutOfBoundsException& e){
        cout << e.GetMessage() << endl;
    }

    // Checking getters 
    cout << test_point_array.GetElement(2) <<endl;

    // checking operators overload
    cout << test_point_array[2] << endl;

    return 0;
}