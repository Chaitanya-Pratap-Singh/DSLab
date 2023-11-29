#include <stdio.h>

// Function to perform heapify on a subtree rooted at given index
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize the largest as the root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root, swap and recursively heapify the affected sub-tree
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort on the array
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from the heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move the current root to the end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
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

    // Sorting in ascending order using Heap Sort
    heapSort(arr, n);

    // Displaying ascending order
    printf("Ascending order:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");

    return 0;
}
