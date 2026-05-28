#include <stdio.h>

int queue[100];
int front = -1, rear = -1;

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
    int n = 6;

    int graph[6][6] = {
        {0,0,1,0,0,0},
        {0,0,1,1,0,0},
        {0,0,0,0,1,0},
        {0,0,0,0,1,1},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}
    };

    int indegree[6] = {0};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(graph[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
        {
            enqueue(i);
        }
    }

    printf("Topological Sorting: ");

    while(!isEmpty())
    {
        int u = dequeue();

        printf("%d ", u);

        for(int v = 0; v < n; v++)
        {
            if(graph[u][v] == 1)
            {
                indegree[v]--;

                if(indegree[v] == 0)
                {
                    enqueue(v);
                }
            }
        }
    }

    return 0;
}