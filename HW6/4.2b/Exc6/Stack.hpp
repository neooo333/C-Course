#ifndef STACK_HPP
#define STACK_HPP

#include "Array.hpp"

namespace Mikita {
    namespace Containers {

        template <typename T, int size>
        class Stack {

            private:
                Array<T> array_instance;
                int m_current;

            public:
                Stack();

                ~Stack();

                Stack(const Stack<T, size>& instance);

                Stack<T, size>& operator=(const Stack<T, size>& instance);

                void Push(const T& element);

                T Pop();
        };

    }
}

#ifndef STACK_CPP
#include "Stack.cpp"
#endif

#endif
