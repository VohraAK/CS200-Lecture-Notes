#include "dll.h"
#include <iostream>
#include <string>

struct Person
{
    std::string name;
    int age;

    // needed for std::find()
    bool operator==(const Person &other) const
    {
        return (name == other.name && age == other.age);
    }
};

int main()
{
    List<int> list;
    List<int>::Iterator it = list.end();

    it = list.insert(it, 4);
    it = list.insert(it, 7);
    it = list.insert(it, 29);

    list.push_back(56);
    list.push_back(992);
    list.push_front(918);
    list.push_front(918);
    list.pop_back();
    list.pop_back();

    List<int> l2 = list;

    for (it = list.begin(); it != list.end(); it++)
        std::cout << *it << " -> ";

    std::cout << std::endl;

    // List<Person> list;

    // Person p1;
    // p1.name = "Frank Underwood";
    // p1.age = 56;

    // Person p2;
    // p2.name = "Claire Underwood";
    // p2.age = 48;

    // Person p3;
    // p3.name = "Doug Stamper";
    // p3.age = 42;

    // Person p4;
    // p4.name = "Ginny Weasly";
    // p4.age = 20;

    // // inserting from end-of-list
    // auto it = list.end();
    // it = list.insert(it, p1);
    // it = list.insert(it, p2);
    // it = list.insert(it, p3);

    // it = std::find(list.begin(), list.end(), p4);

    // if (it == list.end())
    // {
    //     std::cout << "NOT FOUND!" << std::endl;
    // }

    // else
    // {
    //     std::cout << p2.name << " found with age: " << p2.age << std::endl;
    // }

    // // forward iteration
    // std::cout << "Forward iteration..." << std::endl;
    // for (it = list.begin(); it != list.end(); ++it)
    // {
    //     std::cout << it->name << " | Age: " << it->age << std::endl;
    // }
    // std::cout << std::endl;

    // // reverse iteration (can't use a for loop)
    // it = list.end();

    // std::cout << "Backward iteration..." << std::endl;
    // while (it != list.begin())
    // {
    //     it--;   // should be here, as .end() returns the tail sentinel node
    //     std::cout << it->name << " | Age: " << it->age << std::endl;
    // }

    return 0;
}
