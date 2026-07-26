#include "point_h.hpp"

#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;


//Constructor implementation
Point::Point () : m_x (0), m_y (0) {

    cout << "Instance created" << endl;
}; 

//Constructor with provided parameters
Point::Point (double value_x, double value_y) : m_x (value_x), m_y (value_y) {

    cout << "Instance Created" << endl;
}; 


// Copy Constructor
Point::Point (const Point& other) : m_x (other.m_x), m_y (other.m_y){

    cout<< "Copy Constructor was executed" << endl;
}

// Reports when a Point instance is destroyed.
Point::~Point () {

    cout << "Instance was successfully destroyed" << endl;
}

// Formats the point as a readable string.
string Point::ToString () const {
    stringstream message;
    message << "Point(" << m_x << ", " << m_y << ")";
    return message.str();
}

// Calculates the Pythagorean distance from this point to the origin.
double Point::Distance () const {
    return sqrt((m_x * m_x) + (m_y * m_y));
}

// Calculates the Pythagorean distance to another point passed by const reference
double Point::Distance (const Point& p) const {
    double distance_x = m_x - p.X();
    double distance_y = m_y - p.Y();
    return sqrt((distance_x * distance_x) + (distance_y * distance_y));
}





