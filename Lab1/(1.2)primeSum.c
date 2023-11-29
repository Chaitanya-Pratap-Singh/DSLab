#include<stdio.h>
#include<stdlib.h>
int isPrime(int num){
    int i = 1,count = 0;
    while(i <= num){
        if(num%i == 0){
            count ++;
        }
        i += 1;
    }

    if(count != 2)
        return 0;
    else
        return 1;
}

int primeSum(int* arr, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(isPrime(arr[i]))
            sum += arr[i];
    }
    return sum;
}

int main(){
    int n;
    printf("Enter number of elements of the array ");
    scanf("%d",&n);

    int* arr = (int*)malloc(n* sizeof(int));

    printf("Enter the numbers ");

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int sum =  primeSum(arr,n);

    printf("Sum of prime numbers in array is %d", sum);

    free(arr);

    return 0;
}
