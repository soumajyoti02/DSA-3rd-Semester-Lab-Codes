Question : Write a program to check a matrix is upper triangular matrix or not;
=======================================================================================
  
Algorithm:

---> Take input for the number of rows and columns of the matrix.
---> Take input for the elements of the matrix.
---> Iterate through the matrix, starting from the second row, and for each element, check if it is zero or not.
---> If any element below the main diagonal is not zero, return false, else return true
---> If the returned value is true, print the matrix is upper triangular, otherwise print the matrix is not upper triangular;

Code Below ::::
---------------------------------------------------
  
#include <stdio.h>
#include <stdbool.h>

/*
    Function to check whether a given matrix is upper triangular or not.
    An upper triangular matrix is a matrix in which all the elements below the main diagonal are zero.
    So, we check if all the elements below the main diagonal are zero, then the matrix is upper triangular.
*/
bool is_upper_triangular(int matrix[][100], int rows, int cols) {
    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int matrix_rows, matrix_cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &matrix_rows, &matrix_cols);

    int matrix[matrix_rows][matrix_cols];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < matrix_rows; i++) {
        for (int j = 0; j < matrix_cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (is_upper_triangular(matrix, matrix_rows, matrix_cols)) {
        printf("The matrix is upper triangular\n");
    } else {
        printf("The matrix is not upper triangular\n");
    }
    return 0;
}


