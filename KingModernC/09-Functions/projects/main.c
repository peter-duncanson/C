//==============================================================================
// C Programming: A Modern Approach - K.N. King
// Chapter 9 Projects - Functions
// 07/09/26
//==============================================================================
#include <stdio.h>
#include "functions.h"

int main(void)
{
    // // Project 1
    // int n = 0;
    // int a[1000];
    //
    // printf("Enter a series of integers to be sorted: ");
    // do 
    // {
    //     scanf("%d", &a[n++]);
    // }
    // while (getchar() != '\n' && n < 100);
    //
    // selection_sort(a, n);
    // for (int i = 0; i < n; i++) printf("%d ", a[i]);
    // puts("");

    // // Project 2
    // float income;
    // printf("Enter your income: ");
    // scanf("%f", &income);
    // printf("Your income tax is: %.2f\n", compute_tax(income));

    // // Project 3
    // char a[10][10];
    // generate_random_walk(a);
    // print_array(a);

    // // Project 4
    // int first[26] = { 0 };
    // int second[26] = { 0 };
    // printf("Enter two words\n");
    // read_word(first);
    // read_word(second);
    // if (equal_array(first, second)) printf("Anagrams\n");
    // else printf("not anagrams\n");

    // // Project 5
    // int size;
    // printf("Enter size for magic square: ");
    // scanf("%d", &size);
    // int a[size][size];
    // create_magic_square(size, a);
    // print_magic_square(size, a);

    // // Project 6
    // int x = 10;
    // printf("%d\n", f(x));

    // Project 7
    int base, exponent;
    printf("Enter base exponent: ");
    scanf("%d %d", &base, &exponent);
    printf("%d\n", power(base, exponent));

    return 0;
}
