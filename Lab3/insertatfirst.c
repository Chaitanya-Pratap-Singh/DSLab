#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void insertAtEnd(int k)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->key = k;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (head == NULL)
    {
        head = ptr;
        tail = head;
    }
    else
    {
        struct node *temp = ptr;
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void printList(struct node *current)
{
    while (current != NULL)
    {
        printf("%d ", current->key);
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