Question : Write a Program to multiply 2 matrices. (Elements in the matrix must be taken dynamically.)
===========================================================================================================
  
Algorithm:
--> Take input for the dimensions of the matrices (n m p).
--> Allocate memory for the matrices using dynamic memory allocation.
--> Take input for the elements of the matrices.
--> Initialize a nested loop to iterate through the rows and columns of the result matrix.
--> Within the nested loops, initialize a variable sum to zero.
--> Use another loop to iterate through the columns of the first matrix and rows of the second matrix.
--> Multiply the element at the current position of the first matrix with the element at the current position of the second matrix and add it to sum.
--> Assign the value of sum to the current position of the result matrix.
--> Print the result matrix.
--> Free the dynamically allocated memory using the free() function;


Code Below :::
-------------------------------------------------------------------------------------
  
  
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rowsA, colsA, rowsB, colsB; // dimensions of the matrices
    printf("Enter the dimensions of matrix A (rows columns): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter the dimensions of matrix B (rows columns): ");
    scanf("%d %d", &rowsB, &colsB);
    if(colsA != rowsB) {
        printf("Error: The number of columns of matrix A should be equal to the number of rows of matrix B for multiplication.\n");
        return 1;
    }
    // allocate memory for the matrices using dynamic memory allocation
    int **matrixA = (int**)malloc(rowsA * sizeof(int*));
    for (int i = 0; i < rowsA; i++) {
        matrixA[i] = (int*)malloc(colsA * sizeof(int));
    }
    int **matrixB = (int**)malloc(rowsB * sizeof(int*));
    for (int i = 0; i < rowsB; i++) {
        matrixB[i] = (int*)malloc(colsB * sizeof(int));
    }
    int **result = (int**)malloc(rowsA * sizeof(int*));
    for (int i = 0; i < rowsA; i++) {
        result[i] = (int*)malloc(colsB * sizeof(int));
    }

    // take input for the matrices
    printf("Enter the elements of matrix A: \n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }
    printf("Enter the elements of matrix B: \n");
    for (int i = 0; i < rowsB; j++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    // multiply the matrices
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int sum = 0;
            for (int k = 0; k < colsA; k++) {
                // multiplying row of matrixA with column of matrixB
                sum += matrixA[i][k] * matrixB[k][j];
            }
            result[i][j] = sum;
        }
    }

    // print the result
    printf("Result: \n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    // free the dynamically allocated memory
    for (int i = 0; i < rowsA; i++) {
        free(matrixA[i]);
    }
    free(matrixA);
    for (int i = 0; i < rowsB; i++) {
        free(matrixB[i]);
    }
    free(matrixB);
    for (int i = 0; i < rowsA; i++) {
        free(result[i]);
    }
    free(result);
