#include "point_h.hpp"

#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

Point::Point () : m_x (0), m_y (0) {

    cout << "Instance created" << endl;
}; 

Point::Point (double value_x, double value_y) : m_x (value_x), m_y (value_y) {

    cout << "Instance Created" << endl;
}; 


// Copy Constructor
Point::Point (const Point& other) : m_x (other.m_x), m_y (other.m_y){

    cout<< "Copy Constructor was executed" << endl;
}

Point::~Point () {

    cout << "Instance was successfully destroyed" << endl;
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





