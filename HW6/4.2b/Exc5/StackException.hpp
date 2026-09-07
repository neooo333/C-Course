#ifndef STACK_EXCEPTION_HPP
#define STACK_EXCEPTION_HPP

#include <string>

namespace Mikita {
    namespace Containers {

        class StackException {
            public:
                virtual ~StackException() {}
                virtual std::string GetMessage() const = 0;
        };

        class StackFullException : public StackException {
            public:
                std::string GetMessage() const {
                    return "Stack is full.";
                }
        };

        class StackEmptyException : public StackException {
            public:
                std::string GetMessage() const {
                    return "Stack is empty.";
                }
        };
    }
}

#endif