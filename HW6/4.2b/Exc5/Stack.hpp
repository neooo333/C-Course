#ifndef STACK_HPP
#define STACK_HPP

#include "Array.hpp"

namespace Mikita {
    namespace Containers {

        template <typename T>
        class Stack {

            private:
                Array<T> array_instance;
                int m_current;

            public:
                Stack();
                Stack(const int& array_size);
                ~Stack();

                Stack(const Stack<T>& instance);

                Stack<T>& operator=(const Stack<T>& instance);

                void Push(const T& element);

                T Pop();
        };

    }
}

#ifndef STACK_CPP
#include "Stack.cpp"
#endif

#endif
