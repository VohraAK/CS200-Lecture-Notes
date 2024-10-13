#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

/**
 * @brief Creates a 2D array with size ROWS x COLS dynamically.
 *
 * @return A pointer to the 2D array.
 */
int** create2DArray()
{
    // allocate array of pointers with size ROWS 
    int** array = (int**) malloc(ROWS * sizeof(int*));

    for (int i = 0; i < ROWS; i++)
        // allocate ROW no. of int arrays with size COLS
        *(array + i) = (int*) malloc(COLS * sizeof(int));

    return array;
}

/**
 * @brief Frees a 2D array allocated by create2DArray() dynamically.
 *
 * @param[in] array The 2D array to be freed.
 *
 * @details
 * The function takes a pointer to the 2D array as argument and frees the memory allocated for it.
 * The function does not return anything.
 */
void free2DArray(int** array)
{
    for (int i = 0; i < ROWS; i++)
        free(*(array + i));
    free(array);
}

int main()
{
    int** array = create2DArray();

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            *(*(array + i) + j) = i + j;
    }

    

    free2DArray(array);

    return 0;
}