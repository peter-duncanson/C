/*
Given a positive integer n, we have to find the sum of squares of first n natural numbers. 
Examples : 

    Input : n = 2
    Output: 5
    Explanation: 1^2+2^2 = 5

    Input : n = 8
    Output: 204
    Explanation :  1^2 + 2^2 + 3^2 + 4^2 + 5^2 + 6^2 + 7^2 + 8^2 = 204
*/
#include <stdio.h>

int sum_squares(int n);

int main(void)
{
    int x = 8;
    printf("Sum of squares: %d\n", sum_squares(x));
    return 0;
}

int sum_squares(int n)
{
    // return (n * (n + 1) * (2 * n + 1)) / 6;

    // restructure to avoid overflow
    // n * (n + 1) must always be divisible by 2
    return ((n * (n + 1) / 2) * (2 * n + 1)) / 3;
}
