#ifndef POINT_H
#define POINT_H

#include <string>
#include <ostream>
using namespace std;


namespace Mikita {
    namespace CAD {
    
        class Point{

            private:
                double m_x;
                double m_y;

            public:
                // Constructors
                Point ();

                Point (double value_x, double value_y);

                explicit Point (double value);

                // Exc 1 Copy Constructor
                Point (const Point& other);

                // Destructor
                ~Point ();

                //  functions normal inline, implemented below the class
                double X () const;
                double Y () const;

                //Set Functions (default inline)
                void X (double new_x_value) { m_x = new_x_value; }
                void Y (double new_y_value) { m_y = new_y_value; }

                // Returns a string like "Point(1.5, 3.9)" (no trailing newline)
                string ToString () const;

                // Pythagorean distance to origin (0, 0) and to another point
                double Distance () const;
                double Distance (const Point& p) const;

                // Operator Overload

                Point operator - () const;
                Point operator * (double factor) const;
                Point operator + (const Point& p) const;
                bool operator == (const Point& p) const;
                Point& operator = (const Point& source);
                Point& operator *= (double factor); 


                friend ostream& operator << (ostream& os, const Point& p);
                
        };

        //  normal inline getters
        inline double Point::X () const { return m_x; }
        inline double Point::Y () const { return m_y; }

        // ostream operator

        /* << Operator for Exc1 (commented since we used in friend function in Point class)
        inline ostream& operator << (ostream& os, const Point& p){
            return os << p.ToString();
        }
        */
    }
}
#endif