#define _USE_MATH_DEFINES
#include "Circle.hpp"
#include <sstream>
#include <iostream>
#include <cmath>


namespace Mikita {
    namespace CAD {
    
        // Constructor & Destructor — colon syntax 
        Circle::Circle () : Shape (), center_point (), m_radius (0) {}

        Circle::Circle (const Point& center_point_passed, const double& radius)
            : Shape () , center_point (center_point_passed), m_radius (radius) {}

        Circle::Circle (const Circle& circle)
            : Shape (circle), center_point (circle.center_point), m_radius (circle.m_radius) {}

        Circle::~Circle () {}

        // Getters and Setters

        double Circle::radius () const{
            return m_radius;
        }
        void Circle::radius (const double& new_rad){
            m_radius = new_rad;
        }

        Point Circle::center () const{
            return center_point;
        }

        void Circle::center (const Point& cent_point){
            center_point = cent_point;
        }

        //Metrics
        double Circle::diameter () const{
            return m_radius * 2;
        }

        double Circle::area () const{
            return M_PI * m_radius * m_radius;
        }

        double Circle::circumference () const{
            return 2 * M_PI * m_radius;
        }

        //ToString
        string Circle::ToString () const{
            stringstream message;
            message << "Circle with center (" << center_point.X() << ", " << center_point.Y() << ") " << "Radius: " << m_radius;
            return message.str();
        }

        // Operator Overload

        Circle& Circle::operator = (const Circle& c){
            if (this == &c) return *this;

            Shape::operator=(c);
            center_point = c.center ();
            m_radius = c.radius ();
            return *this;
        }

        ostream& operator << (ostream& os, const Circle& c){
            return os << c.ToString();
        }

}

}   