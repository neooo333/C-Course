#include "Line_h.hpp"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

namespace Mikita {
    namespace CAD {

        // Constructors and Destructors
        Line::Line () : start(), finish() {}

        Line::Line (const Point& p1, const Point& p2) : start(p1), finish(p2) {}

        Line::Line (const Line& line_passed) : start(line_passed.start), finish(line_passed.finish) {}

        Line::~Line () {
        }

        // Getters and Setters
        Point Line::start_point () const {
            return start;
        }

        void Line::start_point (const Point& new_value) {
            start = new_value;
        }

        Point Line::end_point () const{
            return finish;
        }

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

        // Length
        double Line::Length () const{
            return start.Distance(finish);
        }

        // Operator Overload

        Line& Line::operator = (const Line& l){
            if (this == &l) return *this;

            start = l.start_point();
            finish = l.end_point ();
            return *this;
        }

        ostream& operator << (ostream& os, const Line& l){
            return os << "Line with coordinates:({" << l.start << "}, {" 
            << l.finish << "})";
        }

    }
}
