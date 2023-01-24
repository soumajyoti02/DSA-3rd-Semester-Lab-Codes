Question : Write a program to take a 2D matrix as an input, map it to 1D array and display it.
===================================================================================================
  
Algorithm:

---> Take input for the number of rows and columns of the matrix.
---> Take input for the elements of the matrix.
---> Create a 1D array of size rows*columns.
---> Iterate through the 2D matrix, and for each element, store it in the corresponding index of the 1D array.
---> Display the 1D array;

Code Below :::
-----------------------------------------------------------
  
#include <stdio.h>

/*
    Function to map a 2D matrix to a 1D array.
    It takes a 2D matrix and its dimensions as inputs,
    and stores the elements of the matrix in a 1D array.
*/
void map_2d_to_1d(int matrix[][100], int rows, int cols, int array[]) {
    // Initialize index for 1D array
    int array_index = 0;
    // Iterate through the 2D matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Store the current element in the 1D array
            array[array_index] = matrix[i][j];
            // increment the index for the 1D array
            array_index++;
        }
    }
}

int main() {
    //Take user inputs for number of rows and columns of the matrix
    int matrix_rows, matrix_cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &matrix_rows, &matrix_cols);

    //Take user input for the elements of the matrix
    int matrix[matrix_rows][matrix_cols];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < matrix_rows; i++) {
        for (int j = 0; j < matrix_cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    // Create 1D array of size matrix_rows*matrix_cols
    int array[matrix_rows * matrix_cols];
    // Map the 2D matrix to the 1D array
    map_2d_to_1d(matrix, matrix_rows, matrix_cols, array);
    printf("The 1D array: ");
    for (int i = 0; i < matrix_rows*matrix_cols; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
