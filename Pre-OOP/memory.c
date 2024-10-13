#include <stdio.h>
#include <stdlib.h>

typedef struct Point2D
{
    float x, y
} Point2D;

int main()
{
    
    // allocating space for one int
    // ptr = malloc(sizeof(int));

    // allocating space for an array of ints [typecasting to int*]
    // ptr = (int *) malloc(num * sizeof(int));

    Point2D* ptr = (Point2D*) malloc(sizeof(Point2D));

    ptr -> x = 3.14;
    ptr -> y = 6.78;

    return 0;
};