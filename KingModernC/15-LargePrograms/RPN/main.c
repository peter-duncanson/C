/* =============================================================================
 *
 * Reverse Polish Notation Calculator - Using a Stack
 * main.c - Entry point
 * 
 * ========================================================================== */
#include "stack.h"

extern Stack stack;

int main(void)
{
    stack.top = 0;

    printf("top: %d\n", stack.top);
    return 0;
}
