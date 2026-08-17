#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;



namespace Mikita {
    namespace CAD {

        class Shape {

            private:
                int id;  // ID member of the class
            public:
                Shape (); //Default constructor
                Shape (const Shape& copy); // Copy constructor 

                Shape& operator = (const Shape& copy); //assignemnt operator
                virtual string ToString () const; 

                int ID () const {return id;}


        };
    
    }

}




#endif