// Given an array and a number K where K is smaller than the size of the array. Find the K’th smallest element in the given array. Given that all array elements are distinct.
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int kthSmallest(int arr[], int N, int K)
{
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    return arr[K - 1];
}

int main()
{
    int N, K;

    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of K: ");
    scanf("%d", &K);

    if (K >= 1 && K <= N)
    {
        printf("K'th smallest element is %d", kthSmallest(arr, N, K));
    }
    else
    {
        printf("Invalid value of K. K should be between 1 and %d", N);
    }

    return 0;
}
