#include "PointArray.hpp"
#include "Array.hpp"
#include <iostream>

using Mikita::Containers::Array;
using namespace std;


namespace Mikita {
    namespace Containers {

        //default constructor
        PointArray::PointArray () : Array<Point> (){}

        //Custom cinstructor
        PointArray::PointArray (const int& value) : Array <Point> (value) {};

        //Copy constructor
        PointArray::PointArray (const PointArray& value) : Array <Point> (value) {};

        //Destructor

        PointArray::~PointArray () {

        }

        //assignment operator 

        PointArray& PointArray::operator = (const PointArray& value){
            if (this == &value){
                return *this;
            }
            Array::operator = (value);
            return *this;
        }

        // Length function

        double PointArray::Length () const {

            double length = 0;

            for (int i = 0; i < ((this->Size())-1); i++){

                length += (*this)[i].Distance((*this)[i+1]);
            }
            return length;
        }
    }
}