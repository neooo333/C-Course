#ifndef NUMERIC_ARRAY_CPP
#define NUMERIC_ARRAY_CPP

#include "NumericArray.hpp"
#include "ArrayException.hpp"

using Mikita::Containers::NotSameSizeException;


namespace Mikita{
    namespace Containers {

    template <typename T>
    NumericArray<T>::NumericArray () : Array<T>() {}

    template <typename T>
    NumericArray<T>::NumericArray (const int& length) : Array<T>(length) {}

    template <typename T>
    NumericArray<T>::NumericArray (const NumericArray<T>& narray)
        : Array<T>(narray) {}

    template <typename T>
    NumericArray<T>::~NumericArray () {}

    template <typename T>
    NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& narray){

        if (this == &narray){
            return *this;
        }

        this->Array<T>::operator = (narray);
        return *this;

    }

    template <typename T>
    NumericArray<T> NumericArray<T>::operator * (const double& factor) const{

        NumericArray<T> result (this->Size());

        for (int i = 0; i < result.Size(); i++){
            result [i] = (*this)[i]  * factor;
        }

        return result;

    }

    template <typename T>
    NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& narray) const{

        if (this->Size() != narray.Size()){
            throw  NotSameSizeException (this->Size() , narray.Size());
        }

        NumericArray<T> result (this->Size ());

        for (int i = 0; i < this->Size() ; i++){
            result[i] = (*this)[i] + narray[i];
        }

        return result;

    }

    template <typename T>
    double NumericArray<T>::DotProduct (const NumericArray<T>& narray) const {
        
        if (this->Size() != narray.Size()){
            throw  NotSameSizeException (this->Size() , narray.Size());
        }

        double result = 0;

        for (int i = 0; i < this->Size() ; i++){
            result += (*this)[i] * narray[i];
        }

        return result;

    }



    }
}







#endif