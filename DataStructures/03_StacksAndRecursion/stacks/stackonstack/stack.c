#include "stack.h"
// ================================================================================================
// stack_create:    Creates a new stack.
// Pre:             Pointer to a stack is initialized.
// Post:            The stack s has been created and is initialized to be empty.
// ================================================================================================
void stack_create(Stack *s)
{
    s->top = -1;
}

// ================================================================================================
// stack_empty:     Checks if an existing stack is empty.
// Pre:             The stack exists and has been initialized.
// Post:            Returns true is the stack is empty, otherwise false.
// ================================================================================================
bool stack_empty(Stack *s)
{
    return s->top <= 0;
}

// ================================================================================================
// stack_full:      Checks if an existing stack is full.
// Pre:             The stack exists and has been initialized.
// Post:            Returns true is the stack is full, otherwise false.
// ================================================================================================
bool stack_full(Stack *s)
{
    return s->top >= MAXSTACK;
}

// ================================================================================================
// stack_size:      Check the size of a stack.
// Pre:             The stack exists and has been initialized.
// Post:            The size of the stack is returned to the caller as an integer.
// ================================================================================================
int stack_size(Stack *s)
{
    return s->top + 1;
}

// ================================================================================================
// stack_clear:     Clears a stack of all contents.
// Pre:             The stack exists and has been initialized.
// Post:            All entries in the stack have been deleted, the stack is empty.
// ================================================================================================
void stack_clear(Stack *s)
{
    s->top = 0;
}

// ================================================================================================
// stack_top:       Returns the item at the top of the stack.
// Pre:             The stacks exists and is not empty.
// Post:            The item is set to point to the item at the top of the stack, stack remains
//                  unchanged.
// ================================================================================================
// TODO
// void stack_top(StackEntry *item, Stack *s)
// {
//     item = s->entry[s->top];
// }

// ================================================================================================
// stack_push:      Push an item onto the stack.
// Pre:             The stacks exists and is not full.
// Post:            The argument item has been stored at the top of the stack.
// ================================================================================================
void stack_push(StackEntry item, Stack *s)
{
    // if (stack_full(s)) Error("Stack is full.");
    s->entry[++s->top] = item;
}

// ================================================================================================
// stack_pop:       Removes the item at the top of the stack.
// Pre:             The stacks exists and is not empty.
// Post:            The top of the stack has been removed and item now points to its value.
// ================================================================================================
void stack_pop(StackEntry *item, Stack *s)
{
    // if (stack_empty(s)) Error("Stack is empty");
    *item = s->entry[--s->top];
}

// ================================================================================================
// stack_traverse:  Traverses a stack.
// Pre:             The stacks exists and it has been initialized.
// Post:            The function that visit points to has been invoked for each entry in the stack,
//                  beginning with the entry at the top and proceeding to the bottom of the stack.
// ================================================================================================
void stack_traverse(Stack *s, void(*Visit)(StackEntry))
{
    for (int i = 0; i <= s->top; i++) (*Visit)(s->entry[i]);
}

