#define _USE_MATH_DEFINES   // MSVC: must precede <cmath> so M_PI is defined
#include "Circle_h.hpp"
#include <sstream>
#include <iostream>
#include <cmath>




//Constructor & Destructor
Circle::Circle () : center_point (), m_radius (0) {}
Circle::Circle (const Point& center_point_passed, const double& radius){
    m_radius = radius;
    center_point = center_point_passed;
}
Circle::Circle (const Circle& circle) : center_point(circle.center_point), m_radius(circle.m_radius) {};
Circle::~Circle () {};

//GEtters and Setters

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