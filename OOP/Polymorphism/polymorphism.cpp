#include <iostream>

class Base 
{
public:
    virtual ~Base() { std::cout << "Base destructor\n"; }
};

class Derived : public Base 
{
public:
    ~Derived() { std::cout << "Derived destructor\n"; }
};

int main() 
{
    Base* ptr = new Derived();
    delete ptr;  // Derived destructor is called
}

