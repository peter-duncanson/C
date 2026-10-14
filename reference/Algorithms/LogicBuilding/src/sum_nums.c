/*
Given a positive integer n, find the sum of the first n natural numbers.

Examples : 

    Input: n = 3
    Output: 6
    Explanation: 1 + 2 + 3 = 6

    Input: n = 5
    Output: 15 
    Explanation:  1 + 2 + 3 + 4 + 5 = 15
*/
#include <stdio.h>

int sum_nums(int n);

int main(void)
{
    int sum = sum_nums(5);
    printf("sum = %d\n", sum);
    return 0;
}

int sum_nums(int n)
{
    return (n * (n + 1)) >> 1;
}
