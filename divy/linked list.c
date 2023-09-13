#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*START=NULL;

void traverse()
{
    struct node *temp;
    
    if(START==NULL)
    {
        printf("No node exists\n");
    }
    else
    {
        temp=START;
        while(temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}

void insert_at_beg()
{
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    int key;
    printf("Enter the data \n");
    scanf("%d",&key);
    ptr->data=key;
    ptr->link=START;
    START=ptr;
}

void mid()
{
     struct node *temp;int count=0;
    if(START==NULL)
    {
        printf("No mid exists\n");
    }
    else
    {
        temp=START;
        while(temp!=NULL)
        {
            count++;
            temp=temp->link;
        }
        count=count/2;
        temp=START;
        for(int i=0;i<=count;i++)
        {
            temp=temp->link;
        }
        printf("%d ",temp->data);
    }

}

void insert_at_end()
{
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    struct node *temp;
    printf("Enter the key\n");
    int key;
    scanf("%d",&key);
    ptr->data=key;
    ptr->link=NULL;
    if(START==NULL)
    {
        START=ptr;
        ptr->link=NULL;
    }
    else
    {
        temp=START;
        while(temp->link != NULL)
        {
            temp=temp->link;
        }
        temp->link=ptr;
    }
}

void insert_at_pos()
{
    int pos;struct node *ptr;struct node *temp;
    ptr=malloc(sizeof(struct node));


    printf("Enter the position you want to insert\n");
    scanf("%d",&pos);

    printf("Enter the data of the node\n");
    int key;scanf("%d",&key);
    ptr->data=key;


    if(pos==0)
    {
        ptr->link=START;
        START=ptr;
    }
    else
    {
    temp=START;
    for(int i=1;i< pos-1 ;i++)
    {
        temp=temp->link;
    }
        struct node *nex;
        nex=temp->link;
        ptr->link=nex;
        temp->link=ptr;

    }


}

void count()
{
    struct node *temp;int count=0;
    if(START==NULL)
    {
        printf("No node exists\n");
    }
    else
    {
        temp=START;
        while(temp!=NULL)
        {
            count++;
            temp=temp->link;
        }
        printf("The number of nodes are: %d \n",count);
        
    }
}

void main()
{
    int n=1;
    
    while(n>0)
    {
        printf("\n           MENU       \n");
        printf(" 0: TRAVERSE\n");
        printf(" 1: Insert at End\n");
        printf(" 2: Insert at begining\n");
        printf(" 3: Count\n\n");
        printf(" 4: To find the middle element\n");
        printf(" 5: Insert at pos\n");
        printf("EXIT: Enter -ve no to \n");
        printf("Enter your choice:");
        scanf("%d",&n);
        switch(n)
        {
        case 0:
            traverse();
            break;

        case 1:
            insert_at_end();
            break;


        case 2:
            insert_at_beg();
            break;

        case 3:
            count();
            break;

        case 4:
            mid();
            break;

        case 5:
            insert_at_pos();
            break;    
        
        default:
            printf("Error! operator is not correct");
        }
    }
    
}#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*START=NULL;

void traverse()
{
    struct node *temp;
    
    if(START==NULL)
    {
        printf("No node exists\n");
    }
    else
    {
        temp=START;
        while(temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}

void insert_at_beg()
{
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    int key;
    printf("Enter the data \n");
    scanf("%d",&key);
    ptr->data=key;
    ptr->link=START;
    START=ptr;
}

void mid()
{
     struct node *temp;int count=0;
    if(START==NULL)
    {
        printf("No mid exists\n");
    }
    else
    {
        temp=START;
        while(temp!=NULL)
        {
            count++;
            temp=temp->link;
        }
        count=count/2;
        temp=START;
        for(int i=0;i<=count;i++)
        {
            temp=temp->link;
        }
        printf("%d ",temp->data);
    }

}

void insert_at_end()
{
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    struct node *temp;
    printf("Enter the key\n");
    int key;
    scanf("%d",&key);
    ptr->data=key;
    ptr->link=NULL;
    if(START==NULL)
    {
        START=ptr;
        ptr->link=NULL;
    }
    else
    {
        temp=START;
        while(temp->link != NULL)
        {
            temp=temp->link;
        }
        temp->link=ptr;
    }
}

void insert_at_pos()
{
    int pos;struct node *ptr;struct node *temp;
    ptr=malloc(sizeof(struct node));


    printf("Enter the position you want to insert\n");
    scanf("%d",&pos);

    printf("Enter the data of the node\n");
    int key;scanf("%d",&key);
    ptr->data=key;


    if(pos==0)
    {
        ptr->link=START;
        START=ptr;
    }
    else
    {
    temp=START;
    for(int i=1;i< pos-1 ;i++)
    {
        temp=temp->link;
    }
        struct node *nex;
        nex=temp->link;
        ptr->link=nex;
        temp->link=ptr;

    }


}

void count()
{
    struct node *temp;int count=0;
    if(START==NULL)
    {
        printf("No node exists\n");
    }
    else
    {
        temp=START;
        while(temp!=NULL)
        {
            count++;
            temp=temp->link;
        }
        printf("The number of nodes are: %d \n",count);
        
    }
}

void main()
{
    int n=1;
    
    while(n>0)
    {
        printf("\n           MENU       \n");
        printf(" 0: TRAVERSE\n");
        printf(" 1: Insert at End\n");
        printf(" 2: Insert at begining\n");
        printf(" 3: Count\n\n");
        printf(" 4: To find the middle element\n");
        printf(" 5: Insert at pos\n");
        printf("EXIT: Enter -ve no to \n");
        printf("Enter your choice:");
        scanf("%d",&n);
        switch(n)
        {
        case 0:
            traverse();
            break;

        case 1:
            insert_at_end();
            break;


        case 2:
            insert_at_beg();
            break;

        case 3:
            count();
            break;

        case 4:
            mid();
            break;

        case 5:
            insert_at_pos();
            break;    
        
        default:
            printf("Error! operator is not correct");
        }
    }
    
}
