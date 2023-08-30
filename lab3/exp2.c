#include <stdio.h>

int main() 
{
    // First sparse matrix in 3-tuple form
    int n, i;
    printf("First matrix\n");
    printf("Enter the number of non-zero elements:");
    scanf("%d", &n);

    int A[n + 1][3];

    printf("Enter the number of rows:");
    scanf("%d", &A[0][0]);

    printf("Enter the number of columns:");
    scanf("%d", &A[0][1]);

    A[0][2] = n;

    printf("Enter the values:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    }

    // Second matrix
    printf("Second matrix\n");
    int m, j;

    printf("Enter the number of non-zero elements:");
    scanf("%d", &m);

    int B[m + 1][3];

    printf("Enter the number of rows:");
    scanf("%d", &B[0][0]);

    printf("Enter the number of columns:");
    scanf("%d", &B[0][1]);

    B[0][2] = m;

    printf("Enter the values:\n");
    for (j = 1; j <= m; j++) {
        scanf("%d %d %d", &B[j][0], &B[j][1], &B[j][2]);
    }

    // Start of sum
    int k = 1, C[n + m + 1][3];  // Change k to n + m + 1 to handle worst case
    i = 1;
    j = 1;

    if (A[0][0] == B[0][0] && A[0][1] == B[0][1]) {
        C[0][0] = A[0][0];
        C[0][1] = A[0][1];

        while (i <= n && j <= m) {
            if (A[i][0] == B[j][0]) {
                if (A[i][1] == B[j][1]) {
                    C[k][0] = A[i][0];
                    C[k][1] = A[i][1];
                    C[k][2] = A[i][2] + B[j][2];
                    i++;
                    j++;
                    k++;
                } else if (A[i][1] < B[j][1]) {
                    C[k][0] = A[i][0];
                    C[k][1] = A[i][1];
                    C[k][2] = A[i][2];
                    i++;
                    k++;
                } else {
                    C[k][0] = B[j][0];
                    C[k][1] = B[j][1];
                    C[k][2] = B[j][2];
                    j++;
                    k++;
                }
            } else if (A[i][0] < B[j][0]) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = A[i][2];
                i++;
                k++;
            } else {
                C[k][0] = B[j][0];
                C[k][1] = B[j][1];
                C[k][2] = B[j][2];
                j++;
                k++;
            }
        }

        while (i <= n) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++;
            k++;
        }

        while (j <= m) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++;
            k++;
        }

        C[0][2] = k - 1;
        printf("Sum sparse matrix:\n");
        for (i = 0; i < k; i++) {
            printf("%d %d %d\n", C[i][0], C[i][1], C[i][2]);
        }
    }

    return 0;
}