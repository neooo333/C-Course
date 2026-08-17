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
                virtual ~Shape (); // Virtual destructor for polymorphic deletion

                Shape& operator = (const Shape& copy); //assignemnt operator
                virtual string ToString () const; // Virtual so derived ToString is called via Shape*
                int ID () const {return id;}

                virtual void Draw () const = 0; //abstract base class


        };
    
    }

}




#endif
