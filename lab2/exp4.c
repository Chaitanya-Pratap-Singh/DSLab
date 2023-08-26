#include <stdio.h>
#include <stdlib.h>

struct SparseMatrix {
    int rows;
    int cols;
    int numNonZero;
    int** values;
};

struct Tuple {
    int row;
    int col;
    int value;
};

void convertToTuple(struct SparseMatrix matrix, struct Tuple* tupleArray) {
    int currentIndex = 0;

    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            if (matrix.values[i][j] != 0) {
                tupleArray[currentIndex].row = i;
                tupleArray[currentIndex].col = j;
                tupleArray[currentIndex].value = matrix.values[i][j];
                currentIndex++;
            }
        }
    }
}

int main() {
    struct SparseMatrix sparseMatrix;
    sparseMatrix.rows = 4;
    sparseMatrix.cols = 5;
    sparseMatrix.numNonZero = 4;

    // Allocate memory for the values array
    sparseMatrix.values = (int**)malloc(sparseMatrix.rows * sizeof(int*));
    for (int i = 0; i < sparseMatrix.rows; i++) {
        sparseMatrix.values[i] = (int*)malloc(sparseMatrix.cols * sizeof(int));
    }

    // Initialize the sparse matrix (example)
    sparseMatrix.values[0][4] = 5;
    sparseMatrix.values[1][1] = 2;
    sparseMatrix.values[2][2] = 9;

    // Convert sparse matrix to tuple format
    struct Tuple* tupleArray = (struct Tuple*)malloc(sparseMatrix.numNonZero * sizeof(struct Tuple));
    convertToTuple(sparseMatrix, tupleArray);

    // Display the tuple format
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < sparseMatrix.numNonZero; i++) {
        printf("%d\t%d\t%d\n", tupleArray[i].row, tupleArray[i].col, tupleArray[i].value);
    }

    // Free allocated memory
    for (int i = 0; i < sparseMatrix.rows; i++) {
        free(sparseMatrix.values[i]);
    }
    free(sparseMatrix.values);
    free(tupleArray);

    return 0;
}
