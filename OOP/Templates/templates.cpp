#include <iostream>

// function template that searches a numeric array for a specified value

// template <typename T>
// int searchValue(T* arr, int size, T value)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == value)
//             return i;
//     }

//     return -1;
// }

// int main()
// {
//     int arr1[4] = {3, 6, 0, 12};
//     float arr2[5] = {9.3, 22.2, 9.44, 9, 1222.2};
//     double arr3[2] = {12.333343434343, 933.443243};

//     std::cout << searchValue(arr1, 4, 12);
//     std::cout << searchValue(arr2, 5, float(9.44));
//     std::cout << searchValue(arr3, 2, 12.333343434343) << std::endl;

//     return 0;
// }


// #include <iostream>

// template <typename T>
// class Vector
// {
// public:
//     T x, y;
//     Vector(T x, T y) : x(x), y(y) {}
//     void printVector() {std::cout << "<" << x << ", " << y << ">" << std::endl;}
// };

// int main()
// {
//     Vector<int> v1(1, 2);
//     Vector<double> v2(2.3, 4.5);

//     v1.printVector();
//     v2.printVector();

//     return 0;
// }


#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;        // Pointer to dynamically allocated array
    int top;       // Index of the top element
    int capacity;  // Maximum capacity of the stack

public:
    // Constructor
    Stack(int size) {
        arr = new T[size];
        capacity = size;
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(T value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return;
        }
        --top;
    }

    // Peek the top element of the stack
    T peek() const {
        if (isEmpty()) {
            throw runtime_error("Stack is empty! Cannot peek.");
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() const {
        return top == capacity - 1;
    }

    // Get the current size of the stack
    int size() const {
        return top + 1;
    }
};

int main() {

    Stack<int> s1(5);

    s1.push(345);
    s1.push(4);
    s1.push(-91);

    cout << "Top of Stack 1: " << s1.peek() << endl;

    s1.pop();

    cout << "Top of Stack 1 after pop: " << s1.peek() << endl;
    cout << "Stack 1 size: " << s1.size() << endl << std::endl;


    Stack<string> s2(3);
    
    s2.push("Hello");
    s2.push("World");

    cout << "Top element: " << s2.peek() << endl;
    cout << "Stack 2 size: " << s2.size() << endl;

    return 0;
}