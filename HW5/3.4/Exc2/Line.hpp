#ifndef LINE_H
#define LINE_H

#include "Shape.hpp"
#include "Point.hpp"
#include <string>
#include <ostream>

using namespace std;

namespace Mikita {
    namespace CAD {

class Line : public Shape{

    private:
        Point start;
        Point finish;

    public:
    // Constructors and Destructors
        Line ();
        Line (const Point& p1, const Point& p2);
        Line (const Line& line_passed);
        ~Line ();
    // Getters and Setters
        const Point& start_point () const;
        void start_point (const Point& new_value);

        const Point& end_point () const;
        void end_point (const Point& new_value);

    // ToString 

        string ToString() const;

    // Length
        double Length () const;
    // Operator Overload
        Line& operator = (const Line& l);

        friend ostream& operator << (ostream&  os, const Line& l);

};


}

}



#endif