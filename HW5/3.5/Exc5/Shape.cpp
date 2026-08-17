#include "Shape.hpp"
#include "stdlib.h"
#include <iostream>
#include <sstream>
using namespace std;


namespace Mikita {
    namespace CAD {
        Shape::Shape () : id (rand()) {} //default consrructor
        Shape::Shape (const Shape& copy) : id (copy.id) {} // Copy Constructor
        Shape::~Shape () {
            cout << "Shape destructor was called" << endl;
        }
        Shape& Shape::operator = (const Shape& copy){
            if (this == &copy){
                return *this;
            }
            id = copy.id;
            return *this;
        }

        // To String implementation
        string Shape::ToString () const {
            stringstream name;
            name << "ID: " << id;
            return name.str();
        }

        
    
    }

}
