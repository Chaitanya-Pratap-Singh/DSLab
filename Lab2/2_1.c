// An element in an array X is called a leader if it is greater than all elements to the right of it in X. The best algorithm to find all leaders in an array
#include <stdio.h>

void findLeaders(int arr[], int n)
{
    int currentMax = arr[n - 1];
    printf("Leaders in the array: %d ", currentMax);

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > currentMax)
        {
            currentMax = arr[i];
            printf("%d ", currentMax);
        }
    }

    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    findLeaders(arr, n);

    return 0;
}
