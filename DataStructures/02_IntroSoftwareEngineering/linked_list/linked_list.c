#include "linked_list.h"
#include "common.h"

List *list_create(void)
{
    List *p = malloc(sizeof(List));
    if (p == NULL)
    {
        puts("malloc returned null pointer, aborting.");
        exit(1);
    }
    p->value = 0;
    p->next = NULL;
    return p;
}

void list_add(List *list, ListEntry new_value)
{
    List *new = malloc(sizeof(List));
    if (new == NULL)
    {
        puts("malloc returned null pointer, aborting.");
        exit(1);
    }
    if (list->count > MAXLIST)
    {
        puts("List is full");
        exit(1);
    }
    new->value = new_value;
    new->next = NULL;
    p->next = new;
}

void list_clear(List *list)
{
    while (list->next != NULL)
    {
        
    }
}
