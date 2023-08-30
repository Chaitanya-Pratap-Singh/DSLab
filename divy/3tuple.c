#include<stdio.h>
#include<stdlib.h>

void main()
{
    printf("Enter the no of elements of the array\n");
    int n;
    scanf("%d",&n);
    int count=0;
    int arr[n][n];
    printf("Enter the elements of the matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
            if((arr[i][j])!=0)
            {
                count++;
            }
        }
    }

    //To store in three tuple form
    
    int storage[count][3];
    storage[0][0]=n;
    storage[0][1]=n;
    storage[0][2]=count;
    printf("The sparse matrix in three tuple format is \n");
    int k=1;
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]!=0)
            {
                storage[k][0]=i;
                storage[k][1]=j;
                storage[k][2]=arr[i][j];
                k++;

               
            }
            
        }
       }

     printf("The sparse matrix in three tuple format is \n");
     
     for(int k=0;k<count+1;k++)
     {
        printf("%d %d %d\n",storage[k][0],storage[k][1],storage[k][2]);
     }
    }