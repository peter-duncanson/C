#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // // allocate space for each row in the the 2d array, and a array to hold these pointers
    //
    // // array of pointers to the arrays
    // int **array = malloc(sizeof(int *) * 3);
    //
    // // array to store 3 integers
    // // stores the address of the first int in this memory block
    // int *array_0 = malloc(sizeof(int) * 3);
    // int *array_1 = malloc(sizeof(int) * 3);
    // int *array_2 = malloc(sizeof(int) * 3);
    //
    // *(array) = array_0;
    // *(array + 1) = array_1;
    // *(array + 2) = array_2;
    
    // can reduce this to
    // int **array = malloc(sizeof(int *) * 3);
    // for (int i = 0; i < 3; i++)
    //     array[i] = malloc(sizeof(int) * 3);
    

    // memory will be contiguous on the heap apparently
    int (*array)[5] = malloc(5 * 5 * sizeof(int));

    return 0;
}
