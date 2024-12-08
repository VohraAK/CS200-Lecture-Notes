#include "stack.h"
#include <iostream>

int main()
{
    Stack<int> stack;

    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(987);

    stack.pop();
    stack.pop();


    std::cout << "PEEKING: " << stack.peek() << std::endl;

    for (auto it = stack.begin(); it != stack.end(); it++)
        std::cout << *(it) << ", ";
    
    std::cout << std::endl;

    std::cout << "Size of stack: " << stack.size() << std::endl;

    return 0;
}