#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

char **driver(size_t len, size_t amount);
char *worker(size_t len);

int main(void)
{
    // const char *a = "a1";
    // const char *b = "b2";
    //
    // short dx = *b - *a;
    // short dy = *++b - *++a;

    // printf("dx = %d\ndy = %d\n", dx, dy);
    char **a = driver(3, 10);
    // for (int *i = 0; i < 10; i++)
    //     printf("%s\n", a[i]);
    printf("%X", &a);
    return 0;
}

char **driver(size_t len, size_t amount)
{
    char **results = malloc(sizeof(const char *) * amount);
    for (size_t i = 0; i < amount; i++) 
        results[i] = worker(len);
    return results;
}

char *worker(size_t len)
{
    char *word = malloc(len + 1);

    for (char c = 'a'; c < 'a' + len; c++)
        *word++ = c;
    *word = '\0';
    return word;
}
