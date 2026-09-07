#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.hpp"
#include <iostream>
#include "ArrayException.hpp"
#include "StackException.hpp"

namespace Mikita {
    namespace Containers {

        template <typename T>
        Stack<T>::Stack() : array_instance(), m_current(0) {}

        template <typename T>
        Stack<T>::Stack(const int& array_size) : array_instance(array_size), m_current(0) {}

        template <typename T>
        Stack<T>::~Stack() {
            std::cout << "Destructor was called" << std::endl;
        }

        template <typename T>
        Stack<T>::Stack(const Stack<T>& instance)
            : array_instance(instance.array_instance), m_current(instance.m_current) {}

        template <typename T>
        Stack<T>& Stack<T>::operator=(const Stack<T>& instance) {
            if (this == &instance) {
                return *this;
            }
            m_current = instance.m_current;
            array_instance = instance.array_instance;
            return *this;
        }

        template <typename T>
        void Stack<T>::Push(const T& element) {
            try {
                array_instance.SetElement(m_current, element);
                m_current++;
            } catch (const ArrayException&) {
                throw StackFullException ();
            }

        }

        template <typename T>
        T Stack<T>::Pop() {
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
