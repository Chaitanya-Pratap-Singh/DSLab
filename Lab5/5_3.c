#include<stdio.h>
#include<stdlib.h>
struct node
{
    int row;
    int col;
    int value;
    struct node *next;
};
struct node *createnode(int row,int col,int value)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->row=row;
    newnode->col=col;
    newnode->value=value;
    newnode->next=NULL;
    return newnode;
}
void insert(struct node **head,int row,int col,int value)
{
    struct node *newnode=createnode(row,col,value);
    if(*head==NULL)
    {
        *head=newnode;
    } 
    else
    {
        struct node *current=*head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=newnode;
    }
}
void display(struct node *head,int rows,int cols,int c)
{
    printf("sparse matrix in 3-tuple format\n");
    printf("%d %d %d\n",rows,cols,c);
    struct node *current=head;
    while(current!=NULL)
    {
        printf("%d %d %d\n",current->row,current->col,current->value);
        current=current->next;
    }
}
int main()
{
    struct node *head=NULL;
    int rows,cols;
    printf("enter the size of the sparse matrix(rows columns):");
    scanf("%d %d",&rows,&cols);
    printf("enter the elements of the sparse matrix:\n");
    int c=0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            int value;
            scanf("%d",&value);
            if(value!=0)
            {
                insert(&head,i,j,value);
                c++;
            }
        }
    }
    display(head,rows,cols,c);
    while(head!=NULL)
    {
        struct node *temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}