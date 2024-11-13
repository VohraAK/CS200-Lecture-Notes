#include <string>
#include <iostream>

template <typename T, typename U>
auto max(T a, U b)
{
    return (a > b) ? a : (b > a) ? b : 0;
}

int main()
{
    int a = 4, b = 15;
    
    std::cout << max(a, b) << std::endl;

    return 0;
}