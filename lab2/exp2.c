#include <stdio.h>
void main()
{
    int k, n, arr[100], temp;
    printf("enter the size of the array \n");
    scanf("%d", &n);
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number of times array should be rotated\n");
    scanf("%d", &k); // Add '&' before k to correctly read the value

    for (int i = 0; i < k; i++)
    {
        temp = arr[n - 1]; // Use n - 1 to access the last element
        for (int j = n - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1]; // Shift elements to the right
        }
        arr[0] = temp; // Place the last element at the beginning
    }
    printf("revised array \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
