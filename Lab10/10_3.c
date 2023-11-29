#include <stdio.h>

#define MAX_VERTICES 100
#define QUEUE_SIZE 100

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
int visited[MAX_VERTICES] = {0};
int degree[MAX_VERTICES] = {0};
int queue[QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int vertex)
{
    if (rear == QUEUE_SIZE - 1)
    {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = vertex;
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int vertex = queue[front];
    front++;
    if (front > rear)
    {
        front = rear = -1;
    }
    return vertex;
}

void bfs(int startVertex)
{
    enqueue(startVertex);
    visited[startVertex] = 1;

    while (front != -1)
    {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (int i = 1; i <= MAX_VERTICES; ++i)
        {
            if (adjacencyMatrix[currentVertex][i] && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
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

    // BFS traversal
    int startVertex;
    printf("Enter start vertex: ");
    scanf("%d", &startVertex);

    printf("\nBreadth First Search: ");
    bfs(startVertex);
    printf("\n");

    return 0;
}
