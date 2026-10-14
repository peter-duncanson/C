/*
Given two integers n and m (m != 0). Find the number closest to n and divisible by m.
If there is more than one such number, then output the one having maximum absolute value.

Input: n = 13, m = 4
Output: 12
Explanation: 12 is the closest to 13, divisible by 4.

Input: n = -15, m = 6
Output: -18
Explanation: Both -12 and -18 are closest to -15, but -18 has the maximum absolute value.
*/

#include <stdio.h>
#include <stdlib.h>

int closest(int n, int m);

int main(void)
{
    int n = 13;
    int m = 4;

    printf("n = %d\nm = %d\noutput = %d\n", n, m, closest(n, m));

    return 0;
}

int closest(int n, int m)
{
    int quotient = n / m;
    int a = quotient * m;
    int b = ((n * m) > 0) ? m * (quotient + 1) : m * (quotient - 1);
    return (abs(n - a) < abs(n - b)) ? a : b;
}
