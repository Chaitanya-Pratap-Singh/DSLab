#include <stdio.h>

#define MAX_VERTICES 100

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
int visited[MAX_VERTICES] = {0};
int degree[MAX_VERTICES] = {0};

void dfs(int vertex)
{
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 1; i <= MAX_VERTICES; ++i)
    {
        if (adjacencyMatrix[vertex][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &adjacencyMatrix[i][j]);
            if (adjacencyMatrix[i][j])
            {
                degree[i]++;
                degree[j]++;
            }
        }
    }

    // Display the degree of each vertex
    printf("\nVertex Degree\n");
    for (int i = 1; i <= n; ++i)
    {
        printf("%d %d\n", i, degree[i]);
    }

    // DFS traversal
    int startVertex;
    printf("Enter start vertex: ");
    scanf("%d", &startVertex);

    printf("\nDepth First Search: ");
    dfs(startVertex);
    printf("\n");

    return 0;
}
