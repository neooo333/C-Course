#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
using namespace std;

namespace Mikita {
    namespace CAD {

        class Shape {

            private:
                int id;  // ID member of the class
            public:
                Shape (); //Default constructor
                Shape (const Shape& copy); // Copy constructor 
                virtual ~Shape (); // Destructor

                Shape& operator = (const Shape& copy); //assignemnt operator
                virtual string ToString () const;
                int ID () const {return id;} //Returns copy of the ID
                virtual void Draw () const =0; // Virtual function with no implementation. This will make Shape class abstract.

                void Print () const {cout << ToString() <<endl;}  //Print function (defautl inline)

        };
    
    }

}




#endif