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

// struct date { int month, day, year; };
// struct date d1 = { 8, 12, 1997, };
// struct date d2 = { 3, 27, 2001, };
//
// int day_of_year(struct date d)
// {
//     int day = d.day;
//     // I dont feel like doing all the different month amounts
//     return day;
// }
//
// int compare_dates(struct date d1, struct date d2)
// {
//     if ()
//
// }
//
//
// int main(void)
// {
//
//     return 0;
// }
//

// 6.   Write the following function, assuming that the time structure
//      contains three members; hours, minutes, and seconds all of type
//      int.
//
//      struct time split_time(long total_seconds);
//
//      the function accepts an amount of seconds and returns a struct with
//      the seconds converted.
struct time split_time(long total_seconds)
{
    struct time {
        int hours;
        int minutes;
        int seconds;
    } t;
    t.hours = total_seconds % 3600;
    t.minutes = (total_seconds - t.hours * 3600) % 60;
    t.seconds = (total_seconds - ((t.hours * 3600) + (t.minutes * 60)));
    return t;
}
//
// 7.   Assume that the fraction structure contains two members: numberator
//      and denominator. Write functions that perform the following operations
//      on the struct fractions.
//      (a) reduce the fraction f to lowest terms
//      (b) add the fractions f1 and f2
//      (c) subtract the fraction f2 from the fraction f1
//      (d) multiply the fractions f1 and f2
//      (e) divide the fraction f1 by the fraction f2
//
// 8.   Let color be the following structure:
//      struct color {
//          int red;
//          int green;
//          int blue;
//      };
//
//      (a) write a declaration for a const variable named MAGENTA of type
//          struct color whose members have the values 255, 0, 255
//      (b) repeat part a but use a designated initializer, not specifying the
//          value of green to allow it to default to zero
//
// 9.   Write the following functions for the color structure defined in
//      exercise 8.
//      (a) struct color make_color(int red, int green, int blue);
//      (b) int get_red(struct color c);
//      (c) bool equal_color(struct color c);
//      (d) struct color brighter(struct color c);
//          -> divide all members by 0.7
//      (e) struct color darker(struct color c);
//          -> multiply all member by 0.7
//  
// 10.  The following structures are designed to store information about objects
//      on a graphics screen:
//      struct point { int x, y; };
//      struct rectangle { struct point upper_left, lower_right; };
//      A point structure stores the x and y coordinates of a point on the
//      screen. A rectangle structure stores the coordinates of the upper left
//      and lower right corners of a rectangle. Write functions that perform
//      the following operations on a rectangle structure r passed as argument
//      (a) compute the area of r
//      (b) compute the center of r, returning it as a point structure.
//      (c) more r by x units in the x direction and y units in the y direction,
//          return a modified version of r.
//      (d) determine if a point p lies within r.
//
// 11.  Suppose the s is the following structure:
//      struct {
//          double a;
//          union {
//              char b[4];
//              double c;
//              int d;
//          } e;
//          char f[4];
//      } s;
//
//      if char values occupy one byte, int values four bytes and double eight
//      bytes, how much space will the compiler allocate for s?
//
// 12.  Suppose that u is the following union:
//      union {
//          double a;
//          struct {
//              char b[4];
//              double c;
//              int d;
//          } e;
//          char f[4];
//      } u;
//
//      how much space will the compiler allocate for u?
//
// 13.  suppose that s is the following structure (point is the structure
//      declared in exercise 10)
//
//      struct shape {
//          int shape_kind; // rectangle or circle
//          struct point center;    // coordinates of center
//          union {
//              struct {
//                  int height, width;
//              } rectangle;
//              struct {
//                  int radius;
//              } circle;
//          } u;
//      } s;
//
//      indicate which of the following statements are legal and correct the
//      ones that aren't
//      (a) s.shape_kind = RECTANGLE;
//      (b) s.center.x = 10;
//      (c) s.height = 25;
//      (d) s.u.rectangle.width = 8;
//      (e) s.u.circle = 5;
//      (f) s.u.radius = 5;
//
// 14.  Let shape be the structure tag declared in exercise 13. Write functions
//      that perform the following operations on a shape structure s pass as arg
//      (a) compute the area of s
//      (b) move s by x units in the x direction and y units in the y direction
//          returning a modified version of s
//      (c) scale s by a factor of double c. return a modified version of s
//
// 15.  (a) declare a tag for an enumeration whose values represent the seven
//          days of the week.
//      (b) use typedef to degine a name for the enum in part a
// 
// 16.  which of the following statements about enumeration constants are true?
//      (a) an enumeration constant may represent any integer specified by the
//          programmer.
//      (b) enumeration constants have exactly the same properties as constants
//          created using #define.
//      (c) enumeration constants have the values 0, 1, 2... by default.
//      (d) all constants in an enumeration must have different values
//      (e) enumeration constants may be used as integers in expressions
//
// 17.  suppose that b and i are declared as follows:
//      enum { FALSE, TRUE } b;
//      int i;
//
//      which of the following statelemts are legal? which ones are 'safe'?
//      (always yields a meaningful result)
//      (a) b = FALSE;
//      (b) b = i;
//      (c) b++;
//      (d) i = b;
//      (e) i = 2 * b + 1;
//
// 18.  (a) Each square of a chessboard can hold one piece, a pawn
