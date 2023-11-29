// Given an array of N integer elements. Count the number of elements in an array such that at least 1 element is greater than itself.
#include <stdio.h>

int countElementsGreaterThanThemselves(int arr[], int N)
{
    int count = 0;

    for (int i = 0; i < N; ++i)
    {
        int hasGreater = 0;
        for (int j = 0; j < N; ++j)
        {
            if (arr[j] > arr[i])
            {
                hasGreater = 1;
                break;
            }
        }
        if (hasGreater)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &arr[i]);
    }

    int result = countElementsGreaterThanThemselves(arr, N);
    printf("Number of elements greater than at least one element: %d\n", result);

    return 0;
}
