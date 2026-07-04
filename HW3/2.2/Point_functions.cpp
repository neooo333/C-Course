#include "point_h.hpp"

#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

Point::Point () : m_x (0), m_y (0) {}; 

Point::Point (double value_x, double value_y) : m_x (value_x), m_y (value_y) {}; 

Point::~Point () {

    cout << "Instance was successfully destroyed" << endl;
}

double Point::GetX (){
    return  m_x;
};


double Point::GetY (){
    return m_y;
};

void Point::SetX (double new_x_value){
    m_x = new_x_value;
}

void Point::SetY (double new_y_value){
    m_y = new_y_value;
}

string Point::ToString () const {
    stringstream message;
    message << "Point(" << m_x << ", " << m_y << ")";
    return message.str();
}

// sqrt(x^2 + y^2) — distance from this point to (0, 0)
double Point::DistanceOrigin () {
    return sqrt((m_x * m_x) + (m_y * m_y));
}

// sqrt((dx)^2 + (dy)^2) — distance to another point (passed by value)
double Point::Distance (Point p) {
    double distance_x = m_x - p.GetX();
    double distance_y = m_y - p.GetY();
    return sqrt((distance_x * distance_x) + (distance_y * distance_y));
}





