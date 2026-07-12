#ifndef POINT_ARRAY
#define POINT_ARRAY



#include "point_h.hpp"


class Array{

    private:
        Point* m_data;
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
        void SetElement (const int& index, const Point& point);
    
        Point& GetElement () {return m_data[0];}
        Point& GetElement (const int& index); 

        Point& operator [] (const int& index);

        const Point& operator [] (const int& index) const;

    

};

#endif
