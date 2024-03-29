#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *next;
    int vertex;
} node;
node *G[20];
// heads of linked list
int visited[20];
intn;
void read_graph();
// create adjacency list
void insert(int, int);
// insert an edge (vi,vj) in te adjacency list
void DFS(int);
void main()
{
    int i;
    read_graph();
    // initialised visited to 0

    for (i = 0; i < n; i++)
        visited[i] = 0;
    DFS(0);
}
void DFS(int i)
{
    node *p;
    printf("\n%d", i);
    p = G[i];
    visited[i] = 1;
    while (p != NULL)
    {
        i = p->vertex;
        if (!visited[i])
            DFS(i);
        p = p->next;
    }
}
void read_graph()
{
    int i, vi, vj, no_of_edges;
    printf("Enter number of vertices:");
    scanf("%d", &n);
    // initialiseG[] with a NULL
    for (i = 0; i < n; i++)
    {
        G[i] = NULL;
        // read edges and insert them in G[]

        printf("Enter number of edges:");
        scanf("%d", &no_of_edges);
        for (i = 0; i < no_of_edges; i++)
        {
            printf("Enter an edge(u,v):");
            scanf("%d%d", &vi, &vj);
            insert(vi, vj);
        }
    }
}
void insert(int vi, int vj)
{
    node *p, *q;

    // acquire memory for the new node
    q = (node *)malloc(sizeof(node));
    q->vertex = vj;
    q->next = NULL;
    // insert the node in the linked list number vi
    if (G[vi] == NULL)
        G[vi] = q;
    else
    {
        // go to end of the linked list
        p = G[vi];

        while (p->next != NULL)
            p = p->next;
        p->next = q;
    }
}

// OUTPUT:
// Enter number of vertices:8
// Enter number of edges:10
// Enter an edge(u,v):0 1
// Enter an edge(u,v):0 2
// Enter an edge(u,v):0 3
// Enter an edge(u,v):0 4
// Enter an edge(u,v):1 5
// Enter an edge(u,v):2 5
// Enter an edge(u,v):3 6
// Enter an edge(u,v):4 6
// Enter an edge(u,v):5 7
// Enter an edge(u,v):6 7
// 0 1 5 7 2 3 6 4
