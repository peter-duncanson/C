#include <stdio.h>

#define DISKS 64

void move(int count, int source, int target, int spare);

int main(void)
{
    move(3, 1, 3, 2);
    return 0;
}

void move(int count, int source, int target, int spare)
{
    if (count > 0)
    {
        move(count - 1, source, spare, target);
        printf("Move a disk from %d to %d\n", source, target);
        move(count - 1, spare, target, source);
    }
}
