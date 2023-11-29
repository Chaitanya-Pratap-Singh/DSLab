#include <stdio.h>

#define MAX_SIZE 5

// Define a structure for the linear queue
struct Queue {
    int front, rear;
    int array[MAX_SIZE];
};

// Function prototypes
void initializeQueue(struct Queue* q);
int isFull(struct Queue* q);
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
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");

        // Get the user's choice
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Enqueue operation
                printf("Enter element: ");
                scanf("%d", &element);
                if (!isFull(&queue)) {
                    enqueue(&queue, element);
                    printf("Element enqueued\n");
                } else {
                    printf("Queue is full. Enqueue operation failed\n");
                }
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
                // IsFull operation
                if (isFull(&queue)) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;

            case 5:
                // Traverse operation
                traverse(&queue);
                break;

            case 6:
                // Exit the program
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid option. Please enter a valid option.\n");
        }

    } while (choice != 6);

    return 0;
}

// Function to initialize the queue
void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    return (q->rear == MAX_SIZE - 1);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

// Function to perform enqueue operation
void enqueue(struct Queue* q, int element) {
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->array[q->rear] = element;
}

// Function to perform dequeue operation
int dequeue(struct Queue* q) {
    int element = q->array[q->front];
    if (q->front == q->rear) {
        // Last element in the queue
        initializeQueue(q);
    } else {
        q->front++;
    }
    return element;
}

// Function to traverse and display the elements of the queue
void traverse(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->array[i]);
        }
        printf("\n");
    }
}
