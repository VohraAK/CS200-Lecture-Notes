#include <iostream>
#include <string>

int divide (int a, int b)
{
    if (b == 0)
    {
        std::string eString = "Division By Zero Exception";
        throw eString;
    }

    return (a / b);
}


int main()
{
    try
    {
        std::cout << divide(10, 0) << std::endl;
    }
    catch(std::string e)
    {
        std::cerr << e << std::endl;
    }
    

    return 0;
}