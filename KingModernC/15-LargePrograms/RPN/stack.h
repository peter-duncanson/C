#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>

typedef struct stack {
    int contents[100];
    int top;
} Stack;

Stack stack;

void make_empty(Stack *s);
bool is_empty(Stack *s);
bool is_full(Stack *s);
void push(Stack *s, int i);
int pop(Stack *s);

#endif
