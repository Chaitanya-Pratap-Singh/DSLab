#include <stdio.h>

// Function to perform selection sort in ascending order
void selectionSortAscending(int arr[], int n)
{
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the element at index i
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to perform selection sort in descending order
void selectionSortDescending(int arr[], int n)
{
    int i, j, maxIndex, temp;
    for (i = 0; i < n - 1; i++)
    {
        maxIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }
        // Swap the found maximum element with the element at index i
        temp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Sorting in ascending order
    selectionSortAscending(arr, n);

    // Displaying ascending order
    printf("Ascending order:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");

    // Sorting in descending order
    selectionSortDescending(arr, n);

    // Displaying descending order
    printf("Descending order:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");

    return 0;
}
