#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a stack structure
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Stack operations
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';  // '$' is used to indicate an empty stack
}

// Function to check if a character is an operand
int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, j;
    
    for (i = 0, j = 0; infix[i]; ++i) {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            push(stack, infix[i]);
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                postfix[j++] = pop(stack);
            pop(stack);  // Pop the '('
        } else {
            while (!isEmpty(stack) && getPrecedence(infix[i]) <= getPrecedence(peek(stack)))
                postfix[j++] = pop(stack);
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack))
        postfix[j++] = pop(stack);

    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
