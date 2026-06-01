#include <stdio.h>

#define V 4

int graph[V][V] = {
    {0,1,1,1},
    {1,0,1,0},
    {1,1,0,1},
    {1,0,1,0}
};

int m = 3;
int color[V];

int isSafe(int v, int c)
{
    for(int i = 0; i < V; i++)
    {
        if(graph[v][i] && color[i] == c)
            return 0;
    }
    return 1;
}

int graphColoring(int v)
{
    if(v == V)
        return 1;

    for(int c = 1; c <= m; c++)
    {
        if(isSafe(v, c))
        {
            color[v] = c;

            if(graphColoring(v + 1))
                return 1;

            color[v] = 0;
        }
    }

    return 0;
}

int main()
{
    if(graphColoring(0))
    {
        printf("Solution Exists:\n");
        for(int i = 0; i < V; i++)
            printf("Vertex %d ---> Color %d\n", i, color[i]);
    }
    else
    {
        printf("No Solution Exists");
    }

    return 0;
}