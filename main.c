#include <stdio.h>
#include <string.h>

int *px = NULL;

void foo(void)
{
    printf("foo\n");
    // *px = 7;
}

int main(void)
{
    char *name = "peter";
    char *name2 = "duncanson";
    // ... ...
    

    // code that prints name
    printf("My name is %s\n", name);

    foo();

    name = name2;

    return 0;
}
