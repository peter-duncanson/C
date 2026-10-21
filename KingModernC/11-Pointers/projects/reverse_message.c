/*
Reverses a message that is input from a user
*/
#include <stdio.h>
#include <stdlib.h>

#define LEN 20

int main(void)
{
    char buffer[LEN];
    char c; 
    int i;

    while ((c = getchar()) != '\n') *(buffer + i++) = c;

    --i;

    while (i >= 0) printf("%c", *(buffer + i--));
   
    puts("");

    return 0;
}
