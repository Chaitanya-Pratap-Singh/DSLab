#include <stdio.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Check if the key is present at the middle
        if (arr[mid] == key)
            return 1; // Element found

        // If the key is greater, ignore the left half
        if (arr[mid] < key)
            low = mid + 1;

        // If the key is smaller, ignore the right half
        else
            high = mid - 1;
    }

    // If the key is not present in the array
    return 0;
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements (sorted): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    // Performing binary search
    int result = binarySearch(arr, 0, n - 1, key);

    // Displaying the result
    if (result)
        printf("Element found\n");
    else
        printf("Element not found\n");

    return 0;
}
