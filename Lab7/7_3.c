#include <stdio.h>

#define MAX_SIZE 10

// Define a structure for the circular queue
struct CircularQueue {
    int front, rear;
    int array[MAX_SIZE];
};

// Function prototypes
void initializeQueue(struct CircularQueue* cq);
int isEmpty(struct CircularQueue* cq);
int isFull(struct CircularQueue* cq);
void enqueue(struct CircularQueue* cq, int element);
int dequeue(struct CircularQueue* cq);
void traverse(struct CircularQueue* cq);

int main() {
    struct CircularQueue cqueue;
    initializeQueue(&cqueue);

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
                if (!isFull(&cqueue)) {
                    enqueue(&cqueue, element);
                    printf("Element enqueued\n");
                } else {
                    printf("Queue is full. Enqueue operation failed\n");
                }
                break;

            case 2:
                // Dequeue operation
                if (!isEmpty(&cqueue)) {
                    element = dequeue(&cqueue);
                    printf("Element %d dequeued\n", element);
                } else {
                    printf("Queue is empty. Dequeue operation failed\n");
                }
                break;

            case 3:
                // IsEmpty operation
                if (isEmpty(&cqueue)) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;

            case 4:
                // IsFull operation
                if (isFull(&cqueue)) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;

            case 5:
                // Traverse operation
                traverse(&cqueue);
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

// Function to initialize the circular queue
void initializeQueue(struct CircularQueue* cq) {
    cq->front = cq->rear = -1;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* cq) {
    return cq->front == -1;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* cq) {
    return (cq->rear + 1) % MAX_SIZE == cq->front;
}

// Function to perform enqueue operation
void enqueue(struct CircularQueue* cq, int element) {
    if (isEmpty(cq)) {
        cq->front = cq->rear = 0;
    } else {
        cq->rear = (cq->rear + 1) % MAX_SIZE;
    }
    cq->array[cq->rear] = element;
}

// Function to perform dequeue operation
int dequeue(struct CircularQueue* cq) {
    int element = cq->array[cq->front];

    if (cq->front == cq->rear) {
        // Last element in the queue
        initializeQueue(cq);
    } else {
        cq->front = (cq->front + 1) % MAX_SIZE;
    }

    return element;
}

// Function to traverse and display the elements of the circular queue
void traverse(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty\n");
    } else {
        int i = cq->front;
        printf("CQueue: ");
        do {
            printf("%d ", cq->array[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (cq->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}
