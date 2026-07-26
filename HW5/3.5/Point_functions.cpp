#include "point_h.hpp"

#include <iostream>
#include <ostream>
#include <sstream>
#include <cmath>
using namespace std;

namespace Mikita {
    namespace CAD {
    

        // Colon syntax for m_x / m_y (primitives — no extra object ctors, but still correct style)
        Point::Point () : Shape (), m_x (0), m_y (0) {
            cout << "Point default constructor" << endl;
        }

        Point::Point (double value_x, double value_y) : 
        Shape () , m_x (value_x), m_y (value_y) {
            cout << "Point constructor (" << m_x << ", " << m_y << ")" << endl;
        }

        Point::Point (double value) : Shape (),  m_x (value), m_y (value) {
            cout << "Point single-value constructor (" << m_x << ", " << m_y << ")" << endl;
        }

        // Copy Constructor
        Point::Point (const Point& other) : Shape (other) , m_x (other.m_x), m_y (other.m_y) {
            cout << "Point copy constructor (" << m_x << ", " << m_y << ")" << endl;
        }

        Point::~Point () {
            cout << "Point destructor (" << m_x << ", " << m_y << ")" << endl;
        }

        // Getters and setters are inline in point_h.hpp

        string Point::ToString () const {
            stringstream message;
            string s = Shape::ToString();
            message << s <<  ": Point(" << m_x << ", " << m_y << ")";
            return message.str();
        }

        // sqrt(x^2 + y^2) — distance from this point to (0, 0)
        double Point::Distance () const {
            return sqrt((m_x * m_x) + (m_y * m_y));
        }

        // sqrt((dx)^2 + (dy)^2) — distance to another point
        double Point::Distance (const Point& p) const {
            double distance_x = m_x - p.X();
            double distance_y = m_y - p.Y();
            return sqrt((distance_x * distance_x) + (distance_y * distance_y));
        }

        // Operator Overload

        Point Point::operator - () const {
            return Point (-m_x, -m_y);
        }

        Point Point::operator * (double factor) const {
            return Point (m_x * factor, m_y * factor);
        }

        Point Point::operator + (const Point& p) const {
            return Point (m_x + p.X(), m_y + p.Y());
        }

        bool Point::operator == (const Point& p) const {
            if (m_x == p.X() && m_y == p.Y ()) {
                return true;
            } else {
                return false;
            }
        }

        Point& Point::operator = (const Point& source) {
            cout << "Point assignment operator" << endl;
            if (this == &source) return *this;

            Shape::operator = (source);
            m_x = source.X();
            m_y = source.Y();
            return *this;
        }

        Point& Point::operator *= (double factor) {
            m_x *= factor;
            m_y *= factor;
            return *this;
        }

        // operator overload with friend function. Testing access to private members.
        ostream& operator << (ostream& os, const Point& p) {
            return os << "Point (" << p.m_x << ", " << p.m_y << ")";
        }

    }

}
