#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

int parent[100];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int u, int v) {
    int uroot = find(u);
    int vroot = find(v);
    parent[uroot] = vroot;
}

void sortEdges(struct Edge edges[], int e) {
    int i, j;
    struct Edge temp;

    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void kruskal(struct Edge edges[], int v, int e) {
    int i;
    int count = 0;
    int minCost = 0;

    for (i = 0; i < v; i++)
        parent[i] = i;

    sortEdges(edges, e);

    printf("Edges in MST:\n");

    for (i = 0; i < e && count < v - 1; i++) {
        int u = edges[i].src;
        int vtx = edges[i].dest;

        int setU = find(u);
        int setV = find(vtx);

        if (setU != setV) {
            printf("%d -- %d == %d\n", u, vtx, edges[i].weight);
            minCost += edges[i].weight;
            unionSet(setU, setV);
            count++;
        }
    }

    printf("Minimum Cost = %d\n", minCost);
}

int main() {
    int v = 4;
    int e = 5;

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges, v, e);

    return 0;
}