#include "cont_stack.h"

Stack *stack_create(size_t capacity, size_t size)
{
    Stack *s = malloc(sizeof(Stack));
    if (s == NULL)
    {
        puts("malloc returned null pointer in function stack_create. Aborting.");
        exit(1);
    }

    s->size = size;
    s->capacity = capacity;
    s->top = 0;

    // TODO: check for overflow
    s->data = malloc(s->capacity * s->size);
    if (s->data == NULL)
    {
        free(s);
        puts("malloc returned null pointer in function stack_create. Aborting.");
        exit(1);
    }

    return s;
}

void stack_destroy(Stack *s)
{
    free(s->data);
    free(s);
}

bool stack_full(Stack *s)
{
    return (s->top == s->capacity);
}

bool stack_empty(Stack *s)
{
    return (s->top == 0);
}

void pop(Stack *s, void *item)
{
    if (stack_empty(s))
    {
        puts("Attempt to pop from an empty stack.");
        return;
    }

    s->top--;
    memcpy(item, (char *)s->data + s->top * s->size, s->size);
}

void push(Stack *s, void *item)
{
    if (stack_full(s))
    {
        puts("Attempt to push to a full stack.");
        return;
    }

    memcpy((char *)s->data + s->top * s->size, item, s->size);
    s->top++;
}

void peek(Stack *s, void *item)
{
    if (stack_empty(s))
    {
        puts("Attempt to peek at an empty stack.");
        return;
    }

    memcpy(item, (char *)s->data + (s->top - 1) * s->size, s->size);
}

void stack_print(Stack *s)
{
    for (int i = s->top - 1; i >= 0; i--)
    {
        unsigned long *p = &s->data[i];
        printf("%ld\n", *p);
    }
}
