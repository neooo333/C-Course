#include "Point_array.hpp"
#include "point_h.hpp"
#include <cstdlib>
#include <iostream>

namespace Mikita {
    namespace Containers {
    

        Array::Array (){
            m_size = 10;
            m_data = new CAD::Point [m_size];
        }


        Array::Array (const int& size){
            m_size = size;
            m_data = new CAD::Point [m_size];
        }

        Array::Array (const Array& arr){
            m_size = arr.m_size;
            m_data = new CAD::Point [arr.m_size];
            for (int i = 0; i < arr.m_size; i++){
                m_data [i] = arr.m_data [i];
            }
        }

        Array::~Array (){
            delete [] m_data;
            cout << "Destructor was called" << endl;
        }

        Array& Array::operator = (const Array& arr){
            if (this == &arr){ 
            return *this; 
            }

            m_size = arr.m_size;

            delete [] m_data;
            m_data = new CAD::Point [arr.m_size];
            for (int i = 0; i < arr.m_size; i++){
                m_data [i] = arr.m_data [i];
            }
            return *this;
        }

        void Array::SetElement (const int& index, const CAD::Point& point){
            if ((index > (m_size -1))
            || 
            (index < 0))
            {
                cout << "Index out of bound" << endl;
            }else {
                m_data[index] = point;
            }
        }

        CAD::Point& Array::GetElement (const int& index){
            if ((index > (m_size -1))
            || 
        (index < 0))
        {
            cout << "Index out of bound. First element returned." << endl; 
            return (*this).GetElement ();
        }else {
            return m_data[index];
        }
        }


        CAD::Point& Array::operator [] (const int& index){
            return GetElement(index);
        }

        const CAD::Point& Array::operator [] (const int& index) const{
            if (index < 0 || index > (m_size - 1)) {
                cout << "Index out of bound. First element returned." << endl;
                return m_data[0];
            }
            return m_data[index];
        }
}

}   