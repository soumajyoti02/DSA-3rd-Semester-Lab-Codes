Question : Write a program to insert an element in array at any position.
===========================================================================
Algorithm :
---> Start
---> Declare and initialize the array, the size of the array, the element to be inserted, and the position at which the element should be inserted.
---> Shift all elements after the specified position to the right using a loop.
---> Insert the new element at the specified position in the array.
---> Print the original and modified arrays.
---> End


Code Below :::
----------------------------------------------------------------------------
#include <stdio.h>

void insert_at_position(int array[], int size, int element, int position) {
    int i;

    // Shift all elements after the specified position to the right
    for (i = size - 1; i >= position; i--) {
        array[i + 1] = array[i];
    }

    // Insert the new element at the specified position
    array[position] = element;
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int element = 10;
    int position = 3;

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    insert_at_position(array, size, element, position);

    printf("\nModified array: ");
    for (int i = 0; i < size + 1; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
