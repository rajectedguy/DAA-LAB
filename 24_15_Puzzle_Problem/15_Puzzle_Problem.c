#include <stdio.h>
#include <stdlib.h>

#define N 4

int goal[N][N] =
{
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,0}
};

void printBoard(int board[N][N])
{
    int i,j;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(board[i][j]==0)
                printf(" _ ");
            else
                printf("%2d ",board[i][j]);
        }
        printf("\n");
    }
}

int manhattanDistance(int board[N][N])
{
    int i,j,value;
    int distance = 0;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            value = board[i][j];

            if(value != 0)
            {
                int targetRow = (value-1)/N;
                int targetCol = (value-1)%N;

                distance += abs(i-targetRow)
                          + abs(j-targetCol);
            }
        }
    }

    return distance;
}

int isGoal(int board[N][N])
{
    int i,j;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(board[i][j] != goal[i][j])
                return 0;
        }
    }

    return 1;
}

void findBlank(int board[N][N], int *x, int *y)
{
    int i,j;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(board[i][j]==0)
            {
                *x=i;
                *y=j;
                return;
            }
        }
    }
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int board[N][N] =
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,0,15}
    };

    printf("Initial State:\n");
    printBoard(board);

    printf("\nManhattan Distance = %d\n",
           manhattanDistance(board));

    if(isGoal(board))
        printf("Goal State Reached\n");
    else
        printf("Goal State Not Reached\n");

    int x,y;

    findBlank(board,&x,&y);

    if(y < N-1)
    {
        swap(&board[x][y], &board[x][y+1]);

        printf("\nAfter One Move:\n");
        printBoard(board);

        if(isGoal(board))
            printf("\nGoal State Reached\n");
    }

    return 0;
}