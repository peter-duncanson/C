#include "stack.h"
#include <stdio.h>

// void reverse_read(void);
void print_stack(StackEntry x);

int main(void)
{
    Stack *stack = NULL;
    stack_create(stack);
    stack_push(1, stack);
    stack_push(2, stack);
    stack_traverse(stack, print_stack);

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
