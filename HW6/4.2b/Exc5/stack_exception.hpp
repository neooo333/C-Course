#ifndef STACK_EXC
#define STACK_EXC

namespace Mikita {
    namespace Containers {

        class StackException {};  
        class StackFullException : public StackException {};
        class StackEmptyException : public StackException {};
    }
}

#endif