#include <stdio.h>
#include <stdlib.h>

void prims(int n, int cost[10][10])
{
    int i, j, u, v, min, mincost = 0, visited[10], no_of_edges = 1;
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    printf("The edges considered for MST are:-");
    visited[1] = 1;
    while (no_of_edges < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    if (visited[i] == 0)
                    {
                        continue;
                    }
                    else
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf(" %d Edge(%d,%d) = %d\n", no_of_edges++, u, v, min);
            mincost += min;
            visited[v] = 1;
        }
        cost[u][v] = cost[v][u] = 999;
    }
    printf("Cost of Constructing MST is %d:", mincost);
}
void main()
{
    int i, j, n, cost[10][10];
    printf("Read The number of nodes:");
    scanf("%d", &n);
    printf("Read the cost Matrix:");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }
    prims(n, cost);
}