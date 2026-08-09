#ifndef NUMERIC_ARR
#define NUMERIC_ARR

#include "array.hpp"

using Mikita::Containers::Array;

namespace Mikita {
    namespace Containers {
    
        template <typename T>
        class NumericArray : public Array<T> {
        
            public:
                //Constructors 
                NumericArray ();
                NumericArray (const int& length);
                NumericArray (const NumericArray<T>& narray);

                //Destructor
                ~NumericArray ();

                NumericArray<T>& operator = (const NumericArray<T>& narray);

                NumericArray<T> operator + (const NumericArray<T>& narray) const;

                NumericArray<T> operator * (const double& factor) const;

                double DotProduct (const NumericArray<T>& narray) const;

        };
    }
}

#ifndef NARRAY_CPP
#include "numeric_array.cpp"
#endif

#endif