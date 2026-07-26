#include "point_h.hpp"

#include <iostream>
#include <ostream>
#include <sstream>
#include <cmath>
using namespace std;

namespace Mikita {
    namespace CAD {
    

        Point::Point () : m_x (0), m_y (0) {

        } 

        Point::Point (double value_x, double value_y) : m_x (value_x), m_y (value_y) {}; 

        Point::Point (double value) : m_x (value), m_y (value) {};
        // Copy Constructor
        Point::Point (const Point& other) : m_x (other.m_x), m_y (other.m_y){
            cout << "Copy constructor was called: " 
                << m_x << ", " << m_y <<endl;
        }

        Point::~Point () {
        }

        // Getters and setters are inline in point_h.hpp (Exc 7)

        string Point::ToString () const {
            stringstream message;
            message << "Point(" << m_x << ", " << m_y << ")";
            return message.str();
        }

        // sqrt(x^2 + y^2) — distance from this point to (0, 0)
        double Point::Distance () const {
            return sqrt((m_x * m_x) + (m_y * m_y));
        }

        // sqrt((dx)^2 + (dy)^2) — distance to another point (passed by value)
        double Point::Distance (const Point& p) const {
            double distance_x = m_x - p.X();
            double distance_y = m_y - p.Y();
            return sqrt((distance_x * distance_x) + (distance_y * distance_y));
        }

        //Operator Overload

        Point Point::operator - () const {
            return Point (-m_x, -m_y);
        }

        Point Point::operator * (double factor) const {
            return Point(m_x * factor, m_y * factor);
        }

        Point Point::operator + (const Point& p) const {
            return Point(m_x + p.X(), m_y + p.Y());
        }

        bool Point::operator == (const Point& p) const {
            if (m_x == p.X() && m_y == p.Y ()){
                return true;
            } else {
                return false;
            }
        }

        Point& Point::operator = (const Point& source) {
            if (this == &source) return *this;

            m_x = source.X();
            m_y = source.Y();
            return *this;
        }

        Point& Point::operator *= (double factor){
            m_x *= factor;
            m_y *= factor;
            return *this;
        }

        // operator overload with friend function. Testing access to private members.
        ostream& operator << (ostream& os, const Point& p){
            return os << "Point (" << p.m_x << ", " << p.m_y << ")";
        }

    }

}


