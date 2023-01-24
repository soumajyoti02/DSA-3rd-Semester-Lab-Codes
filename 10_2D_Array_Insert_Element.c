Question : Write a program to insert elements in a 2D array and display the elements.
============================================================================================
Algorithm:

---> The program declares a 2D array of size 3x3 and initializes the number of rows and columns to 3.
  
---> The program defines two functions, one to insert an element into a specific position in the 2D array and one to display the elements of the 2D array.
  
---> The main function prompts the user to enter the elements of the 2D array.
  
---> The insertElement function takes the 2D array, number of rows, number of columns, the element to be inserted, the x and y position as input and insert the
    element into the specific position if it is a valid position, otherwise it will print an error message.
      
---> The displayElements function takes the 2D array, number of rows and number of columns as input and displays the elements of the 2D array.
      
---> The main function displays the original 2D array, prompts the user to enter the element and position to insert it, and call the insertElement function to 
    insert the element at the specified position, then it will display the 2D array after insertion;


Code Below :::
-----------------------------------------------------------------------------------------------
  
  
#include <stdio.h>

// function to insert an element into a specific position in the 2D array
void insertElement(int array[][3], int row, int col, int element, int x, int y) {
    if (x < 0 || x >= row || y < 0 || y >= col) {
        printf("Invalid position\n");
    } else {
        array[x][y] = element;
        printf("Element %d inserted at position (%d, %d)\n", element, x, y);
    }
}

// function to display the elements of the 2D array
void displayElements(int array[][3], int row, int col) {
    int i, j;
    printf("The elements of the 2D array are:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int array[3][3];
    int row = 3, col = 3;
    int element = 0, x = 0, y = 0;
    int i, j;

    printf("Enter the elements of the 2D array:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    printf("Original 2D array:\n");
    displayElements(array, row, col);

    // insert an element at user defined position
    printf("Enter the element you want to insert: ");
    scanf("%d", &element);
    printf("Enter the position (x y) where you want to insert the element: ");
    scanf("%d %d", &x, &y);
    insertElement(array, row, col, element, x, y);

    printf("\n2D array after insertion:\n");
    displayElements(array, row, col);

    return 0;
}

      
