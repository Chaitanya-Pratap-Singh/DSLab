#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

struct Complex addComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

void multiplyComplex(struct Complex *c1, struct Complex *c2) {
    float real = c1->real * c2->real - c1->imaginary * c2->imaginary;
    float imaginary = c1->real * c2->imaginary + c1->imaginary * c2->real;
    c1->real = real;
    c1->imaginary = imaginary;
}

int main() {
    struct Complex complex1, complex2, result;
    int choice;

    printf("Enter real and imaginary parts of the first complex number:\n");
    scanf("%f %f", &complex1.real, &complex1.imaginary);

    printf("Enter real and imaginary parts of the second complex number:\n");
    scanf("%f %f", &complex2.real, &complex2.imaginary);

    printf("Choose an operation:\n");
    printf("1. Addition of two complex numbers\n");
    printf("2. Multiplication of two complex numbers\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = addComplex(complex1, complex2);
            printf("Result of addition: %.2f + %.2fi\n", result.real, result.imaginary);
            break;
        case 2:
            multiplyComplex(&complex1, &complex2);
            printf("Result of multiplication: %.2f + %.2fi\n", complex1.real, complex1.imaginary);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
