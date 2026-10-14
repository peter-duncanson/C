/*
Given two numbers a and b, the task is to swap them.

a = 1101
b = 0101

a = a ^ b -> a = 1000
b = a ^ b -> b = 1101
a = a ^ b -> a = 0101
*/

#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 2;
    int y = 10;
    
    swap(&x, &y);

    printf("x = %d\ny = %d\n", x, y);
    return 0;
}

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
