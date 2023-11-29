#include <stdio.h>
#include <stdlib.h>

// Define the initial size of the dynamic array
#define INITIAL_SIZE 10

// Define the stack structure
struct Stack {
    int* data;
    int top;
    int capacity;
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->data = (int*)malloc(INITIAL_SIZE * sizeof(int));
    if (stack->data == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    stack->top = -1;
    stack->capacity = INITIAL_SIZE;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return (stack->top == stack->capacity - 1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int element) {
    if (isFull(stack)) {
        // If the stack is full, resize the array
        stack->capacity *= 2;
        stack->data = (int*)realloc(stack->data, stack->capacity * sizeof(int));
        if (stack->data == NULL) {
            fprintf(stderr, "Memory reallocation failed.\n");
            exit(1);
        }
    }

    stack->data[++stack->top] = element;
    printf("Pushed %d onto the stack\n", element);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop from an empty stack\n");
        return -1; // Return a sentinel value to indicate an error
    } else {
        return stack->data[stack->top--];
    }
}

// Function to get the top element of the stack without popping it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek\n");
        return -1; // Return a sentinel value to indicate an error
    } else {
        return stack->data[stack->top];
    }
}

//function to print all the elements of the stack
void printStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Elements in the stack: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->data[i]);
        }
        printf("\n");
    }
}


// Function to free the memory used by the dynamic array and stack
void cleanup(struct Stack* stack) {
    free(stack->data);
    stack->top = -1;
    stack->capacity = 0;
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));
    printf("all elements of the stack :\n");
    printStack(&stack);

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Is the stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");

    // Clean up and free memory
    cleanup(&stack);

    return 0;
}
