#include <stdio.h>
#include "mazes.c"

void solve_maze(int size, int maze[][size]);

int main(void)
{
    solve_maze(10, maze_a);

    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         printf("  %d", maze_z[i][j]);
    //     }
    //     puts("");
    // }

    
    return 0;
}

void solve_maze(int size, int maze[][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf(" %2d", maze[i][j]);
        }
        puts("");
    }
    return;
}
