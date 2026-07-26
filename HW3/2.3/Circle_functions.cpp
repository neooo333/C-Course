#define _USE_MATH_DEFINES 
#include "Circle_h.hpp"
#include <sstream>
#include <iostream>
#include <cmath>


//Constructor & Destructor
Circle::Circle () : center_point (), m_radius (0) {} //Default constructor
Circle::Circle (const Point& center_point_passed, const double& radius){ //Construcor with passed parameters
    m_radius = radius;
    center_point = center_point_passed;
}
Circle::Circle (const Circle& circle) : center_point(circle.center_point), m_radius(circle.m_radius) {};

// Destroys the circle.
Circle::~Circle () {};

// Returns the radius.
double Circle::radius () const{
    return m_radius;
}

//Changes the radius.
void Circle::radius (const double& new_rad){
    m_radius = new_rad;
}

// Returns a copy of the center point.
Point Circle::center () const{
    return center_point;
}

// Changes the center point
void Circle::center (const Point& cent_point){
    center_point = cent_point;
}

//Metrics
double Circle::diameter () const{
    return m_radius * 2;
};

double Circle::area () const{
    return M_PI * m_radius * m_radius;
};

double Circle::circumference () const{
    return 2 * M_PI * m_radius;
};

//ToString
string Circle::ToString () const{
    stringstream message;
    message << "Circle with center (" << center_point.X() << ", " << center_point.Y() << ") " << "Radius: " << m_radius;
    return message.str();
};