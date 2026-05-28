#include <stdio.h>

int graph[5][5] = {
    {0,1,1,0,0},
    {1,0,1,1,0},
    {1,1,0,0,1},
    {0,1,0,0,1},
    {0,0,1,1,0}
};

int visited[5] = {0};

void DFS(int start)
{
    visited[start] = 1;

    printf("%d ", start);

    for(int v = 0; v < 5; v++)
    {
        if(graph[start][v] == 1 && visited[v] == 0)
        {
            DFS(v);
        }
    }
}

int main()
{
    printf("DFS Traversal: ");

    DFS(0);

    return 0;
}