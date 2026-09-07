#include "Stack.hpp"
#include "ArrayException.hpp"
#include <iostream>

using namespace Mikita::Containers;
using namespace std;

int main() {
    Stack<int> s(3);

    cout << "Pushing 10, 20, 30" << endl;
    s.Push(10);
    s.Push(20);
    s.Push(30);

    //checking exception 
    try {
        cout << "Pushing 40 onto full stack" << endl;
        s.Push(40);
    } catch (const ArrayException& e) {
        cout <<  e.GetMessage() << endl;
    }

    cout << "Pop: " << s.Pop() << endl;
    cout << "Pop: " << s.Pop() << endl;
    cout << "Pop: " << s.Pop() << endl;

    try {
        cout << "Popping empty stack" << endl;
        cout << s.Pop() << endl;
    } catch (const ArrayException& e) {
        cout << "Caught on Pop: " << e.GetMessage() << endl;
    }


    Stack<int> s2(5);
    s2.Push(1);
    
    s2.Push(2);

    Stack<int> s3(s2);
    cout << "Copy Pop: " << s3.Pop() << endl;

    Stack<int> s4;
    s4 = s2;
    cout << "Assigned Pop: " << s4.Pop() << endl;
    cout << "Assigned Pop: " << s4.Pop() << endl;

    return 0;
}
