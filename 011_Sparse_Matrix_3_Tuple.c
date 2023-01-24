Question : Write a program to test a given matrix is sparse or not. If it is sparse then represent it as 3-tuple format.
=============================================================================================================================

Algorithm:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--> Take input for the dimensions of the matrix (n m).
  
--> Take input for the matrix elements.
  
--> Initialize a variable non_zero_count to zero.
  
--> Iterate through the matrix and for each non-zero element, increment the non_zero_count variable.
  
--> Check if non_zero_count is greater than (n*m)/2. If yes, then the matrix is not sparse. Else, the matrix is sparse.
  
--> If the matrix is sparse, then create a new array called tuple_matrix with size non_zero_count * 3 to store the 3-tuple representation of the matrix.
  
--> Create a variable tuple_index and initialize it to zero.
  
--> Iterate through the matrix and for each non-zero element, store it in the tuple_matrix as a 3-tuple (i, j, matrix[i][j]) and increment the tuple_index variable.
  
--> Print the 3-tuple matrix by iterating through the tuple_matrix and printing the tuple (tuple_matrix[i][0], tuple_matrix[i][1], tuple_matrix[i][2]) for
    each i in range of non_zero_count.
  
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
Code Below :::
------------------------------------------------------------
  
#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int n, m; // dimensions of the matrix
    int matrix[MAX_SIZE][MAX_SIZE]; // the matrix
    int non_zero_count = 0; // count of non-zero elements in the matrix

    // take input for the dimensions of the matrix
    printf("Enter the dimensions of the matrix (n m): ");
    scanf("%d %d", &n, &m);

    // take input for the matrix
    printf("Enter the elements of the matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) {
                non_zero_count++;
            }
        }
    }

    // check if the matrix is sparse
    if (non_zero_count > (n * m) / 2) {
        printf("The matrix is not sparse.\n");
    } else {
        printf("The matrix is sparse.\n");
        int tuple_matrix[non_zero_count][3]; // array to store the 3-tuple representation
        int tuple_index = 0; // index for the tuple_matrix

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] != 0) {
                    tuple_matrix[tuple_index][0] = i;
                    tuple_matrix[tuple_index][1] = j;
                    tuple_matrix[tuple_index][2] = matrix[i][j];
                    tuple_index++;
                }
            }
        }

        // print the 3-tuple matrix
        printf("3-tuple representation: \n");
        for (int i = 0; i < non_zero_count; i++) {
            printf("(%d, %d, %d)\n", tuple_matrix[i][0], tuple_matrix[i][1], tuple_matrix[i][2]);
        }
    }

    return 0;
}
