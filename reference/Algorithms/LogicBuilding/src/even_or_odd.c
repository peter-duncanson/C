/*
Given a number n, check whether it is even or odd. Return true for even and false for odd.
*/
#include <stdio.h>
#include <stdbool.h>

bool is_even(int n);

int main(void)
{
    int x = 3;

    if (is_even(x))
        puts("even");
    else
        puts("odd");
    return 0;
}

bool is_even(int n)
{
    return !(n & 1);
}
