#ifndef ARRAY_EXCEPTION_HPP
#define ARRAY_EXCEPTION_HPP

#include <string>
#include <sstream>

using namespace std;

namespace Mikita{
    namespace Containers{

        class ArrayException {
            public:
                virtual string GetMessage () const = 0;

        };

        
        class OutOfBoundsException : public ArrayException{
            private:
                int m_index;
            public:
                OutOfBoundsException (int index) : m_index (index) {}
                string GetMessage () const {
                    stringstream message;
                    message << "Index " << m_index << " is out of bounds.";
                    return message.str();


                }


        };
    
    }
}






#endif