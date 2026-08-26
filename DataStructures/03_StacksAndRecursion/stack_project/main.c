// #include "linked_stack.h"
#include "cont_stack.h"

int main(void)
{
    FloatStack *fstack = stack_create(fstack, 10);
    float *a, *b, *c;
    float x = 1.5;
    a = &x;
    float y = 2.5;
    b = &y;
    float z = 3.5;
    c = &z;
    push(fstack, a);
    push(fstack, b);
    push(fstack, c);

    for (int i = fstack->top - 1; i >= 0; i--)
        printf("%f", fstack->data[i]);


    return 0;
}
