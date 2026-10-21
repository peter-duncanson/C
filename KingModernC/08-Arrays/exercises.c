// Chapter 8 Exercises

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// =============================================================================
// (1) We discussed using the expression sizeof(a) / sizeof(a[0]) to calculate
// the number of elements in an array. The expression sizeof(a) / sizeof(t) 
// where t is the type of a's elements would also work, but it's considered an 
// inferior technique, why?
// -> Size of types is architecture dependent, so strictly using the variable's
// type with sizeof could have different results on different machines, which 
// makes the program less portable.
// =============================================================================

// =============================================================================
// (2) The Q&A section shows how to use a *letter* as an array subscript.
// Describe how to use a *digit* in character form as a subscript
// -> According to the ASCII character set, the digits 1-9 are encoded as 48-57
// with 48 being '0' and 57 being '9'. In order to use these *digits* as array 
// subscripts, we would have to scale all of them down by 48; like 
// array['0' - 48] will be the integer zero.
// =============================================================================

// =============================================================================
// (3) Write a declaration of an array named <weekend> containing seven <bool> 
// values. Include an initializer that makes the first and last values *true*;
// all other values should be *false*.
// -> bool weekend[7] = { true, false, false, false, false, false, true };
// =============================================================================

// =============================================================================
// (4) Repeat exercise 3, but this time use a designated initializer. Make the
// initializer as short as possible.
// -> bool weekend[7] = { true, false, [6] = true };
// =============================================================================

// =============================================================================
// (5) The Fibonacci numbers are 0, 1, 1, 2, 3, 5, 8, 13, ..., where each number
// is the sum of the two preceding numbers. Write a program fragment that
// declares an array named <fib_numbers> of length 40 and fills the array with
// the first 40 Fibonacci numbers.
int *fib(void) {
    static int fib_numbers[40] = { 0, 1 };
    int N = sizeof(fib_numbers) / sizeof(fib_numbers[0]);
    int *i = fib_numbers;
    int *j = fib_numbers + 1;

    for (int n = 2; n < N; n++) {
        fib_numbers[n] = *i + *j;
        i++;
        j++;
    }
    return fib_numbers;
}
// =============================================================================

// =============================================================================
// (6) Calculators, watches, and other electronic devices often rely on
// seven-segment displays for numerical output. To form a digit, such devices
// 'turn on' some of the seven segments while leaving others 'off'.
// Suppose we want to set up an array that remembers which segments should be
// 'on' for each digit. We number the segments as:
//  0
// 5 1
//  6
// 4 2
//  3
const int segments[10][7] = {
//    0  1  2  3  4  5  6
    { 1, 1, 1, 1, 1, 1, 0 }, // 0
    { 0, 1, 1, 0, 0, 0, 0 }, // 1
    { 1, 1, 0, 1, 1, 0, 1 }, // 2
    { 1, 1, 1, 1, 0, 0, 1 }, // 3
    { 0, 1, 1, 0, 0, 1, 1 }, // 4
    { 1, 0, 1, 1, 0, 1, 1 }, // 5
    { 1, 0, 1, 1, 1, 1, 1 }, // 6
    { 1, 1, 1, 0, 0, 0, 0 }, // 7
    { 1, 1, 1, 1, 1, 1, 1 }, // 8
    { 1, 1, 1, 1, 0, 1, 1 }, // 9
};
// =============================================================================

// =============================================================================
// (7) Using the shortcuts described in Section 8.2, shrink the initializer for
// the <segments> array as much as you can.
// (((This is annoying and seems dangerous)))
const int segments_short[10][7] = {
    { [0] = 1, [1] = 1, [2] = 1, [3] = 1, [4] = 1, [5] = 1 },           // 0
    { [1] = 1, [2] = 1 },                                               // 1
    { [0] = 1, [1] = 1, [3] = 1, [4] = 1, [6] = 1 },                    // 2
    { [0] = 1, [1] = 1, [2] = 1, [3] = 1, [6] = 1 },                    // 3
    { [1] = 1, [2] = 1, [5] = 1, [6] = 1 },                             // 4
    { [0] = 1, [2] = 1, [3] = 1, [5] = 1, [6] = 1 },                    // 5
    { [0] = 1, [2] = 1, [3] = 1, [4] = 1, [5] = 1, [6] = 1 },           // 6
    { [0] = 1, [1] = 1, [2] = 1 },                                      // 7
    { [0] = 1, [1] = 1, [2] = 1, [3] = 1, [4] = 1, [5] = 1, [6] = 1 },  // 8
    { [0] = 1, [1] = 1, [2] = 1, [3] = 1, [5] = 1, [6] = 1 }            // 9
};
// =============================================================================

// =============================================================================
// (8) Write a declaration of a two-dimentional array named
// <temperature-readings> that stores one month of hourly temperature readings.
// For simplicity, assume that a month has 30 days. The rows of the array should
// represent days of the month, the columns should represent hours of the day.
#define DAYS 30
#define HOURS 24

float temperature_readings[DAYS][HOURS] = { { 0 } };
// =============================================================================

// =============================================================================
// (9) Using the array of Exersise 8, write a program fragment that computes the
// average temperature for a month.
float average_temp(float temperatures[DAYS][HOURS]) {

    float sum;

    // fill the array with values, normally the array would already be full
    // and there would be no reason to loop twice, once to fill then once to
    // sum it all up.
    srand((unsigned) time(NULL));
    for (int day = 0; day < DAYS; day++) {
        for (int hour = 0; hour < HOURS; hour++) {
            // some random temperature between 0 and 100
            // We are in New England after all...
            temperatures[day][hour] = (float) (rand() % 100);
        }
    }

    // go back and sum all the elements, pretending we didnt just access all
    // of them
    for (int day = 0; day < DAYS; day++) {
        for (int hour = 0; hour < HOURS; hour++) {
            sum += temperatures[day][hour];
        }
    }

    return sum / ((float) DAYS * HOURS); 
}
// =============================================================================

// =============================================================================
// (10) Write a declaration for an 8x8 <char> array named <chess_board>. Include
// an initializer that puts the following data into the array.
// r n b q k b n r
// p p p p p p p p
//   .   .   .   .
// .   .   .   .  
//   .   .   .   .
// .   .   .   .
// P P P P P P P P
// R N B Q K B N R
char chess_board[8][8] = {
    { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
    { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
    { ' ', '.', ' ', '.', ' ', '.', ' ', '.' },
    { '.', ' ', '.', ' ', '.', ' ', '.', ' ' },
    { ' ', '.', ' ', '.', ' ', '.', ' ', '.' },
    { '.', ' ', '.', ' ', '.', ' ', '.', ' ' },
    { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
    { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' },
};
// =============================================================================

// =============================================================================
// (11) Write a program fragment that declares an 8x8 <char> array named
// <checker_board> and then uses a loop to store the following data into the
// array.
// B R B R B R B R
// R B R B R B R B
// B R B R B R B R
// R B R B R B R B
// B R B R B R B R
// R B R B R B R B
// B R B R B R B R
// R B R B R B R B

char checker_board[8][8];

void fill_checker_board(char board[8][8]) {

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            switch ((col + row) % 2) {
                case 0:
                    board[row][col] = 'B';
                    break;
                case 1:
                    board[row][col] = 'R';
                    break;
            };
        }
    }
}
// =============================================================================

int main(void) {

    return 0;
}
