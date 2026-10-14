#include <stdio.h>

int factorial(int n);

int main(void)
{
    int a = factorial(3);
    printf("%d\n", a);

    return 0;
}

int factorial(int n)
{
    if (n == 1) return n;
    else return n * factorial(n - 1);
}
