#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

// char (*perm(int index, int len, const char *s))[len];
void rp(int index, int len, const char *s);
char *swap(const char *s, char *swapped, size_t a, size_t b);
size_t factorial(size_t n);

char sol[100];

int main(void)
{
    const char *s = "ABC";
    const size_t n_permute = factorial(strlen(s));


    // rp(0, 3, "ABC");

    return 0;
}

// char (*perm(int index, int len, const char *s))[len]
// {
//     return;
// }

void rp(int index, int len, const char *s)
{
    if (index == len) return;

    for (int i = index; i < len; i++)
    {
        char *temp_swap = NULL;
        temp_swap = swap(s, temp_swap, i, index);

        rp(index + 1, len, temp_swap);
        
        if (index == len - 1) printf("%s\n", temp_swap);

        free(temp_swap);
    }
}

// swaps character at position a with position b
char *swap(const char *s, char *swapped, size_t a, size_t b)
{
    size_t len = strlen(s);
    if (a > len || b > len) 
    {
        puts("Attempt to swap chars out of array bounds, aborting.");
        exit(1);
    }

    swapped = malloc((len + 1) * sizeof(char));
    if (swapped == NULL)
    {
        puts("malloc for swap buffer failed, aborting.");
        exit(1);
    }

    strcpy(swapped, s);

    // return early if the swapped string is equivalent
    if (a == b) return swapped;

    char temp = swapped[a];
    swapped[a] = swapped[b];
    swapped[b] = temp;
    
    return swapped;
}

size_t factorial(size_t n)
{
    if (n <= 1) return n;
    else return n * factorial(n - 1);
}
