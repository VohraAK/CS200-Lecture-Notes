#include <iostream>
#include <cmath>
using namespace std;

class DynamicArray
{
    int* data;
    int size;

public:
    DynamicArray(int size)
    {
        this->data = new int[size];
        this->size = size;
    }

    // copy constructor
    DynamicArray(DynamicArray& d)
    {
        this->data = new int[d.size];
        this->size = d.size;
        for (int i = 0; i < d.size; i++)
        {
            this->data[i] = d.data[i];
        }
    }

    // print method
    void print()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << this->data[i] << " ";
        }
        cout << endl;
    }

    // add at index method
    void addAt(int index, int value)
    {
        this->data[index] = value;
        printf("Added %d at %d\n", value, index);
    }
};

int main()
{
    DynamicArray d1(5);

    d1.addAt(0, 1);
    d1.addAt(1, 4);
    d1.addAt(2, 9);
    d1.addAt(3, 16);
    d1.addAt(4, 25);

    printf("Printing d1: ");
    d1.print();

    // copy to d2
    DynamicArray d2(d1);

    printf("Printing d2: ");
    d2.print();

    return 0;
}