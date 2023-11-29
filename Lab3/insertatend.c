#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void insertAtEnd(int k)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = k;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (head == NULL)
    {
        head = ptr;
        tail = ptr;
    }
    else
    {
        ptr->prev = tail;
        tail->next = ptr;
        tail = ptr;
    }
}

void printList(struct node *current)
{
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);

    printf("Doubly linked list: ");
    printList(head);

    return 0;
}
