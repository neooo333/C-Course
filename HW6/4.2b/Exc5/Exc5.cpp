#include "stack.hpp"
#include "stack_exception.hpp"

#include <iostream>
using Mikita::Containers::Stack;
using Mikita::Containers::StackEmptyException;
using Mikita::Containers::StackFullException;


int main()
{
    Stack<int> stack(3);

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    try
    {
        stack.Push(40);
    }
    catch (const StackFullException& e)
    {
        std::cout << "Cannot push: stack is full." <<std::endl;
    }

    try
    {
        std::cout << stack.Pop() << std::endl;
        std::cout << stack.Pop() << std::endl;
        std::cout << stack.Pop() << std::endl;
        std::cout << stack.Pop() << std::endl;
    }
    catch (const StackEmptyException& e)
    {
        std::cout << "Cannot pop: stack is empty.\n";
    }

    return 0;
}
