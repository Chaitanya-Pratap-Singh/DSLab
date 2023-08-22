#include <stdio.h>
#include <stdlib.h>

int prime(int num) 
    {
    if (num <= 1) 
    {
        return 0; 
    }

    for (int i = 2; i * i <= num; i++) 
        {
        if (num % i == 0) 
            {
            return 0; 
            }
        }

    return 1; 
    }

int main() {
    int n;
    printf("Enter the number of digits you want to save in the array: \n");
    scanf("%d", &n);
    printf("Enter the numbers \n");
    int* p = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", (p + i));
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (prime(p[i])) 
            {
            sum += p[i];
            }
    }

    printf("%d is the sum of all the prime digits\n", sum);

    free(p);
    return 0;
}