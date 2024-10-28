// #include <iostream>

// class Base {
// public:
//     int pub;     // Accessible publicly
// protected:
//     int prot;    // Accessible within Base and Derived
// private:
//     int priv;    // Only accessible within Base

// public:

//     Base()
//     {
//         std::cout << "Base Default Constructor" << std::endl;
//     }
//     Base(int pub, int prot, int priv)
//     {
//         std::cout << "Base Param Constructor" << std::endl;
//         this->pub = pub;
//         this->prot = prot;
//         this->priv = priv;
//     }
// };

// // calling base constructor in derived class
// class Derived : public Base {
// private:
//     int a;
// public:
    
//     Derived()
//     {
//         // base default constructor is called without using constructor initializer list
//         std::cout << "Derived Default Constructor" << std::endl;
//     }
//     Derived(int pub, int prot, int priv, int a) : Base(pub, prot, priv)
//     {
//         // base param constructor must be called using the above constructor initializer list
//         // otherwise only the base default will be called
//         std::cout << "Derived Param Constructor" << std::endl;
//         this->a = a;
//     }
// };


// // main function
// int main()
// {
//     // creating object of derived class
//     std::cout << std::endl << "Creating Object 1:" << std::endl;
//     Derived obj1;
//     std::cout << std::endl <<"Creating Object 2:" << std::endl;
//     Derived obj2(1, 2, 3, 10);

//     return 0;
// }



// #include <iostream>
// using namespace std;

// class Box {
// private:
//     double width;

// public:
//     int amount;

// public:
//     Box(double w, int a) : width(w), amount(a) {}

//     // Member function to print Box data
//     void print(ostream& out) const {
//         out << "Box width: " << width << std::endl;
//     }
// };

// // Non-member function that calls the member function
// ostream& operator<<(ostream& out, const Box& box) {
//     box.print(out); // Calls the print member function to access private data
//     out << "Number of boxes: " << box.amount;
//     return out;
// }

// int main() {
//     Box box(10.5, 5);
//     cout << box << endl; // Calls the overloaded << operator
//     return 0;
// }