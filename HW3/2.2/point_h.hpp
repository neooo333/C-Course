#ifndef POINT_H
#define POINT_H

#include <string>
using namespace std;

class Point{

    private:
        double m_x;
        double m_y;

    public:
        // Constructors
        Point ();

        Point (double value_x, double value_y);

        // Destructor
        ~Point ();

        // Get functions
        double GetX ();
        double GetY ();

        //Set Functions 
        void SetX (double new_x_value);
        void SetY (double new_y_value);  

        // Returns a string like "Point(1.5, 3.9)" (no trailing newline)
        string ToString () const;

        // Pythagorean distance to origin (0, 0) and to another point
        double DistanceOrigin ();
        double Distance (Point p);

        
};

#endif