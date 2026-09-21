#include <stdio.h>

int main(void)
{
    const char *a = "a1";
    const char *b = "b2";

    short dx = *b - *a;
    short dy = *++b - *++a;

    printf("dx = %d\ndy = %d\n", dx, dy);

    return 0;
}
