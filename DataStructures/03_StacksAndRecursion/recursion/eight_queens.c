#include <stdio.h>
#include <stdbool.h>

#define BOARDSIZE 8
#define DIAGONAL (2 * BOARDSIZE - 1)
#define DOWNOFFSET (BOARDSIZE - 1)

void write_board(void);
void add_queen(void);

int queencol[BOARDSIZE];    // column with the queen
bool colfree[BOARDSIZE];    // is the column free
bool upfree[DIAGONAL];      // is the upward diagonal free
bool downfree[DIAGONAL];    // is the downward diagonal free
int queencount = -1;        // row whose queen is currently placed
int numsol = 0;             // number of solutions found so far

int main(void)
{
    int i;

    for (i = 0; i < BOARDSIZE; i++)
        colfree[i] = true;

    for (i = 0; i < DIAGONAL; i++)
    {
        upfree[i] = true;
        downfree[i] = true;
    }

    add_queen();
    printf("Solutions: %d\n", numsol);

    return 0;
}

void add_queen(void)
{
    int col;
    queencount++;

    for (col = 0; col < BOARDSIZE; col++)
    {
        if (colfree[col] && upfree[queencount + col] && downfree[queencount - col + DOWNOFFSET])
        {
            queencol[queencount] = col;
            colfree[col] = false;
            upfree[queencount + col] = false;
            downfree[queencount - col + DOWNOFFSET] = false;

            if (queencount == BOARDSIZE - 1) // termination condition
            {
                numsol++;
                write_board();
            }
            else
                add_queen();                // proceed recursively

            // now backtrack by removing the queen
            colfree[col] = true;
            upfree[queencount + col] = true;
            downfree[queencount - col + DOWNOFFSET] = true;
        }
    }
    queencount--;
}

void write_board(void)
{
    for (int i = 0; i < BOARDSIZE; i++)
    {
        printf("%d\t", queencol[i]);
    }
    puts("");
}
