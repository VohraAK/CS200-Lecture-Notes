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
    {
        this->name = name;
    }

    string getName()
    {
        return this->name;
    }

    void setAddress(string address)
    {
        this->address = address;
    }

    string getAddress()
    {
        return this->address;
    }

    void setRollNum(int rollNum)
    {
        this->rollNum = rollNum;
    }

    int getRollNum()
    {
        return this->rollNum;
    }

    void setGender(string gender)
    {
        this->gender = gender;
    }

    string getGender()
    {
        return this->gender;
    }
};

int main()
{
    Student A;

    A.setName("Abdullah");
    A.setAddress("Karachi");
    A.setRollNum(90);
    A.setGender("Male");

    cout << &A;

    return 0;
}