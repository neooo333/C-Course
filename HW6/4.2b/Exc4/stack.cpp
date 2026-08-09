#ifndef STACK_CPP
#define STACK_CPP

#include "stack.hpp"
#include <iostream>
#include "array_exception.hpp"

namespace Mikita {
    namespace Containers {

        template <typename T>
        Stack<T>::Stack() : araray_instance(), m_current(0) {}

        template <typename T>
        Stack<T>::Stack(const int& array_size) : araray_instance(array_size), m_current(0) {}

        template <typename T>
        Stack<T>::~Stack() {
            std::cout << "Destructor was called" << std::endl;
        }

        template <typename T>
        Stack<T>::Stack(const Stack<T>& instance)
            : araray_instance(instance.araray_instance), m_current(instance.m_current) {}

        template <typename T>
        Stack<T>& Stack<T>::operator=(const Stack<T>& instance) {
            if (this == &instance) {
                return *this;
            }
            m_current = instance.m_current;
            araray_instance = instance.araray_instance;
            return *this;
        }

        template <typename T>
        void Stack<T>::Push(const T& element) {
            araray_instance.SetElement(m_current, element);
            m_current++;
        }

        template <typename T>
        T Stack<T>::Pop() {
            m_current--;
            try {
                return araray_instance[m_current];
            } catch (const OutOfBoundsException&) {
                m_current++;
                throw;
            }
        }

    }
}

#endif
