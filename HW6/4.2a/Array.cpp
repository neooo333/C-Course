#ifndef ARRAY_CPP
#define ARRAY_CPP

#include "Array.hpp"
#include <cstdlib>
#include <iostream>
#include "ArrayException.hpp"

using Mikita::Containers::OutOfBoundsException;

namespace Mikita {
    namespace Containers {

        template <typename T>
        Array<T>::Array (): m_data (new T [10]), m_size (10){}

        template <typename T>
        Array<T>::Array (const int& size) : m_data (new T[size]), m_size (size){}

        template <typename T>
        Array<T>::Array (const Array<T>& arr) : m_data (new T [arr.m_size]), m_size (arr.m_size){
            for (int i = 0; i < arr.m_size; i++){
                m_data [i] = arr.m_data [i];
            }
        }

        template <typename T>
        Array<T>::~Array (){
            delete [] m_data;
            std::cout << "Destructor was called" << std::endl;
        }

        template <typename T>
        Array<T>& Array<T>::operator = (const Array<T>& arr){
            if (this == &arr){
            return *this;
            }

            m_size = arr.m_size;

            delete [] m_data;
            m_data = new T [arr.m_size];
            for (int i = 0; i < arr.m_size; i++){
                m_data [i] = arr.m_data [i];
            }
            return *this;
        }

        template <typename T>
        void Array<T>::SetElement (const int& index, const T& point){
            if ((index > (m_size -1))
            ||
            (index < 0))
            {
                throw OutOfBoundsException (index); // throw OutOfBoundsException object instead of -1
            }else {
                m_data[index] = point;
            }
        }

        template <typename T>
        T& Array<T>::GetElement (const int& index){
            if ((index > (m_size -1)) || (index < 0))
            {
                throw OutOfBoundsException (index); // throw OutOfBoundsException object instead of -1
            }else {
                return m_data[index];
            }
        }

        template <typename T>
        T& Array<T>::operator [] (const int& index){
            if ((index > (m_size -1)) || (index < 0))
            {
                throw OutOfBoundsException (index);  // throw OutOfBoundsException object instead of -1
            }else {
            return GetElement(index);
            }
        }

        template <typename T>
        const T& Array<T>::operator [] (const int& index) const{
            if (index < 0 || index > (m_size - 1)) {
                throw OutOfBoundsException (index); // throw OutOfBoundsException object instead of -1
            }
            return m_data[index];
        }
}

}

#endif
