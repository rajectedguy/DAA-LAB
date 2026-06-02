#include <stdio.h>

#define V 5

int graph[V][V] = {
    {0,1,0,1,1},
    {1,0,1,1,0},
    {0,1,0,0,1},
    {1,1,0,0,1},
    {1,0,1,1,0}
};

int path[V];

int isSafe(int v, int pos)
{
    if(graph[path[pos - 1]][v] == 0)
        return 0;

    for(int i = 0; i < pos; i++)
    {
        if(path[i] == v)
            return 0;
    }

    return 1;
}

int hamCycleUtil(int pos)
{
    if(pos == V)
    {
        if(graph[path[pos - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }

    for(int v = 1; v < V; v++)
    {
        if(isSafe(v, pos))
        {
            path[pos] = v;

            if(hamCycleUtil(pos + 1))
                return 1;

            path[pos] = -1;
        }
    }

    return 0;
}

void printSolution()
{
    printf("Hamiltonian Cycle:\n");

    for(int i = 0; i < V; i++)
        printf("%d ", path[i]);

    printf("%d\n", path[0]);
}

int main()
{
    path[0] = 0;

    for(int i = 1; i < V; i++)
        path[i] = -1;

    if(hamCycleUtil(1))
        printSolution();
    else
        printf("No Hamiltonian Cycle exists\n");

    return 0;
}