// static variables are initialized only once and are not destroyed when the program ends
// scope of a variable: local or global`
// variable lifetime: local -> created inside the function/scope, dies when the function/scope ends
//                    global -> created when the program starts, dies when the program ends
//                    static -> created when the program starts, dies when the program ends

// x86 memory layout: stack, heap, BSS, data, text
//     stack: for local variables
//     heap: for dynamic memory allocation
//     BSS: for static variables
//     data: for global variables`
//     text: for function code

#include <stdio.h>
#include <stdlib.h>

// create a function when prints the static int and increments it locally

void increment()
{
    static int x = 0;
    x++;
    printf("%d\n", x);
}

int main()
{
    increment();
    increment();
    increment();
    return 0;
}