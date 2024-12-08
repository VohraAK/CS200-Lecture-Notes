#ifndef DLL_H
#define DLL_H

#include <iterator>
#include <algorithm>
#include <cstddef>

template <class T>
class List
{

protected:
    // define an integrated protected Node struct
    struct Node
    {
        T value;
        Node *previous;
        Node *next;
    };

    // member variables
    Node *head;
    Node *tail;
    size_t _size;

public:
    // helper functions for constructors
    void init()
    {
        // initialize head and tail
        head = new Node;
        tail = new Node;

        // set endpoints
        head->previous = nullptr;
        tail->next = nullptr;

        // point head and tail (empty list)
        head->next = tail;
        tail->previous = head;

        _size = 0;
    }

    void copy(const List &other)
    {
        Iterator it1 = end();
        Iterator it2 = other.begin();

        while (it2 != other.end())
        {
            insert(it1, *it2); // insert in this list at current position, the value at it2
            it2++;             // move to the next node
        }

        _size = other._size;
    }

    // constructor
    List() { init(); }

    // copy constructor
    List(const List &other)
    {
        init();
        copy(other);
    }

    // assignment operator
    void operator=(const List &other)
    {
        clear();
        copy(other);
    }

    // function to delete all nodes excluding head and tail sentinel nodes
    void clear()
    {
        // start from the node pointed to by head
        Node *_1 = head->next;

        // iterate through list
        while (_1 != tail)
        {
            // save the next node
            Node *_2 = _1->next;

            // delete the current node
            delete _1;

            // point head to next node and vice verse
            head->next = _2;
            _2->previous = head;

            // step forward
            _1 = _2;
        }

        _size = 0;
    }

    // destructor
    ~List()
    {
        clear();

        // delete sentinel nodes
        delete head;
        delete tail;
    }

    // define an iterator member class, needs to be bidirectional, will never point to the sentinel node
    class Iterator
    {
        friend class List<T>;

    private:
        Node *ptr;

    public:
        // STL implementation tags
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;

        // constructor
        Iterator(Node *p) : ptr(p) {};

        // pre-increment operator
        Iterator &operator++()
        {
            // check for not end-of-list
            if (ptr && ptr->next)
                ptr = ptr->next;

            return *this;
        }

        // post-increment operator
        Iterator operator++(int)
        {
            Iterator _ = *this;

            // call pre-decrement operator
            ++(*this);

            return _;
        }

        // pre-decrement operator
        Iterator operator--()
        {
            // check if previous node is not the head sentinel node
            if (ptr && ptr->previous)
            {
                ptr = ptr->previous;
            }

            return *this;
        }

        // post-decrement operator
        Iterator operator--(int)
        {
            Iterator _ = *this;

            --(*this);

            return _;
        }

        // equality operators
        bool operator==(const Iterator &other) const
        {
            return (ptr == other.ptr);
        }

        bool operator!=(const Iterator &other) const
        {
            return !(*this == other);
        }

        // indirection operators
        T &operator*() const
        {
            return (ptr->value);
        }

        T *operator->() const
        {
            return &(ptr->value);
        }
    };

    // list accessors
    Iterator begin() const
    {
        // never access head
        return (Iterator(head->next));
    }

    Iterator end() const
    {
        return (Iterator(tail));
    }

    // function for inserting a value immediately before a specified position
    Iterator insert(const Iterator &_position, const T &_value)
    {
        // create a new node
        Node *newNode = new Node;
        newNode->value = _value;

        Node *current = _position.ptr;

        // point the new node to the node at specified position
        newNode->next = current;

        // point the new node to the previous node in the list
        newNode->previous = current->previous;

        // point the previous node in the list to the new node
        current->previous->next = newNode;

        current->previous = newNode;

        _size++;

        return Iterator(newNode);
    }

    // insert value to the front of the list
    void push_front(const T &val)
    {
        // position of newNode, immediately before tail
        Iterator pos = begin();

        insert(pos, val);
    }

    // inserts value to the end of the list
    void push_back(const T &val)
    {
        Iterator pos = end();

        insert(pos, val);
    }

    void pop_front()
    {
        if (empty())
            return;

        Iterator pos = begin();
        erase(pos);
    }

    void pop_back()
    {
        if (empty())
            return;

        Iterator pos = end();
        --pos;
        erase(pos);
    }

    Iterator erase(const Iterator &pos)
    {
        // check if pos exists
        if (pos.ptr && pos.ptr->next && pos.ptr->previous)
        {
            // connect the previous node to the node after pos
            pos.ptr->previous->next = pos.ptr->next;
            pos.ptr->next->previous = pos.ptr->previous;

            // create iterator for next-in-line node
            Iterator temp(pos.ptr->next);

            delete pos.ptr;

            _size--;

            return temp;
        }

        // node does not exist
        return Iterator(nullptr);
    }

    int size() { return _size; }

    // check if list is empty
    bool empty() { return (_size == 0); }

    // peek at first element
    T &front() { return *(begin()); }

    // peek at last element
    T &back() { return *(end()--); }
};

#endif