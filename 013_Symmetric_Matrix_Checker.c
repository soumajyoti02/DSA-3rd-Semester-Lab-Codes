Question : Write a program to check whether a matrix is symmetric or not;
==================================================================================
  
Algorithm:

--> Take user inputs for rows and columns of the matrix.
--> Take user input for the elements of the matrix.
--> Compare matrix[i][j] with matrix[j][i] for all i and j
--> Return true if all element are same, else false.
--> If true, then print the matrix is symmetric else not symmetric;


Code Below :::
--------------------------------------------------------------------------------
  
  
#include <stdio.h>
#include <stdbool.h>

/*
    Function to check whether given matrix is symmetric or not.
    A matrix is symmetric if its transpose is equal to the original matrix.
    So, we check if matrix[i][j] is equal to matrix[j][i] for all i and j.
    If it is true, then the matrix is symmetric.
*/
bool is_matrix_symmetric(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (is_matrix_symmetric(matrix, rows, cols)) {
        printf("The matrix is symmetric\n");
    } else {
        printf("The matrix is not symmetric\n");
    }
    return 0;
}


