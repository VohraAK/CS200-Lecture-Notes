#include <stdio.h>

void greet(char* name)
{
    printf("Hello %s!\n", name);
}


int foo(int n)
{
    return n+1;
}

int bar(int n)
{
    return n+2;
}

int baz(int n)
{
    return n+3;
}


int main()
{
    // char name[] = "Abdullah";

    // void (*fptr) (char*) = &greet;

    // (*fptr)(name);


    int (*fptr[3])(int) = {foo, bar, baz};
    
    for(int i = 0; i < 3; i++)
    {
        printf("%d\n", (*(*(fptr + i))) (3));
    }

    return 0;
}