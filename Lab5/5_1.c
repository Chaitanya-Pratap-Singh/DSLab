#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertNode(struct Node **head, int data, int position)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        if (position <= 1)
        {
            newNode->next = *head;
            (*head)->prev = newNode;
            *head = newNode;
        }
        else
        {
            struct Node *current = *head;
            int count = 1;
            while (count < position - 1 && current->next != NULL)
            {
                current = current->next;
                count++;
            }
            newNode->prev = current;
            newNode->next = current->next;
            if (current->next != NULL)
            {
                current->next->prev = newNode;
            }
            current->next = newNode;
        }
    }
    printf("Node inserted\n");
}
void deleteNode(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
    }
    else
    {
        struct Node *current = *head;
        int count = 1;
        while (count < position && current != NULL)
        {
            current = current->next;
            count++;
        }
        if (current == NULL)
        {
            printf("Position out of range. Cannot delete.\n");
        }
        else
        {
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            else
            {
                *head = current->next;
            }
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
            free(current);
            printf("Node deleted\n");
        }
    }
}
void traverseList(struct Node *head)
{
    printf("The list is: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int n, data, choice, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insertNode(&head, data, i + 1);
    }

    while (1)
    {
        printf("MENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Traversal\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &position);
            insertNode(&head, data, position);
            break;
        case 2:
            printf("Enter position: ");
            scanf("%d", &position);
            deleteNode(&head, position);
            break;
        case 3:
            traverseList(head);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
