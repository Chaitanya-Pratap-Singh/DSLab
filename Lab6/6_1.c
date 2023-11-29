#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Define the stack structure
struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
bool isFull(struct Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push element %d\n", element);
    } else {
        stack->data[++stack->top] = element;
        printf("Pushed %d onto the stack\n", element);
    }
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


int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));
    printf("all elements of the stack\n");
    printStack(&stack);

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Is the stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");
    printf("Is the stack full? %s\n", isFull(&stack) ? "Yes" : "No");


    return 0;
}
