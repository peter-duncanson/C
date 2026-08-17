// #include "common.h"
// #include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int value;
    struct node *next;
};

struct node *new_node(int value, struct node *p);

int main(int argc, char **argv)
{
    struct node *new, *first, *p;

    first = malloc(sizeof(struct node));
    first->next = NULL;
    first->value = 1;

    new = malloc(sizeof(struct node));
    first->next = new;
    new->next = NULL;
    new->value = 2;
    p = new;

    new = malloc(sizeof(struct node));
    p->next = new;
    new->next = NULL;
    new->value = 3;
    p = new;

    p = new_node(4, p);

    for (p = first; p != NULL; p = p->next)
    {
        printf("%d\n", p->value);
    }

    return 0;
}

// pass in a new value and a pointer to the end of the list
struct node *new_node(int x, int position, struct node *p)
{
    struct node *new = malloc(sizeof(struct node));

    p->next = new;
    new->next = NULL;
    new->value = x;
    return new;
}
