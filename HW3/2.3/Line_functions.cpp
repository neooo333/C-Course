#include "Line_h.hpp"
#include <sstream>
#include <iostream>

using namespace std;

// Constructors and Destructors
Line::Line () : start(), finish() {}

Line::Line (const Point& p1, const Point& p2) : start(p1), finish(p2) {}

Line::Line (const Line& line_passed) : start(line_passed.start), finish(line_passed.finish) {}

// Destructor
Line::~Line () {
    cout << "Line Object was destroyed" << endl;
}

// Getters and Setters
Point Line::start_point () const {
    return start;
}

// Changes the start point.
void Line::start_point (const Point& new_value) {
    start = new_value;
}

// Returns a copy of the end point.
Point Line::end_point () const{
    return finish;
}

// Changes the end point.
void  Line::end_point (const Point& new_value){
    finish = new_value;
}

// ToString

string Line::ToString() const{
    stringstream message;
    message << "Line with coordinates:({" << start.X()<<", " << start.Y()<< "}, {" 
                << finish.X() <<", " <<finish.Y() << "})";
    return message.str();
}

// Delegates to Point::Distance() to calculate the line length.
double Line::Length () const{
    return start.Distance(finish);
}





