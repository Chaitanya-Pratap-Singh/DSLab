#include<stdio.h>

void compare(int* a, int* b){
    if(*a > *b)
        printf("%d is greater than %d ",*a,*b);
    else if(*b > *a)
        printf("%d is greater than %d ",*b,*a);
    else
        printf("Both are equal ");
}

int main(){
    int a,b;
    printf("Enter 2 numbers: ");
    scanf("%d%d",&a,&b);
    compare(&a,&b);
    return 0;
}