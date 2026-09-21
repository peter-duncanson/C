#include <stdio.h>

// 1D array decays to pointer
void change_array(int arr[], int size)
{
    arr[0] = 999;         // Modifies the original array

    // arr is really treated as:
    // int *arr
}

// pointer itself passed by value
void move_pointer(int *p)
{
    p += 2; // Only moves the local copy of p
    printf("Inside move_pointer: %d\n", *p);
}
/*
2D array
const int arr[][4]
is effectively:
const int (*arr)[4]
It means pointer to an array of 4 ints.
*/
void print_2d_array(const int arr[][4], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// pointer to a row
void demonstrate_rows(const int (*p)[4])
{
    /*
     * p points to a whole row.
     *
     * p + 1 moves forward by ONE ROW,
     * which means 4 ints.
     */

    p += 1;

    printf("Second row, first element: %d\n", (*p)[0]);

    /*
     * p[0] is the row itself.
     *
     * The row is an array of 4 ints, which can
     * decay to an int* when appropriate.
     */

    const int *first_element = p[0];

    printf("First element through int*: %d\n", *first_element);
}

int main(void)
{
    int arr[] = {10, 20, 30, 40};
    change_array(arr, 4);

    printf("arr[0] = %d\n", arr[0]);
    // 999
    //
    // The array wasn't copied.
    // arr decayed to an int* pointing
    // to its first element.

    int *p = arr;
    printf("Before: %d\n", *p);
    move_pointer(p);
    printf("After:  %d\n", *p);
    // Still points to arr[0].
    //
    // The pointer itself was passed by value,
    // so move_pointer() only moved its local copy.

    const int matrix[3][4] = {
        { 1,  2,  3,  4 },
        { 5,  6,  7,  8 },
        { 9, 10, 11, 12 }
    };
    print_2d_array(matrix, 3);


    /*
     * matrix has type:
     *
     *     int [3][4]
     *
     * When passed to a function, the outer
     * array decays:
     *
     *     int [3][4]
     *          ↓
     *     int (*)[4]
     *
     * So this is valid:
     */
    demonstrate_rows(matrix);


    /*
     * matrix[0] is an array of 4 ints:
     *
     *     int [4]
     *
     * When used in this context, it decays
     * to a pointer to its first int:
     *
     *     int [4]
     *       ↓
     *     int *
     */

    const int *row_pointer = matrix[0];
    printf("matrix[0][0] = %d\n", *row_pointer);


    const int (*row_ptr)[4] = matrix;
    /*
     * row_ptr points to row 0.
     */
    printf("Row 0: %d\n", (*row_ptr)[0]);
    row_ptr++;
    /*
     * Now row_ptr points to row 1.
     *
     * It moved by sizeof(int[4]), NOT sizeof(int).
     */
    printf("Row 1: %d\n", (*row_ptr)[0]);

    return 0;
}
