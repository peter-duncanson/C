#include <stdbool.h>

#define MAXSTACK 10

typedef char StackEntry;

typedef struct stack
{
    int top;
    StackEntry entry[MAXSTACK];
} Stack;

void stack_create(Stack *s);
bool stack_empty(Stack *s);
bool stack_full(Stack *s);
int stack_size(Stack *s);
void stack_clear(Stack *s);
void stack_top(StackEntry *item, Stack *s);
void stack_push(StackEntry item, Stack *s);
void stack_pop(StackEntry *item, Stack *s);
void stack_traverse(Stack *s, void(*Visit)(StackEntry));
void stack_top(StackEntry *item, Stack *s);
