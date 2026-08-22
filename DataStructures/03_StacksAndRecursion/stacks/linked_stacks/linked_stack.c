#include "linked_stack.h"

Node *stack_create(StackItem item)
{
    Node *new_stack = malloc(sizeof(Node));
    if (new_stack == NULL)
    {
        puts("malloc returned null in function stack_create. Aborting.");
        exit(1);
    }
    new_stack->prev = NULL;
    new_stack->count = 1;
    new_stack->value = item;

    return new_stack;
}

Node *stack_clear(Node *top)
{
    while (top != NULL)
    {
        Node *temp = top;
        top->count = 0;
        top = top->prev;
        free(temp);
    }
    puts("Stack cleared.");
    return NULL;
}

bool stack_empty(Node *top)
{
    return top->count <= 0;
}

bool stack_full(Node *top)
{
    return top->count >= MAXSTACK;
}

StackItem stack_pop(Node *top)
{
    if (stack_empty(top))
    {
        puts("Cannot pop item, stack is empty.");
        exit(1);
    }
    StackItem item = top->value;
    Node *temp = top;
    top->count--;
    top = top->prev;
    free(temp);
    
    return item;
}

StackItem stack_peek(Node *top)
{
    if (stack_empty(top))
    {
        puts("Cannot peek at empty stack.");
        exit(1);
    }
    return top->value;
}

Node *stack_push(Node *top, StackItem item)
{
    if (stack_full(top))
    {
        puts("Cannot push to a full stack.");
        return NULL;
    }
    else
    {
        Node *new_node = malloc(sizeof(Node));
        if (new_node == NULL)
        {
            puts("malloc returned null in function stack_push. Aborting.");
            exit(1);
        }
        Node *temp = top;
        top = new_node;
        top->prev = temp;
        top->count = temp->count += 1;
        top->value = item;
        return top;
    }
}

void stack_print(Node *top)
{
    for (Node *p = top; p != NULL; p = p->prev)
    {
        printf("Value: %d\n", p->value);
    }
}

void stack_traverse(Node *top, StackItem (*operation)(StackItem))
{
    for (Node *p = top; p != NULL; p = top->prev)
    {
        p->value = operation(p->value); 
    }
}
