#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#define MAXSTACK 1000

typedef struct
{
    void *data;         // heap allocated array to store stack contiguously
    size_t size;        // size in bytes of each data element 
    size_t capacity;    // store a stack capacity
    size_t top;         // store the index of the current top of the stack
} Stack;

Stack *stack_create(size_t capacity, size_t size);
void stack_destroy(Stack *s);
bool stack_full(Stack *s);
bool stack_empty(Stack *s);
void pop(Stack *s, void *item);
void push(Stack *s, void *item);
void peek(Stack *s, void *item);
void stack_print(Stack *s);
