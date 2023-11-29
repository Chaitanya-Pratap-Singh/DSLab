#include <stdio.h>

int main() 
{
    int n,i,j,m,r=1;

//ENTRY OF FIRST THREE TUPLE FORMAT MATRIX
    printf("Enter the number of non-zero elements:");
    scanf("%d", &n);

    int A[n+1][3];

    printf("Enter the number of rows:");
    scanf("%d", &A[0][0]);

    printf("Enter the number of columns:");
    scanf("%d", &A[0][1]);

    A[0][2] = n;

    printf("Enter the values in tuple form:\n");
    for (i = 1; i <= n; i++) 
    {
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    }
    
    printf("Sparse matrix representation in three tuple:\n");
    for (i = 0; i <= n; i++) 
    { 
        printf("%d %d %d\n", A[i][0], A[i][1], A[i][2]);
    }

//CONVERSION TO NORMAL FORM AND STORED IN B MATRIX
    n = A[0][0];
    m = A[0][1];

    int B[n][m];
    
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < m; j++) 
        {
            B[i][j] = 0;
        }
    }
    
for (i = 0; i < n; i++) 
{
    for (j = 0; j < m; j++) 
    {
        int temp1 = A[r][0];
        int temp2 = A[r][1];
        if (i == temp1 && j == temp2) {
            B[i][j] = A[r][2];
            r++;
        }
    }
}


    int p,k,l,q,t=1;

//ENTRY OF SECOND MATRIX IN THREE TUPLE FORMAT

    printf("Enter the number of non-zero elements:");
    scanf("%d", &p);

    int C[n+1][3];

    printf("Enter the number of rows:");
    scanf("%d", &C[0][0]);

    printf("Enter the number of columns:");
    scanf("%d", &C[0][1]);

    C[0][2] = p;

    printf("Enter the values in tuple form:\n");
    for (k = 1; k <= p; k++) 
    {
        scanf("%d %d %d", &C[k][0], &C[k][1], &C[k][2]);
    }
    
    printf("S. matrix representation in three tuple:\n");
    for (k=0;k<=p;k++) 
        { 
        printf("%d %d %d\n", C[k][0], C[k][1], C[k][2]);
        }

//CONVERSION TO NORMAL FORM

    p = C[0][0];
    q = C[0][1];

    int D[p][q];
    
    for (k=0;k<p;k++) 
        {
        for (l=0;l<q;l++) 
            {
            C[k][l] = 0;
            }
        }
    
for (k= 0;k<p;k++) 
    {
    for (l=0;l<q;l++) 
        {
        int temp3 = C[t][0];
        int temp4 = A[t][1];
        if (i == temp3 && j == temp4) 
            {
            D[i][j] = A[t][2];
            t++;
            }
        }
    }
    

    return 0;
}