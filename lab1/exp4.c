#include <stdio.h>

// Structure to represent a complex number
struct Complex {
    float real;
    float imaginary;
};

// Function to add two complex numbers (call by value)
struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}

// Function to multiply two complex numbers (call by address)
void multiplyComplex(struct Complex *num1, struct Complex *num2, struct Complex *result) {
    result->real = (num1->real * num2->real) - (num1->imaginary * num2->imaginary);
    result->imaginary = (num1->real * num2->imaginary) + (num1->imaginary * num2->real);
}

int main() {
    struct Complex complex1, complex2, result;
    int choice;

    printf("Enter the real and imaginary parts of the first complex number:\n");
    scanf("%f %f", &complex1.real, &complex1.imaginary);

    printf("Enter the real and imaginary parts of the second complex number:\n");
    scanf("%f %f", &complex2.real, &complex2.imaginary);

    printf("Select an operation:\n");
    printf("1. Addition\n");
    printf("2. Multiplication\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = addComplex(complex1, complex2);
            printf("Result of addition: %.2f + %.2fi\n", result.real, result.imaginary);
            break;
        case 2:
            multiplyComplex(&complex1, &complex2, &result);
            printf("Result of multiplication: %.2f + %.2fi\n", result.real, result.imaginary);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}
