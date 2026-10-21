#include <stdio.h>

void function(int x);
double add_dbl(double x, double y);
int (*select_operation(void))(int, int);

int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

int main(void)
{
    void (*function_pointer)(int);
    function_pointer = function;
    (*function_pointer)(4);

    double (*add_pointer)(double, double) = add_dbl;
    printf("result of add_pointer is %lf\n", (*add_pointer)(1.0, 2.0));

    // array of pointers to functions that accept two ints and return an int
    int (*arithmetic[])(int, int) = { add, subtract, multiply, divide };
    printf("Product is: %d\n", (*arithmetic[2])(3, 15));

    // we can create functions that themselves return a function pointer
    

    return 0;
}

void function(int x)
{
    printf("x = %d\n", x);
}

double add_dbl(double x, double y)
{
    return x + y;
}

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}
