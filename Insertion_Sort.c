Question : Write a program to arrange list of numbers in ascending order using Insertion sort algorithms;
=================================================================================================================
  
Algorithm:

---> Define a function insertionSort which takes an integer array and its size as input.
---> Use one outer loop and one inner loop. The outer loop runs from 1 to n-1 and the inner loop runs from i-1 to 0
---> In each iteration of outer loop, store the current element in a variable key
---> compare each element of the array with the key, starting from i-1, if the element is greater than key, move the element one position ahead of its current position.
---> Insert the key at its correct position in the array
---> In the main function, take input from the user for the number of elements in the array and store it in the variable 'n'.
---> Use a for loop to take input from the user for the elements of the array and store them in the array
---> Call the insertionSort function with the array and its size as input
---> Print the sorted array

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
The function insertionSort uses the insertion sort algorithm to sort the input array. The outer loop runs from 1 to n-1 and the inner loop runs from i-1 to 0;
The inner loop compares each element of the array with the key, starting from i-1. If the element is greater than key, move the element one position ahead of its
current position. Then, Insert the key at its correct position in the array.

In the main function, we take input from the user for the number of elements in the array and use a for loop to take input from the user for the elements of the array.
Then we call the insertionSort function with the array and its size as input and print the sorted array.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Code Below :::
------------------------------------------------------------------
  
#include <stdio.h>

// function to sort an array using insertion sort
void insertionSort(int arr[], int n) {
    int i, j, key;
    // outer loop runs from 1 to n-1
    for (i = 1; i < n; i++) {
        // store the current element in the variable key
        key = arr[i];
        j = i-1;
        /* Move elements of arr[0..i-1], that are greater than key, 
        to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        // insert the key at its correct position in the array
        arr[j+1] = key;
    }
}

int main() {
    int n, i;
    // take input from the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    // take input from the user for the elements of the array
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // call the insertionSort function with the array and its size as input
    insertionSort(arr, n);

    // print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}


