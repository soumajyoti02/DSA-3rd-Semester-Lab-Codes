Question : Write a program to store the elements in a 2D array in column major order & display it;
=======================================================================================================
  
Algorithm:

---> Take input from the user for the number of rows and columns of the array
---> Use two nested for loops to take input from the user for the elements of the array. The outer loop runs from 0 to col-1 and the inner loop runs from 0 to row-1
---> Use two nested for loops again to display the array in column major order. The outer loop runs from 0 to col-1 and the inner loop runs from 0 to row-1
  
Code Below :::
------------------------------------------------
  
  
#include <stdio.h>

int main() {
    int row, col;
    // take input from the user for the number of rows and columns of the array
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    int arr[row][col];
    // take input from the user for the elements of the array
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            scanf("%d", &arr[j][i]);
        }
    }

    printf("The array in column major order: \n");
    // display the array in column major order
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }
    return 0;
}


