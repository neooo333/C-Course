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
        double GetX () const;
        double GetY () const;

        //Set Functions 
        void SetX (double new_x_value);
        void SetY (double new_y_value);  

        // String description of a point 

        string  ToString () const;

        
};

#endif