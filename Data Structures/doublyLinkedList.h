#ifndef DLL
#define DLL

template <typename T>

class List
{
protected:
    // define a structure
    struct Node
    {
        T value;
        Node *next;
        Node *previous;
    };

    // initialise sentinel nodes (independent of any list)
    Node *head;
    Node *tail;

public:
    // initialise a list
    List()
    {
        head = new Node;
        tail = new Node;

        head->next = tail;
        tail->previous = head;

        head->previous = nullptr;
        tail->next = nullptr;
    }

    ~List()
    {
        Node *nextNode = head;
        while (nextNode)
        {
            // save next node
            Node *temp = nextNode->next;

            // deallocate current node
            delete nextNode;

            // move forward
            nextNode = temp;
        }
    }

    class Iterator
    {
        friend class List;

    protected:
        Node *ptr;

    public:
        Iterator(Node *p) : ptr(p) {}

        // pre-increment operator
        Iterator operator++()
        {
            if(ptr && ptr->next)
            {
                ptr = ptr->next;
            }

            return *this;
        }
        
        // post-increment opearator
        Iterator operator++(int)
        {
            Iterator it = *this;
            if (ptr && ptr->next)
            {
                ptr = ptr->next;
            }
            return it;
        }

        // dereferencing operator
        T operator*()
        {
            return ptr->value;
        }

        // equality opearator
        bool operator==(const Iterator &it)
        {
            return ptr == it.ptr;
        }

        // inequality opearator
        bool operator!=(const Iterator &it)
        {
            return ptr != it.ptr;
        }

    };

        // inserting an new node before the current node
        void insertBefore(const Iterator &it, const T value)
        {
            Node* newNode = new Node;
            newNode->value = value;

            Node* current = it.ptr;
            newNode->next = current;
            newNode->previous = current->previous;

            // point the previous node to the new node
            current->previous->next = newNode;
            current->previous = newNode;
        }

        // iterator should never point to the head sentinel node
        Iterator begin()
        {
            return Iterator(head->next);
        } 

        Iterator end()
        {
            return Iterator(tail);
        }
        
    };


#endif