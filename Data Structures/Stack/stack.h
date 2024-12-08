#ifndef STACK_H
#define STACK_H

#include "../DoublyLinkedList/dll.h"

template <typename T>
class Stack
{
private:
    List<T> list;

public:
    bool empty() { return list.empty(); }

    void push(const T &val) { list.push_front(val); }

    T pop()
    {
        if (list.empty())
            throw std::runtime_error("Stack is empty");

        T popped = list.front();
        list.pop_front();
        return popped;
    }

    T peek()
    {
        if (list.empty())
            throw std::runtime_error("Stack is empty");

        return list.front();
    }

    size_t size() { return list.size(); }
    auto begin() { return list.begin(); }
    auto end() { return list.end(); }
    
};

#endif