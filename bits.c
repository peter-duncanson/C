#include <stdio.h>
#include <stdint.h>

int main(void)
{
    // int8_t a = 0x27;
    // int8_t b = a << 4;
    int8_t a = 0x2F;
    int8_t b = a >> 3;

    printf("%X\n", b);

    return 0;
}
