/* =============================================================================
 * C Programming - A Modern Approach - K.N. King
 * Chapter 16 - Structures, Unions, and Enumerations
 * Exercises
 * ========================================================================== */
#include <stdio.h>

/*
1.  In the following declarations, the x and y structures have members named
    x and y, are these declarations legal? Could both declarations appear as
    shown in the program?

    struct { int x, y; } x;
    struct { int x, y; } y;

    Yes this is legal, the structures have different names and they each have
    their own scope for variable names.
*/

/*
2.  (a) Declare structure variables named c1, c2, and c3, each having members
    real and imaginary of type double.
    (b) Modify the declaration in part (a) so that c1's members initially have
    the values 0.0 and 1.0 while c2's members are 1.0 and 0.0 initially. (c3 is
    not initialized)
    (c) Write statements that add the corresponding members of c1 and c2,
    storing the result in c3.

    struct { double real, imaginary; }
    c1 = { 0.0, 1.0 },
    c2 = { 1.0, 0.0 },
    c3;

    void three(void)
    {
        printf("c1.real = %lf\nc2.imaginary = %lf\nc2.real = %lf\nc2.imaginary = %lf\n",
                c1.real, c1.imaginary, c2.real, c2.imaginary);
        c3.real = c1.real + c2.real;
        c3.imaginary = c1.imaginary + c2.imaginary;
        printf("c3:\nreal = %lf\nimag = %lf\n", c3.real, c3.imaginary);
    }
*/

/*
3.  (a) Show how to declare a tag named complex for a structure with two
    members, real and imaginary of type double.
    (b) Use the complex tag to declare variables named c1, c2, and c3.
    (c) Write a function named make_complex that stores its two arguments
    (both of type double) in a complex structure, then returns the structure.

    struct complex { double real, imag; };
    struct complex c1, c2, c3;

    struct complex make_complex(double real, double imag);

    int main(void)
    {
        c1 = make_complex((double)0.0, (double)1.0);
        
        printf("c1:\nreal = %lf\nimag = %lf\n", c1.real, c1.imag);
        return 0;
    }

    struct complex make_complex(double real, double imag)
    {
        struct complex res = { real = real, imag = imag };

        return res;
    }
*/

/*
5.  Write the following functions, assuming that the date structure contains
    three members: month, day and year all of type int.

    (a) int day_of_year(struct date d);
    Returns the day of the year (an integer between 1 and 366)
    (b) int compare_dates(struct date d1, struct date d2);
    Returns -1 if d1 is earlier than d2, +1 if d1 is a later date than d2 and 0
    if they are equal.
*/

struct date { int month, day, year; };
struct date d1 = { 8, 12, 1997, };
struct date d2 = { 3, 27, 2001, };

int day_of_year(struct date d)
{
    int day = d.day;
    // I dont feel like doing all the different month amounts
    return day;
}

int compare_dates(struct date d1, struct date d2)
{
    if ()

}


int main(void)
{
    
    return 0;
}


