#include <stdio.h>

void reverse_digits() {
    int i;
    printf("Enter a three-digit number: ");
    scanf("%d", &i);
    printf("The reversal is: %d%d%d\n", i % 10, (i % 100) / 10, i / 100);
}

void reverse_no_math() {
    int i, j, k;
    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d", &i, &j, &k);
    printf("%d%d%d\n", k, j, i);
}

void octal() {
    int i;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &i); 
    printf("%.5o\n", i);
}
