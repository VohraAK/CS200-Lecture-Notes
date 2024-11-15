#include <iostream>

using namespace std;

class A
{
public:
    virtual void funA()
    {
        cout << "funA-ClassA" << endl;
    }

    void funB()
    {
        cout << "funB-ClassA" << endl;
    }

    void funC()
    {
        cout << "funC-ClassA" << endl;
    }

    void funD()
    {
        cout << "funD-ClassA" << endl;
        funC();
        funA();
    }

    virtual ~A()
    {
        cout << "Virtual Destructor-ClassA" << endl;
    }

};

class B : public A
{
public:
    void funA()
    {
        cout << "funA-ClassB" << endl;
    }

    void funB()
    {
        cout << "funB-ClassB" << endl;
    }

    ~B()
    {
        cout << "Destructor-ClassB" << endl;
    }
};

int main()
{
    A *a = new B();
    a->funA();
    a->funB();
    a->funC();
    a->funD();
    delete a;

    return 0;
}



// #include <iostream>

// class Base 
// {
// public:
//     virtual ~Base() { std::cout << "Base destructor\n"; }
// };

// class Derived : public Base 
// {
// public:
//     ~Derived() { std::cout << "Derived destructor\n"; }
// };

// int main() 
// {
//     Base* ptr = new Derived();
//     delete ptr;  // Derived destructor is called
// }

