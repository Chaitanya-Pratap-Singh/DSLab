#include <stdio.h>

// Function to perform insertion sort in ascending order
void insertionSortAscending(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform insertion sort in descending order
void insertionSortDescending(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSortAscending(arr, n);

    // Displaying ascending order
    printf("Ascending order:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");

    // Sorting in descending order
    insertionSortDescending(arr, n);

    // Displaying descending order
    printf("Descending order:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");

    return 0;
}
