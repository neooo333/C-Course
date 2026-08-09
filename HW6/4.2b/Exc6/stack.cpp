#ifndef STACK_CPP
#define STACK_CPP

#include "stack.hpp"
#include <iostream>
#include "array_exception.hpp"
#include "stack_exception.hpp"

namespace Mikita {
    namespace Containers {

        template <typename T, int size>
        Stack<T, size>::Stack() : araray_instance(size), m_current(0) {}

        template <typename T, int size>
        Stack<T, size>::~Stack() {
            std::cout << "Destructor was called" << std::endl;
        }

        template <typename T, int size>
        Stack<T, size>::Stack(const Stack<T, size>& instance)
            : araray_instance(instance.araray_instance), m_current(instance.m_current) {}

        template <typename T, int size>
        Stack<T, size>& Stack<T, size>::operator=(const Stack<T, size>& instance) {
            if (this == &instance) {
                return *this;
            }
            m_current = instance.m_current;
            araray_instance = instance.araray_instance;
            return *this;
        }

        template <typename T, int size>
        void Stack<T, size>::Push(const T& element) {
            try {
                araray_instance.SetElement(m_current, element);
                m_current++;
            }catch (const ArrayException& e){
                throw StackFullException ();
            }

        }

        template <typename T, int size>
        T Stack<T, size>::Pop() {
            m_current--;
            try {
                return araray_instance[m_current];
            } catch (const ArrayException& e) {
                m_current = 0;
                throw StackEmptyException ();
            }
        }

    }
}

#endif
