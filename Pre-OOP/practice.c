#include <stdio.h>
#include <string.h>

#define ROWS 3
#define COLS 3

typedef struct Point2D
{
    // alias created for struct named Point2D
    float x, y;
} Point2D;

/**
 * @brief Checks if a given integer is a prime number
 *
 * @param[in] x The number to be checked
 * @return 1 if x is a prime number, 0 otherwise
 */
int isPrime(int x)
{
    if (x <= 1)
    {
        return 0;
    }
    for (int i = 2; i <= x / 2; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
};
/**
 * @brief Reverses a given string in-place.
 *
 * @param[inout] str The string to be reversed
 */
void reverseString(char str[])
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    };
};

/**
 * @brief Returns a pointer to the greater of two integers.
 *
 * @param[in] a pointer to the first integer
 * @param[in] b pointer to the second integer
 * @return pointer to the greater of the two integers, or NULL if either a or b is NULL
 */
int *max(int *a, int *b)
{
    if (a == NULL || b == NULL)
        return NULL;
    return (*a > *b) ? a : b;
};

int main()
{
    // int arr[ROWS][COLS] = {};

    // int *start = arr;

    // printf("Enter elements for %dx%d array:\n", ROWS, COLS);

    // for (int i = 0; i < ROWS; i++)
    // {
    //     for (int j = 0; j < COLS; j++)
    //         scanf("%d", (*(arr + i) + j));
    // };

    Point2D p1;
    Point2D p2;

    

    return 0;
};
