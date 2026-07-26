#ifndef POINT_H
#define POINT_H

#include <string>
using namespace std;

class Point{

    private:
        double m_x;
        double m_y;

    public:
        // Default Constructors
        Point ();

        // Constructor with parameters
        Point (double value_x, double value_y);

        // Destructor
        ~Point ();

        // Returns the x-coordinate.
        double GetX ();

        // Returns the y-coordinate.
        double GetY ();

        //Changes the x-coordinate.
        void SetX (double new_x_value);

        // Changes the y coordinate 
        void SetY (double new_y_value);  

        //returns a string  of a point 
        string ToString () const;

        // Calculates the distance from this point to the origin.
        double DistanceOrigin ();

        // Calculates the distance from this point to another point.
        double Distance (Point p);

        
};

#endif