#include <stdio.h>
#include <stdbool.h>

#define N 8

bool knight_tour(int x, int y, int step, int board[N][N]);

int board[N][N] = { 0 };
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main(void)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = -1;

    board[0][0] = 0;

    knight_tour(0, 0, 1, board);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("  %2d", board[i][j]);
        }
        puts("");
    }

    return 0;
}

bool knight_tour(int x, int y, int step, int board[N][N])
{
    if (step == N * N)
        return true;

     int move_x, move_y;
    
    // 8 possible position changes for x and y
    for (int i = 0; i < 8; i++)
    {
        move_x = x + dx[i];
        move_y = y + dy[i];

        if (move_x >= 0 && move_y >= 0 && x < N && y < N && board[move_x][move_y] == -1)
        {
            board[move_x][move_y] = step;

            if (knight_tour(move_x, move_y, step + 1, board))
                return true;

            board[move_x][move_y] = -1;
        }
    }

    return false;
}
