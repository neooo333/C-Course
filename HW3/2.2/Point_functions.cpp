#include "point_h.hpp"

#include <iostream>
#include <sstream>
using namespace std;

Point::Point () : m_x (0), m_y (0) {}; 

Point::Point (double value_x, double value_y) : m_x (value_x), m_y (value_y) {}; 

Point::~Point () {

    cout<< "Instance was succesfully destroyed"<< endl;
}

double Point::GetX () const{
    return  m_x;
};


double Point::GetY () const{
    return m_y;
};

void Point::SetX (double new_x_value){
    m_x = new_x_value;
    cout<< "The new value of x: " << m_x << endl;
};  

void Point::SetY (double new_y_value){
    m_y = new_y_value;
    cout<< "The new value of y: " << m_y << endl;
};  

string  Point::ToString () const {

    stringstream message;
    message << "Point(" << m_x << ", " << m_y << ")" << endl;
    return message.str();
};





