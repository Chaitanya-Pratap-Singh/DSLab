#include <stdio.h>

void insertElement(int arr[], int *size, int position, int element)
{
    if (*size >= 100)
    {
        printf("Array is full, cannot insert.\n");
        return;
    }

    if (position < 0 || position > *size)
    {
        printf("Invalid position for insertion.\n");
        return;
    }

    for (int i = *size; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    (*size)++;
    printf("Element inserted successfully.\n");
}

void deleteElement(int arr[], int *size, int position)
{
    if (*size <= 0 || position < 0 || position >= *size)
    {
        printf("Invalid position for deletion.\n");
        return;
    }

    for (int i = position; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("Element deleted successfully.\n");
}

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1; // Element not found
}

void traverseArray(int arr[], int size)
{
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[100], size;
    printf("Enter size of array: \n ");
    scanf("%d", &size);

    printf("Enter array elements: \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int choice, element, position, searchElement, result;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Linear search\n");
        printf("4. Traverse array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            printf("Enter the position to insert at: ");
            scanf("%d", &position);
            insertElement(arr, &size, position, element);
            break;
        case 2:
            printf("Enter the position to delete from: ");
            scanf("%d", &position);
            deleteElement(arr, &size, position);
            break;
        case 3:
            printf("Enter the element to search: ");
            scanf("%d", &searchElement);
            result = linearSearch(arr, size, searchElement);
            if (result != -1)
            {
                printf("Element found at position %d.\n", result);
            }
            else
            {
                printf("Element not found.\n");
            }
            break;
        case 4:
            traverseArray(arr, size);
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}
