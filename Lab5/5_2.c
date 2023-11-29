#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void insert(struct node **head,int data)
{
    struct node *newnode=createnode(data);
    if(*head==NULL)
    {
        *head=newnode;
        newnode->next=*head;
    }
    else
    {
        struct node *temp=*head;
        while(temp->next!=*head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=*head;
    }
}
void display(struct node *head)
{
    struct node *current=head;
    if(head==NULL)
    {
        printf("circular linked list is empty.\n");
        return;
    }
    printf("circular linked list:");
    do
    {
        printf("%d ",current->data);
        current=current->next;
    } while (current!=head);
    printf("\n");
}
int main()
{
    struct node *head=NULL;
    int n,data;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter node %d data:",i+1);
        scanf("%d",&data);
        insert(&head,data);
    }
    display(head);
    if(head!=NULL)
    {
        struct node *current=head;
        struct node *next;
        do
        {
            next=current->next;
            free(current);
            current=next;
        } while(current!=head);  
    }
    return 0;
}