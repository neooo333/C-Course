#ifndef CIRCLE_H
#define CIRCLE_H

#include "point_h.hpp"
#include <string>

using namespace std;

class Circle {

    // Privite members of the class
    private:
        Point center_point;
        double m_radius;
    public:
        //Constructor & Destructor
        Circle ();

        // Constructor with parameters
        Circle (const Point& center_point_passed, const double& radius);

        // Creates a circle by copying another circle.
        Circle (const Circle& circle);

        // Destroys the circle.
        ~Circle ();

        //Metrics
        double diameter () const;
        double area () const;
        double circumference () const;

        //GEtters and Setters

        double radius () const;
        void radius (const double& new_rad);

        // Returns a copy of the center point.
        Point center () const;
        void center (const Point& cent_point);

        //ToString
        string ToString () const;
};


#endif