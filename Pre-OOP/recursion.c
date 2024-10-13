// in recursion, each function call creates its own stack frame, and keeps stacking them up
// stack overflow occurs when the stack is full

#include <stdio.h>

unsigned long factorial(unsigned long n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

unsigned long exponentiation(unsigned long base, unsigned long power)
{
    if (power == 0)
        return 1;
    return base * exponentiation(base, power - 1);
}

unsigned long fibonacci(unsigned long n)
{
    if (n == 0 || n == 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

unsigned long sumDigits(unsigned long n)
{
    if (n == 0)
        return 0;
    return n % 10 + sumDigits(n / 10);
}

int binarySearch(int* array, int arrayLength, int search, int start, int end)
{
    
    // look at the center element
    int mid = start + (start - end) / 2;

    if (*(array + mid) == search)
        return mid;

    else if (search > *(array + mid))
        return binarySearch(array, arrayLength, search, mid + 1, end);
    
    else 
        return binarySearch(array, arrayLength, search, start, mid - 1);
    

}

int main()
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("%d", binarySearch(array, 10, 2, 0, 9));

    return 0;
}