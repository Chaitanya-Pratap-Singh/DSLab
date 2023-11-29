#include <stdio.h>

#define MAX_VERTICES 100

int main()
{
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    int degree[MAX_VERTICES] = {0};

    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            char response;
            printf("Vertices %d & %d are Adjacent? (Y/N): ", i, j);
            scanf(" %c", &response);

            if (response == 'Y' || response == 'y')
            {
                adjacencyMatrix[i][j] = 1;
                adjacencyMatrix[j][i] = 1;
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

    return 0;
}
