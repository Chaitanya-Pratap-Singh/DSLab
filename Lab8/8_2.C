#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct PriorityQueue {
    struct Node* front;
};

struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

struct PriorityQueue* initializeQueue() {
    struct PriorityQueue* priorityQueue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    if (priorityQueue == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    priorityQueue->front = NULL;
    return priorityQueue;
}

void enqueue(struct PriorityQueue* queue, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    if (queue->front == NULL || priority > queue->front->priority) {
        newNode->next = queue->front;
        queue->front = newNode;
    } else {
        struct Node* current = queue->front;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    printf("%d enqueued with priority %d\n", data, priority);
}

int dequeue(struct PriorityQueue* queue) {
    if (queue->front == NULL) {
        printf("Priority Queue is empty.\n");
        return -1;
    } else {
        int data = queue->front->data;
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        return data;
    }
}

void traverse(struct PriorityQueue* queue) {
    if (queue->front == NULL) {
        printf("Priority Queue is empty.\n");
    } else {
        struct Node* current = queue->front;
        while (current != NULL) {
            printf("Data: %d, Priority: %d\n", current->data, current->priority);
            current = current->next;
        }
    }
}

int main() {
    struct PriorityQueue* priorityQueue = initializeQueue();
    int choice, data, priority;

    while (1) {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Quit\n");

        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(priorityQueue, data, priority);
                break;
            case 2:
                data = dequeue(priorityQueue);
                if (data != -1) {
                    printf("%d dequeued\n", data);
                }
                break;
            case 3:
                printf("Priority Queue:\n");
                traverse(priorityQueue);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}
