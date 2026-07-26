#include "Point_array.hpp"
#include "point_h.hpp"
#include <iostream>
#include "array_exception.hpp"

using namespace Mikita::Containers;
using Mikita::CAD::Point;
using namespace std;


int main (){

    // Creating test instances of Array class
    Array test_array (3);
    const Array test_array2 (4);


    // if there is no catch block the following error message is raised: "terminating due to uncaught exception of type int".
    //  So we need to catch the exception.
    try {
        test_array [5];  //testing catch block on [] operator
    }catch(const ArrayException& e){
        cout<< e.GetMessage () << endl;
    }

    try {
        test_array2 [7]; //testing catch block on [] operator for cosnt instances 
    }catch(const ArrayException& e){
        cout<< e.GetMessage ()  << endl;
    }

    try {
        test_array.GetElement(8);  //testing catch block on getters methods
    }catch(const ArrayException& e){
        cout<< e.GetMessage () << endl;
    }

    try {
        test_array.SetElement(8, Point () ); //testing catch block on setters methods
    }catch(const ArrayException& e){
        cout<< e.GetMessage ()<< endl;
    }


    return 0;
}