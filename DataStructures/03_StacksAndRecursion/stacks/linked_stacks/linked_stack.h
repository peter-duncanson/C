#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAXSTACK 10

typedef int StackItem;

typedef struct node
{
    StackItem value;
    int count;
    struct node *prev;
} Node;

Node *stack_create(StackItem item);
Node *stack_clear(Node *top);
bool stack_empty(Node *top);
bool stack_full(Node *top);
StackItem stack_pop(Node *top);
StackItem stack_peek(Node *top);
Node *stack_push(Node *top, StackItem item);
void stack_print(Node *top);
void stack_traverse(Node *top, StackItem (*operation)(StackItem));
