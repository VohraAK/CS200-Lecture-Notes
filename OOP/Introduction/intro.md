<h2 style="text-align: center;">Object Oriented Programming</h2>

### Concepts:

- Abstraction
- Encapsulation
- Inheritance
- Polymorphism

<br>

#### Types of Data-Types:

- Primitive (built-in data-types, e.g. int, char, float, double, etc.)
- Non-primitive (user-defined data-types, e.g. struct, union, enum, etc.)

The instance of a <strong>primitive</strong> data-type is called a <strong>variable</strong>, while the instance of a <strong>non-primitive</strong> data-type is called an <strong>object</strong>.
<br>

---

## Classes and Objects:

A class is a blueprint for an object. An object is an instance of a class.
<br>

### Class

The scope of a class is private by default. The properties can be specified as public or private by the user.

<h5> Example: </h5>

```C++
#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name;
    string address;
    int rollNum;
    string gender;

    // defining mutators and accessors 

    public:

    void setName(string name)
        this->name = name;

    string getName()
        return this->name;

    void setAddress(string address)
        this->address = address;

    string getAddress()
        return this->address;

    void setRollNum(int rollNum)
        this->rollNum = rollNum;

    int getRollNum()
        return this->rollNum;

    void setGender(string gender)
        this->gender = gender;

    string getGender()
        return this->gender;
}

int main()
{
    Student A;

    A.setName("Abdullah");
    A.setAddress("Karachi");
    A.setRollNum(90);
    A.setGender("Male");

    // &A stores the address of the first variable defined in the class.
    cout << &a << '\n';

    return 0;
}
```
<br>

`&A` stores the address of the <strong>first variable</strong> defined in the class.


