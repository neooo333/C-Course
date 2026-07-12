#ifndef CIRCLE_H
#define CIRCLE_H

#include "point_h.hpp"
#include <string>
#include <ostream>

using namespace std;


namespace Mikita {
    namespace CAD {
    

        class Circle {

            private:
                Point center_point;
                double m_radius;
            public:
                //Constructor & Destructor
                Circle ();
                Circle (const Point& center_point_passed, const double& radius);
                Circle (const Circle& circle);
                ~Circle ();

                //Metrics
                double diameter () const;
                double area () const;
                double circumference () const;

                //GEtters and Setters

                double radius () const;
                void radius (const double& new_rad);

                Point center () const;
                void center (const Point& cent_point);

                //ToString
                string ToString () const;

                // Operator overload

                Circle& operator = (const Circle& c);
        };

        inline ostream& operator << (ostream& os, const Circle& c){
            return os << c.ToString();
        }

    }

}   

#endif