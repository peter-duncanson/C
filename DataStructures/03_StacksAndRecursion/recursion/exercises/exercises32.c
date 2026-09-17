// Recursion exercises 3.2

#include <stdio.h>

int exercise_one(int n);

int main(void)
{
    int a = exercise_one(1); 
    int b = exercise_one(2); 
    int c = exercise_one(3); 
    int d = exercise_one(99); 
    int e = exercise_one(100); 
    int f = exercise_one(128);
    printf("a: %d\nb: %d\nc: %d\nd: %d\ne: %d\nf: %d\n", a, b, c, d, e, f);
    return 0;
}

int exercise_one(int n)
{
    if (n == 0) return 0;
    else if (!(n & 1) && n > 0) return exercise_one((int) n * 0.5);
    else if ((n & 1) && n > 0) return 1 + exercise_one(n - 1);
    else return n;
}
