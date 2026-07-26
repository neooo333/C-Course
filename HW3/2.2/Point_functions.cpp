#include "point_h.hpp"

#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

// Creates a point at the origin with default constructor
Point::Point () : m_x (0), m_y (0) {}; 

//creates a point with the supplied coordinates.
Point::Point (double value_x, double value_y) : m_x (value_x), m_y (value_y) {}; 

// Destructor. Reports when a Point instance is destroyed
Point::~Point () {

    cout << "Instance was successfully destroyed" << endl;
}

// method. Returns the x coordinate.
double Point::GetX (){
    return  m_x;
};


// Method.Returns the y-coordinate.
double Point::GetY (){
    return m_y;
};

// Changes the x-coordinate.
void Point::SetX (double new_x_value){
    m_x = new_x_value;
}

// Changes the y-coordinate.
void Point::SetY (double new_y_value){
    m_y = new_y_value;
}

// Retunrs string. Formats the point as a readable string.
string Point::ToString () const {
    stringstream message;
    message << "Point(" << m_x << ", " << m_y << ")";
    return message.str();
}

// sqrt(x^2 + y^2) — distance from this point to (0, 0)
double Point::DistanceOrigin () {
    return sqrt((m_x * m_x) + (m_y * m_y));
}

// Calculates the Pythagorean distance to another point passed by value.
double Point::Distance (Point p) {
    double distance_x = m_x - p.GetX();
    double distance_y = m_y - p.GetY();
    return sqrt((distance_x * distance_x) + (distance_y * distance_y));
}





