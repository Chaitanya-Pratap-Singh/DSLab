#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Define the stack structure
struct Stack {
    struct Node* top;
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push element %d\n", element);
        return;
    }

    newNode->data = element;
    newNode->next = stack->top;
    stack->top = newNode;

    printf("Pushed %d onto the stack\n", element);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop from an empty stack\n");
        return -1; // Return a sentinel value to indicate an error
    }

    struct Node* temp = stack->top;
    int poppedElement = temp->data;
    stack->top = temp->next;
    free(temp);

    return poppedElement;
}

// Function to get the top element of the stack without popping it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek\n");
        return -1; // Return a sentinel value to indicate an error
    }

    return stack->top->data;
}

// Function to print all elements of the stack
void printStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Elements in the stack: ");
    struct Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory used by the stack
void cleanup(struct Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    printStack(&stack);

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printStack(&stack);

    printf("Is the stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");

    // Clean up and free memory
    cleanup(&stack);

    return 0;
}
