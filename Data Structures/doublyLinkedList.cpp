#include "doublyLinkedList.h"
#include <iostream>

int main()
{
    List<int> list;
    List<int>::Iterator it = list.end();
    list.insertBefore(it, 3);
    list.insertBefore(it, 2);
    list.insertBefore(it, 1);

    std::cout << "HEAD -> ";
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "-> TAIL" << std::endl;

    return 0;
}