#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000
#define MAX_EDGES (MAX_VERTICES * (MAX_VERTICES - 1) / 2)

struct Edge
{
    int u, v, weight;
};

int num_vertices, num_edges;
struct Edge edges[MAX_EDGES];
int parent[MAX_VERTICES];

void make_set(int x)
{
    parent[x] = x;
}

int find_set(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find_set(parent[x]);
    }
    return parent[x];
}

void union_sets(int x, int y)
{
    int root_x = find_set(x);
    int root_y = find_set(y);
    parent[root_x] = root_y;
}

void bubble_sort(struct Edge arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].weight > arr[j + 1].weight)
            {
                struct Edge temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void kruskal()
{
    int min_weight = 0;
    for (int i = 0; i < num_vertices; i++)
    {
        make_set(i);
    }
    bubble_sort(edges, num_edges);
    for (int i = 0; i < num_edges; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find_set(u) != find_set(v))
        {
            union_sets(u, v);
            min_weight += edges[i].weight;
        }
    }
    printf("Minimum spanning tree weight: %d\n", min_weight);
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    printf("Enter the edges in the format (source destination weight):\n");
    for (int i = 0; i < num_edges; i++)
    {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    kruskal();
    return 0;
}