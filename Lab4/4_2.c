#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at a specific position
void insertNode(struct Node** head, int element, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position!\n");
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    printf("Node inserted\n");
}

// Function to delete a node from a specific position
void deleteNode(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (position == 1) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Node deleted\n");
    } else {
        struct Node* temp = *head;
        struct Node* prev = NULL;
        int count = 1;

        while (count < position && temp != NULL) {
            prev = temp;
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            printf("Invalid position!\n");
        } else {
            prev->next = temp->next;
            free(temp);
            printf("Node deleted\n");
        }
    }
}

// Function to count nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

// Function to traverse and print the linked list
void traverseList(struct Node* head) {
    struct Node* current = head;

    printf("The list is: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to search for an element in the linked list
int searchElement(struct Node* head, int element) {
    struct Node* current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == element) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1; // Element not found
}

// Function to sort the linked list in ascending order using bubble sort
void sortList(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot sort.\n");
        return;
    }

    int swapped, temp;
    struct Node* current;
    struct Node* last = NULL;

    do {
        swapped = 0;
        current = *head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
    printf("List sorted in ascending order\n");
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    printf("List reversed\n");
}

int main() {
    struct Node* head = NULL;
    int n, choice, element, position, searchElementResult;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes!\n");
        return 1;
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        insertNode(&head, element, i + 1);
    }

    while (1) {
        printf("MENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Count\n");
        printf("4. Traverse\n");
        printf("5. Search\n");
        printf("6. Sort\n");
        printf("7. Reverse\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter position: ");
                scanf("%d", &position);
                insertNode(&head, element, position);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNode(&head, position);
                break;
            case 3:
                printf("The total number of nodes: %d\n", countNodes(head));
                break;
            case 4:
                traverseList(head);
                break;
            case 5:
                printf("Enter element to be searched: ");
                scanf("%d", &element);
                searchElementResult = searchElement(head, element);
                if (searchElementResult != -1) {
                    printf("Element found at node-%d\n", searchElementResult);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 6:
                sortList(&head);
                break;
            case 7:
                reverseList(&head);
                break;
            case 8:
                // Free allocated memory and exit
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
