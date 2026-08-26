#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAXSTACK 1000

typedef struct
{
    float *data;
    int size;
    int top;
} FloatStack;

typedef struct
{
    int *data;
    int size;
    int top;
} IntStack;

typedef struct
{
    char *data;
    int size;
    int top;
} CharStack;

void *stack_create(void *stack, int size);
void stack_destroy(void *stack);
bool stack_full(void *stack);
bool stack_empty(void *stack);
void pop(void *stack, void *item);
void push(void *stack, void *item);
void peek(void *stack, void *item);
void stack_print(void *stack);
