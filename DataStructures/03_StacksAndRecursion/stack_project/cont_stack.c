#include "cont_stack.h"

void *stack_create(void *stack, int size)
{
    stack = malloc(sizeof(*stack));
    if (stack == NULL) exit(1);

    stack->size = size;
    stack->top = 0;

    stack->data = malloc(sizeof(*(stack->data)));
    if (stack->data == NULL)
    {
        free(stack);
        exit(1);
    }

    return stack;
}

void stack_destroy(void *stack)
{
    free(stack->data);
    free(stack);
}

bool stack_full(void *stack)
{
    return stack->top == stack->size;
}

bool stack_empty(void *stack)
{
    return stack->top == 0;
}

void pop(void *stack, void *item)
{
    *item = stack->data[stack->top--];
}

void push(void *stack, void *item)
{
    stack->data[++stack->top] = *item;
}

void peek(void *stack, void *item)
{
    *item = stack->data[stack->top];
}

void stack_print(void *stack)
{
    for (int i = stack->top - 1; i >= 0; i--)
        printf("%ld\n", stack->data[i]);
}
