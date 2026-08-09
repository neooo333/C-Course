#ifndef ARRAY
#define ARRAY
//#include "point_h.hpp"


namespace Mikita {
    namespace Containers{
        template<typename T>
        class Array{

            private:
                T* m_data;
                int m_size;

            public:

            // Constructors
                Array ();
                Array (const int& size);
            // Copy constructor 
                Array (const Array<T>& arr);

            // Destructor

                ~Array ();

            // Assignment Operator

                Array& operator = (const Array<T>& arr);

            // Functions
                int Size () const {return m_size;} // Default inline
                void SetElement (const int& index, const T& point);
            
                T& GetElement () {return m_data[0];}
                T& GetElement (const int& index); 

                T& operator [] (const int& index);

                const T& operator [] (const int& index) const;

            

        };

    }

}

#ifndef ARRAY_CPP
#include "array.cpp"
#endif

#endif
