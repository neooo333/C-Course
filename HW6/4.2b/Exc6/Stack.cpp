#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.hpp"
#include <iostream>
#include "ArrayException.hpp"
#include "StackException.hpp"

namespace Mikita {
    namespace Containers {

        template <typename T, int size>
        Stack<T, size>::Stack() : array_instance(size), m_current(0) {}

        template <typename T, int size>
        Stack<T, size>::~Stack() {
            std::cout << "Destructor was called" << std::endl;
        }

        template <typename T, int size>
        Stack<T, size>::Stack(const Stack<T, size>& instance)
            : array_instance(instance.array_instance), m_current(instance.m_current) {}

        template <typename T, int size>
        Stack<T, size>& Stack<T, size>::operator=(const Stack<T, size>& instance) {
            if (this == &instance) {
                return *this;
            }
            m_current = instance.m_current;
            array_instance = instance.array_instance;
            return *this;
        }

        template <typename T, int size>
        void Stack<T, size>::Push(const T& element) {
            try {
                array_instance.SetElement(m_current, element);
                m_current++;
            } catch (const ArrayException&) {
                throw StackFullException ();
            }

        }

        template <typename T, int size>
        T Stack<T, size>::Pop() {
            const int previous_current = m_current;
            m_current--;
            try {
                return array_instance[m_current];
            } catch (const ArrayException&) {
                m_current = previous_current;
                throw StackEmptyException ();
            }
        }

    }
}

#endif
