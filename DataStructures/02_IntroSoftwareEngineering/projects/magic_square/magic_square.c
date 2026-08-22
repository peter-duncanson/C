#include "magic_square.h"

// Project 1:
// A magic square is a square array of integers such that the sum of every row, the sum of every
// column, and sum of each of the two diagonals are all equal.
//
// (a) Write a program that reads a square array of integers and determines whether or not it is
// a magic square.

bool is_magic(int n, int array[][n])
{
    int i, j, row_sums[n], col_sums[n], dia_sums[2];

    for (i = 0; i < n; i++)
    {
        row_sums[i] = 0;
        col_sums[i] = 0;
    }
    dia_sums[0] = 0;
    dia_sums[1] = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            row_sums[i] += array[i][j];
            col_sums[i] += array[j][i];
            if (i == j) dia_sums[0] += array[i][j];
            else if (i + j == (n - 1)) dia_sums[1] += array[i][j];
        }
        if (i)
        {
            if (row_sums[i] != row_sums[i - 1] ||
                col_sums[i] != col_sums[i - 1] ||
                row_sums[i] != col_sums[i - 1] ||
                col_sums[i] != row_sums[i - 1]) return false;
        }
    }

    for (i = 0; i < n; i++)
    {
        if (dia_sums[0] != row_sums[i] || dia_sums[0] != row_sums[i]) return false;
        if (dia_sums[0] != col_sums[i] || dia_sums[0] != col_sums[i]) return false;
    }
    return true;

}
