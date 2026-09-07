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

        class NotSameSizeException : public ArrayException {
            
            private:
                int array_size1;
                int array_size2;
            
            public:

                NotSameSizeException (int size1, int size2) : array_size1 (size1), array_size2 (size2) {};

                // Not same size Exception
                string GetMessage () const {
                    stringstream message;
                    message << "Arrays are not the same size : " << array_size1 << " vs " << array_size2;
                    return message.str ();
            }

        };
    
    }
}






#endif