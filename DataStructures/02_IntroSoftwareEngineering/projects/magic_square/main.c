#include <stdio.h>
#include "magic_square.h"

int magic_square[4][4] = { { 16, 3, 2, 13  },
                             {  5, 10, 11, 8 },
                             {  9, 6, 7, 12  },
                             { 4, 15, 14, 1  }, };


int main(void)
{

    if (is_magic(4, magic_square)) printf("MAGIC!\n");
    else printf("NOT MAGIC!\n");


    return 0;
}
