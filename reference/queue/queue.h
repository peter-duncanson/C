#include <stdbool.h>

typedef struct node
{
    short x;
    short y;
    short step;
    bool visited;
} boardSquare;

void *pop(void *tip);
void push(void *tail, );
