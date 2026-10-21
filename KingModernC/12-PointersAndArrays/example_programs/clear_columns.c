// ================================================================================================
// Clear column i of array a
// ================================================================================================
#include <stdio.h>

#define N_ROWS 5
#define N_COLS 5

void print_array(int n, int a[][n]);

int main(void)
{
    int a[N_ROWS][N_COLS] = {
        { 1, 2, 3, 4, 5},
        { 1, 2, 3, 4, 5},
        { 1, 2, 3, 4, 5},
        { 1, 2, 3, 4, 5},
        { 1, 2, 3, 4, 5}
    };
    int (*p)[N_COLS], i = 3;
    
    print_array(N_ROWS, a);

    // for (p = &a[0]; p < &a[N_ROWS]; p++)
    // {
    //     (*p)[i] = 0;
    // }
    for (p = a; p < a + N_ROWS; p++)
    {
        (*p)[i] = 0;
    }

    print_array(N_ROWS, a);

    return 0;
}

void print_array(int n, int a[][n])
{
    for (int i = 0; i < N_ROWS; i++)
    {
        for (int j = 0; j < N_COLS; j++)
        {
            printf("%d  ", a[i][j]);
        }
    puts("");
    }
    puts("");
}
