#include "common.h"
#include "simplist.h"

// adds an element to the list
void list_add(ListEntry x, List *list)
{
    if (list_full(list))
        Warning("Attempt to insert into a full list.");
        // exit(1);
    else
        list->entry[list->count++] = x;
}

// traverses the list, and performs operation defined in function Visit to each entry
void list_traverse(List *list, void (*Visit)(ListEntry))
{
    int i;
    for (i = 0; i < list->count; i++)
        (*Visit)(list->entry[i]);
}

// creates an empty list, with a count of 0
void list_create(List *list)
{
    list->count = 0;
}

// clears a list by setting all of its elements to zero. Does not reset the count
void list_clear(List *list)
{
    for (int i = 0; i < list->count; i++)
        list->entry[i] = 0;
}

// returns true if the list is empty, else false
bool list_empty(const List *list)
{
    return (list->count == 0);
}

// returns true of the list is full, else false
bool list_full(const List *list)
{
    return (list->count == MAXLIST);
}

// returns the current size of the list
int list_size(const List *list)
{
    return list->count;
}

void list_copy(List *destination, const List *source)
{
    for (int i = 0; i < source->count; i++)
    {
        destination->entry[i] = source->entry[i];
        destination->count++;
    }
}
