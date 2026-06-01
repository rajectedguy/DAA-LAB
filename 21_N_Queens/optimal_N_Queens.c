#include <stdio.h>

#define N 8

int board[N][N];
int col[N];
int diag1[2 * N - 1];
int diag2[2 * N - 1];

int solve(int row)
{
    if(row == N)
        return 1;

    for(int c = 0; c < N; c++)
    {
        if(!col[c] &&
           !diag1[row - c + N - 1] &&
           !diag2[row + c])
        {
            board[row][c] = 1;
            col[c] = 1;
            diag1[row - c + N - 1] = 1;
            diag2[row + c] = 1;

            if(solve(row + 1))
                return 1;

            board[row][c] = 0;
            col[c] = 0;
            diag1[row - c + N - 1] = 0;
            diag2[row + c] = 0;
        }
    }

    return 0;
}

void printBoard()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int main()
{
    if(solve(0))
    {
        printf("Solution Exists:\n");
        printBoard();
    }
    else
    {
        printf("No Solution Exists\n");
    }

    return 0;
}