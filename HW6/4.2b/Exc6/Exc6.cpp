#include "Stack.hpp"
#include "StackException.hpp"

#include <iostream>

using Mikita::Containers::Stack;
using Mikita::Containers::StackFullException;
using namespace std;

int main() {
    Stack<int, 3> stack;

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    try
    {
        stack.Push(40);
    } catch (const StackFullException&) {
        
        cout << "stack is full." << endl;
    }

    Stack<int, 3> copy(stack);
    Stack<int, 3> assigned;
    assigned = stack;
    cout << "Original stack: " <<  stack.Pop() << endl;
    cout << "Copied stack: " <<  copy.Pop() <<  endl;
    cout << "Assigned stack: " << assigned.Pop() << endl;

    return 0;
}
