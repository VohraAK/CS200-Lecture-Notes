# Function Pointers
Function pointers are used to store addresses of functions in C.

They are used in C to call functions at any point in the program

Syntax in calling function: `(return_type) *(fptr) (arg_type)`

Example:
```C

#include <stdio.h>

void greet(char* name)
{
    printf("Hello %s!\n", name);
}

int main()
{
    char name[] = "Abdullah";

    void (*fptr) (char*) = &greet;

    (*fptr)(name);
    
    return 0;
}

```
  
<br>Like other pointers, we can also store function pointers in arrays.
<br>

```C

#include <stdio.h>

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
    int arr[3] = {foo, bar, baz};
    int (*fptr[3])(int) = {foo, bar, baz};
    
    for(int i = 0; i < 3; i++)
    {
        printf("%d\n", (*fptr[i])(3));
    }

    return 0;
}

```