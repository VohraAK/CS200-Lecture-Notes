#include <iostream>

class Base {
public:
    virtual void print() = 0;
};

class Derived : public Base {
public:
    void print() override {
        std::cout << "Derived class" << std::endl;
    }
};

int main() {

    Base *b = new Derived();
    
    std::cout << "Calling print()..." << std::endl;
    b->print();

    return 0;
}