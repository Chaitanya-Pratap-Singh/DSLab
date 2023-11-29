#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int power;
    struct node *next;
};
struct node *createnode(int coeff, int power)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->power = power;
    newnode->next = NULL;
    return newnode;
}
void insert(struct node **poly, int coeff, int power)
{
    struct node *newnode = createnode(coeff, power);
    if (*poly == NULL)
    {
        *poly = newnode;
    }
    else
    {
        struct node *temp = *poly;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
struct node *addpoly(struct node *poly1, struct node *poly2)
{
    struct node *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->power > poly2->power)
        {
            insert(&result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        }
        else if (poly2->power > poly1->power)
        {
            insert(&result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        }
        else
        {
            int sumcoeff = poly1->coeff + poly2->coeff;
            if (sumcoeff != 0)
            {
                insert(&result, sumcoeff, poly1->power);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        insert(&result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        insert(&result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }
    return result;
}
void displaypolynomial(struct node *poly)
{
    struct node *temp = poly;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->power);
        temp = temp->next;
        if (temp != NULL)
        {
            printf("+");
        }
    }
    printf("\n");
}
int main()
{
    struct node *poly1=NULL;
    struct node *poly2=NULL;
    int mpower1,mpower2;
    printf("polynomial-1\n");
    printf("enter the maximun power of X:");
    scanf("%d",&mpower1);
    for(int i=mpower1;i>=0;i--)
    {
        int coeff;
        printf("enter the coefficient of the degree %d:",i);
        scanf("%d",&coeff);
        if(coeff!=0)
        {
            insert(&poly1,coeff,i);
        }
    }
    printf("polynomial-2\n");
    printf("enter the maximun power of X:");
    scanf("%d",&mpower2);
    for(int i=mpower2;i>=0;i--)
    {
        int coeff;
        printf("enter the coefficient of the degree %d:",i);
        scanf("%d",&coeff);
        if(coeff!=0)
        {
            insert(&poly2,coeff,i);
        }
    }
    struct node *sum=addpoly(poly1,poly2);
    printf("sum:");
    displaypolynomial(sum);
    while(poly1!=NULL)
    {
        struct node *temp=poly1;
        poly1=poly1->next;
        free(temp);
    }
    while(poly2!=NULL)
    {
        struct node *temp=poly2;
        poly2=poly2->next;
        free(temp);
    }
    while(sum!=NULL)
    {
        struct node *temp=sum;
        sum=sum->next;
        free(temp); 
    }
    return 0;
}