#ifndef POINT_ARRAY_HPP
#define POINT_ARRAY_HPP

#include "Array.hpp"
#include "Point.hpp"

using Mikita::CAD::Point;

namespace Mikita{
    namespace Containers {

        class PointArray : public Array<Point>{
            public:

                //Constructors
                PointArray ();
                PointArray (const int& size);

                //Copy constructor
                PointArray (const PointArray& value);

                //Destructor
                ~PointArray ();

                // assignment operator

                PointArray& operator = (const PointArray& value);

                //Length function 
                double Length () const;

        };

    }
}


#endif

