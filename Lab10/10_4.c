#include <stdio.h>

#define MAX_VERTICES 100

int main()
{
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    int inDegree[MAX_VERTICES] = {0};
    int outDegree[MAX_VERTICES] = {0};
    int totalDegree[MAX_VERTICES] = {0};

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
                outDegree[i]++;
                inDegree[j]++;
                totalDegree[i]++;
                totalDegree[j]++;
            }
        }
    }

    // Display the degree of each vertex
    printf("\nVertex In_Degree Out_Degree Total_Degree\n");
    for (int i = 1; i <= n; ++i)
    {
        printf("%d %d %d %d\n", i, inDegree[i], outDegree[i], totalDegree[i]);
    }

    return 0;
}
