#include <stdio.h>
#include <stdlib.h>
#include "exercises.h"

void print_array(int *a, int n);

int main(void)
{
    int *arr = create_array(10, 7);
    print_array(arr, 10);
    free(arr);

    return 0;
}

void print_array(int *a, int n)
{
    for (int *p = a; p < a + n; p++)
        printf("%d\n", *p);
}

