#include <stdio.h>

int parent[10];

void initialize(int n)
{
    for(int i = 0; i < n; i++)
    {
        parent[i] = -1;
    }
}

int simpleFind(int x)
{
    while(parent[x] >= 0)
    {
        x = parent[x];
    }

    return x;
}

void simpleUnion(int a, int b)
{
    int root1 = simpleFind(a);
    int root2 = simpleFind(b);

    if(root1 != root2)
    {
        parent[root2] = root1;
    }
}

void weightedUnion(int a, int b)
{
    int root1 = simpleFind(a);
    int root2 = simpleFind(b);

    if(root1 == root2)
    {
        return;
    }

    if(parent[root1] <= parent[root2])
    {
        parent[root1] += parent[root2];
        parent[root2] = root1;
    }
    else
    {
        parent[root2] += parent[root1];
        parent[root1] = root2;
    }
}

int collapsingFind(int x)
{
    int root = x;

    while(parent[root] >= 0)
    {
        root = parent[root];
    }

    while(x != root)
    {
        int temp = parent[x];
        parent[x] = root;
        x = temp;
    }

    return root;
}

void display(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", parent[i]);
    }

    printf("\n");
}

int main()
{
    int n = 7;

    initialize(n);

    weightedUnion(0, 1);
    weightedUnion(2, 3);
    weightedUnion(1, 2);
    weightedUnion(4, 5);

    printf("Parent Array:\n");

    display(n);

    printf("Find(3) = %d\n", collapsingFind(3));

    printf("After Collapsing Find:\n");

    display(n);

    return 0;
}