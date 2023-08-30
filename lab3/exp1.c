#include <stdio.h>
#include <stdlib.h>

void main()
{
    printf("Enter the number of rows and columns of the array\n");
    int m, n;
    scanf("%d %d", &m, &n);
    int count = 0;
    int arr[m][n];

    printf("Enter the elements of the matrix\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] != 0)
            {
                count++;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // To store in three tuple form
    int storage[count + 1][3];
    storage[0][0] = m;
    storage[0][1] = n;
    storage[0][2] = count;
    printf("The sparse matrix in three tuple format is \n");
    int k = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                storage[k][0] = i;
                storage[k][1] = j;
                storage[k][2] = arr[i][j];
                k++;
            }
        }
    }

    for (int k = 0; k < count + 1; k++)
    {
        printf("%d %d %d\n", storage[k][0], storage[k][1], storage[k][2]);
    }

    // Transpose
    for (int k = 0; k < count + 1; k++)
    {
        int temp = storage[k][1];
        storage[k][1] = storage[k][0];
        storage[k][0] = temp;
    }

    // Three tuple to sparse
    int sparse[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sparse[i][j] = 0;
        }
    }

    for (int i = 0; i < count + 1; i++)
    {
        int temp1 = storage[i][0];
        int temp2 = storage[i][1];
        sparse[temp1][temp2] = storage[i][2];
    }

    printf("The final matrix is \n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", sparse[i][j]);
        }
        printf("\n");
    }
}
