#include "Circle_h.hpp"
#include "point_h.hpp"
#include "Shape_h.hpp"
#include "Line_h.hpp"
// #include <iostream>
using namespace Mikita::CAD;
using namespace std;

int main (){

    // Shape std_shape;  Does not comile since it's a abstract class

    Shape* shape_array [3]; // Can create pointers to Shape class

    // Assigning child classes pointers to Shape pointer
    shape_array[0] = new Point; 
    shape_array[1] = new Circle;
    shape_array[2] = new Line;

    for (int i =0; i <3; i++){
        shape_array[i]->Draw(); //Since Draw is virtual it should be overwritten by child classes 
        cout<< endl;
    }

    for (int i =0; i <3; i++) delete shape_array[i]; // Calling destructors to remove objects on the heap 
    return 0;
}