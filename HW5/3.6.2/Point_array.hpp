#ifndef POINT_ARRAY
#define POINT_ARRAY
#include "point_h.hpp"


namespace Mikita {
    namespace Containers{
        class Array{

            private:
                CAD::Point* m_data;
                int m_size;

            public:

            // Constructors
                Array ();
                Array (const int& size);
            // Copy constructor 
                Array (const Array& arr);

            // Destructor

                ~Array ();

            // Assignment Operator

                Array& operator = (const Array& arr);

            // Functions
                int Size () const {return m_size;} // Default inline
                void SetElement (const int& index, const CAD::Point& point);
            
                CAD::Point& GetElement () {return m_data[0];}
                CAD::Point& GetElement (const int& index); 

                CAD::Point& operator [] (const int& index);

                const CAD::Point& operator [] (const int& index) const;

            

        };

    }

}
#endif
