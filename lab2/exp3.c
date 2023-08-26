#include <stdio.h>

// Function to count the number of non-zero elements in a matrix
int countNonZero(int matrix[][100], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}

// Function to display the upper triangular matrix
void displayUpperTriangular(int matrix[][100], int n)
{
    printf("Upper Triangular Matrix:\n");
    printf("\nThe upper triangular matrix is \n");
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if(j>=i)
            {
                printf("%d",matrix[i][j]);
            }
            else
            {
                printf(" ");
            }
        }
       printf("\n");
    }

}

// Function to display elements just above and below the main diagonal
void displayDiagonalElements(int matrix[][100], int n)
{
    printf("Elements above and below the main diagonal:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i - 1 || j == i + 1)
            {
                printf("%d ", matrix[i][j]);
            }
            else
            {
             printf(" ");

            }
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int matrix[100][100];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Count non-zero elements
    int nonZeroCount = countNonZero(matrix, n);
    printf("Number of non-zero elements: %d\n", nonZeroCount);

    // Display upper triangular matrix
    displayUpperTriangular(matrix, n);

    // Display elements just above and below the main diagonal
    displayDiagonalElements(matrix, n);

    return 0;
}
