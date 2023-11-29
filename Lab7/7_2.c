#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the linear queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function prototypes
void initializeQueue(struct Queue* q);
int isEmpty(struct Queue* q);
void enqueue(struct Queue* q, int element);
int dequeue(struct Queue* q);
void traverse(struct Queue* q);

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    int choice, element;

    do {
        // Display the main menu
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");

        // Get the user's choice
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Enqueue operation
                printf("Enter element: ");
                scanf("%d", &element);
                enqueue(&queue, element);
                printf("Element enqueued\n");
                break;

            case 2:
                // Dequeue operation
                if (!isEmpty(&queue)) {
                    element = dequeue(&queue);
                    printf("Element %d dequeued\n", element);
                } else {
                    printf("Queue is empty. Dequeue operation failed\n");
                }
                break;

            case 3:
                // IsEmpty operation
                if (isEmpty(&queue)) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;

            case 4:
                // Traverse operation
                traverse(&queue);
                break;

            case 5:
                // Exit the program
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid option. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}

// Function to initialize the queue
void initializeQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Function to perform enqueue operation
void enqueue(struct Queue* q, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to perform dequeue operation
int dequeue(struct Queue* q) {
    struct Node* temp = q->front;
    int element = temp->data;

    if (q->front == q->rear) {
        // Last element in the queue
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
    }

    free(temp);
    return element;
}

// Function to traverse and display the elements of the queue
void traverse(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        struct Node* current = q->front;
        printf("Queue: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
