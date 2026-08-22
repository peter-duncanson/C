#include "linked_stack.h"

StackItem square(StackItem x);

int main(void)
{
    Node *top = stack_create(0);
    if (stack_empty(top)) puts("Stack is empty.");

    top = stack_push(top, 1);
    top = stack_push(top, 2);
    top = stack_push(top, 3);
    top = stack_push(top, 4);

    stack_print(top);

    stack_traverse(top, square);

    top = stack_clear(top);
    return 0;
}

StackItem square(StackItem x)
{
    return x * x;
}
