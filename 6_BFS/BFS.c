#include <stdio.h>

int queue[100], front = -1, rear = -1;

void enqueue(int x)
{
    if(front == -1)
        front = 0;

    queue[++rear] = x;
}

int dequeue()
{
    return queue[front++];
}

int isEmpty()
{
    if(front > rear)
        return 1;

    return 0;
}

int main()
{
    int graph[5][5] = {
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };

    int visited[5] = {0};

    int start = 0;

    visited[start] = 1;
    enqueue(start);

    printf("BFS Traversal: ");

    while(!isEmpty())
    {
        int u = dequeue();

        printf("%d ", u);

        for(int v = 0; v < 5; v++)
        {
            if(graph[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                enqueue(v);
            }
        }
    }

    return 0;
}