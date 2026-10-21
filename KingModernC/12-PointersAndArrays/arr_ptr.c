#include <stdio.h>

#define SIZE 5

void fill_array(int *a, int n);
void print_array(int *a, int n);

int main(void)
{
    int a[SIZE];
    int b[SIZE][SIZE];

    fill_array(a, SIZE);
    print_array(a, SIZE);

    fill_array(b[0], SIZE * SIZE);
    print_array(b[0], SIZE * SIZE);

    return 0;
}

void fill_array(int *a, int n)
{
    int i = 0;

    for (int *p = a; p < a + n; p++)
        *p = i++;
}

void print_array(int *a, int n)
{
    for (int *p = a; p < a + n; p++)
        printf("%2d ", *p);
    puts("");
}
