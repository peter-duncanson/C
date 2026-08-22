#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int *collection;
    int capacity;
    int size;
} Stack;

Stack *create_stack(int capacity);
void destroy_stack(Stack *stack);
void print_stack(Stack *stack);
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
bool pop(Stack *stack, int *item);
bool push(Stack *stack, int item);
bool peek(Stack *stack, int *item);

int main(void)
{
    Stack *stack = create_stack(30);

    for (int i = 0; i < stack->capacity; i++)
    {
        push(stack, i);
    }

    print_stack(stack);
    destroy_stack(stack);
    
    return 0;
}

Stack *create_stack(int capacity)
{
    if (capacity <= 0) return NULL;

    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL) return NULL;

    stack->collection = malloc(sizeof(int) * capacity);
    if (stack->collection == NULL)
    {
        free(stack);
        return NULL;
    }
    stack->capacity = capacity;
    stack->size = 0;

    return stack;
}

void destroy_stack(Stack *stack)
{
    free(stack->collection);
    free(stack);
}

void print_stack(Stack *stack)
{
    for (int *p = stack->collection; p != stack->collection + stack->size; p++)
        printf("Value: %d\n", *p);
}

bool is_full(Stack *stack)
{
    return stack->size == stack->capacity;
}

bool is_empty(Stack *stack)
{
    return stack->size == 0;
}

bool pop(Stack *stack, int *item)
{
    if (is_empty(stack)) return false;

    stack->size--;

    *item = stack->collection[stack->size];

    return true;
}

bool push(Stack *stack, int item)
{
    if (is_full(stack)) return false;

    stack->collection[stack->size++] = item;

    // stack->size++;

    return true;
}

bool peek(Stack *stack, int *item)
{
    if (is_empty(stack)) return false;

    *item = stack->collection[stack->size - 1];

    return true;
}
