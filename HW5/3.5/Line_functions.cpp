#include "Line_h.hpp"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

namespace Mikita {
    namespace CAD {


    // Version A (assignment in body) 
    /*
        Line::Line () {
            cout << "Default Line constructor was called" << endl;
            start = Point ();
            finish = Point ();
        }

        Line::Line (const Point& p1, const Point& p2) {
            cout << "Line Constructor was called" << endl;
            start = p1;
            finish = p2;
        }

        Line::Line (const Line& line_passed) {
            cout << "Line copy constructor was called" << endl;
            start = line_passed.start;
            finish = line_passed.finish;
        }
    
    */
    // --- VERSION B (colon syntax) ---
    
    
        Line::Line () : Shape () ,start (), finish () {
            cout << "Default Line constructor was called" << endl;
        }

        Line::Line (const Point& p1, const Point& p2) : Shape (), start (p1), finish (p2) {
            cout << "Line Constructor was called" << endl;
        }

        Line::Line (const Line& line_passed)
            : Shape (line_passed), start (line_passed.start), finish (line_passed.finish) {
            cout << "Line copy constructor was called" << endl;
        }
    
    
         Line::~Line () {
            cout << "Line Destructor was called" << endl;
         }
    

        // Getters and Setters
        Point Line::start_point () const {
            return start;
        }

        void Line::start_point (const Point& new_value) {
            start = new_value;
        }

        Point Line::end_point () const {
            return finish;
        }

        void Line::end_point (const Point& new_value) {
            finish = new_value;
        }

        // ToString
        string Line::ToString () const {
            stringstream message;
            std::string s = Shape::ToString();
            message << s << ": Line with coordinates:({" << start.X() << ", " << start.Y() << "}, {"
                        << finish.X() << ", " << finish.Y() << "})";
            return message.str();
        }

        // Length
        double Line::Length () const {
            return start.Distance (finish);
        }

        // Operator Overload
        Line& Line::operator = (const Line& l) {
            if (this == &l) return *this;

            Shape::operator=(l);

            start = l.start_point ();
            finish = l.end_point ();
            return *this;
        }

        ostream& operator << (ostream& os, const Line& l) {
            return os << "Line with coordinates:({" << l.start << "}, {"
            << l.finish << "})";
        }

    }
}
