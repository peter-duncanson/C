#include "stack.h"
#include <stdio.h>

// void reverse_read(void);
void print_stack(StackEntry x);
void add_one(StackEntry x);

int main(void)
{
    Stack *s;
    stack_create(s);
    stack_push(1, s);
    stack_push(2, s);
    printf("value at top index should be 2: %d\n", s->entry[s->top]);
    printf("top: %d\n", s->top);
    stack_traverse(s, add_one);

    for (int i = 0; i <= s->top; i++)
    {
        printf("i = %d\n", s->entry[i]);
    }

    return 0;

}

// reverse_read:    Read one line of input and write it backwards.
// Pre:             The user supplies one line of input.
// Post:            The line has been printed backward, using a stack.
// void reverse_read(void)
// {
//
// }

void print_stack(StackEntry x)
{
    printf("%c\n", x);
}

void add_one(StackEntry x)
{
    x += 1;
}
