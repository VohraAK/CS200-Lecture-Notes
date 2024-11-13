<h1 style="text-align:center;">Polymorphism</h1>

- Polymorphism is the ability of an object to exhibit different characteristics based on certain circumstances.

<h3>Types of Polymorphism</h3>

- Compile-time polymorphism
- Runtime polymorphism

---
<h3 style="text-align: center;">Compile-time Polymorphism</h3>

- Compile-time polymorphism is resilved at compile-time typically through function overloading and operator overloading.

- The compiler decides which function / operator to call based on the context in which it is used.
---
<h3 style="text-align:center;">Run-time Polymorphism</h3>

- Run-time polymorphism is the ability of an object to exhibit different characteristics based on the context in which it is used.

<br>

Run-time polymorphism is implemented using:

- Inheritance
- Function overriding
- Virtual functions
- Base class pointer / reference.

<br>

<h4>Virtual Functions</h4>

- A function defined in the base class which can be overriden in the derived classes.



<h5>Example</h5>

```C++
#include <iostream>

class Base {
public:
    virtual void print() {
        std::cout << "Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void print() override {
        std::cout << "Derived class" << std::endl;
    }
};

int main() {
    std::cout << "Defining a base class object..." << std::endl;
    Base *b = new Derived();

    std::cout << "Calling print()..." << std::endl;
    b->print();

    return 0;
}
```

<h5>Output</h5>

![alt text](assets/image.png)

<br>

- At run-time, a base class pointer may store the reference to a derived class object. 

- Declaring the base class method as virtual allows the derived class to override it; the derived class method is now called through the base class pointer.

<br>

<h4>Virtual Functions Under the Hood (Vtables)</h4>

- The compiler constructs a virtual table for every class containing virtual functions.
- The virtual table contains the addresses of all the virtual functions in the class.
- Vtables store the derived class implementations of the virtual functions, otherwise they store the base class implementations.

<br>

<h4>Abstract Classes</h4>

- Any class which contains at least one <strong>pure virtual function</strong> is an abstract class. 
- Pure virtual functions in an abstract class are declared as `virtual`, have no implementation, and have `= 0` at the end of its signature.
- Derived classes need to override the pure virtual functions to not exhibit abstract class behavior.
- Abstract classes are used to define a common "interface" for its derived classes.


<h5>Example</h5>

```C++
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
    std::cout << "Defining a base class object..." << std::endl;
    Base *b = new Derived();

    std::cout << "Calling print()..." << std::endl;
    b->print();

    return 0;
}
```

<h5>Output</h5>

![alt text](assets/image.png)

---
<h3>Virtual Destructors</h3>

- When an object is deleted through its base class pointer, the destructor being called will depend on whether the base class destructor is virtual or not.

- If the base class destructor is virtual, the derived destructor will be called with the base class destructor, otherwise, <strong>only</strong> the base class destructor will be called.

<h5>Example 1: Without Virtual Destructor</h5>

```C++
class Base 
{
public:
    ~Base() { std::cout << "Base destructor\n"; }
};

class Derived : public Base 
{
public:
    ~Derived() { std::cout << "Derived destructor\n"; }
};

int main() 
{
    Base* ptr = new Derived();
    delete ptr;  // Undefined behavior! Only Base destructor is called
}

```

![alt text](assets/image-2.png)

<br>

<h5>Example 2: With Virtual Destructor</h5>

```C++
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
```
![alt text](assets/image-3.png)