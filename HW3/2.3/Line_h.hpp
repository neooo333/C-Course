#ifndef LINE_H
#define LINE_H

#include "point_h.hpp"
#include <string>

using namespace std;

class Line {

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
        Point start_point () const;
        void start_point (const Point& new_value);

        Point end_point () const;
        void end_point (const Point& new_value);

    // ToString 

        string ToString() const;

    // Length
        double Length () const;

};

#endif