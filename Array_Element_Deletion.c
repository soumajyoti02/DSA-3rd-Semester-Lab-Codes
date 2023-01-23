Question : Write a program to delete an element in array at any position;
============================================================================
  
Algorithm:
---> Start
---> Declare and initialize the array, the size of the array, and the position of the element to be deleted.
---> Shift all elements after the specified position to the left using a loop.
---> Print the original and modified arrays.
---> End
--------------------------------------------------------------------------------------------------
This program creates a function called "delete_at_position" that takes in the array, its size;and the position at which the element should be deleted as arguments;
Inside the function;it shifts all elements after the specified position to the left using a loop. In the main function;
it calls the delete_at_position function and prints the original and modified arrays;


Code Below :::
----------------------------
  
#include <stdio.h>

void delete_at_position(int array[], int size, int position) {
    int i;

    // Shift all elements after the specified position to the left
    for (i = position; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
}

int main() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter the elements of array: ");
    for(int i=0;i<size;i++){
        scanf("%d",&array[i]);
    }

    int position;
    printf("Enter the position of the element to be deleted: ");
    scanf("%d", &position);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    // call the delete_at_position function and pass the array, its size and the position of the element to be deleted
    delete_at_position(array, size, position);

    printf("\nModified array: ");
    for (int i = 0; i < size - 1; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
