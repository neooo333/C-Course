#ifndef STACK
#define STACK

#include "array.hpp"

namespace Mikita {
    namespace Containers {

        template <typename T>
        class Stack {

            private:
                Array<T> araray_instance;
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
#include "stack.cpp"
#endif

#endif
