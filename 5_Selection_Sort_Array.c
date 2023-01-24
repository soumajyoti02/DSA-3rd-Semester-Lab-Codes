Question : Write a program to arrange list of numbers in ascending order using Selection sort algorithms;
===================================================================================================================
  
Algorithm:

---> Define a function selectionSort which takes an integer array and its size as input.
---> Use two nested for loops. The outer loop runs from 0 to n-1 and the inner loop runs from i+1 to n-1
---> In each iteration of outer loop, set minimum index as i
---> Compare each element with the element at minimum index, if the element is smaller than the element at minimum index, set the elements index as new minimum index
---> After inner loop, swap the element at minimum index with the element at i
---> In the main function, take input from the user for the number of elements in the array and store it in the variable 'n'.
---> Use a for loop to take input from the user for the elements of the array and store them in the array
---> Call the selectionSort function with the array and its size as input
---> Print the sorted array

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
The function selectionSort uses the selection sort algorithm to sort the input array. The outer loop runs from 0 to n-1 and the inner loop runs from i+1 to n-1;
The inner loop compares each element with the element at the minimum index, if the element is smaller than the element at minimum index;
set the elements index as new minimum index. After inner loop, swap the element at minimum index with the element at i.

In the main function, we take input from the user for the number of elements in the array and use a for loop to take input from the user for the elements of the array.
Then we call the selectionSort function with the array and its size as input and print the sorted array.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Code Below :::
---------------------------------------------------------------------------------------------------------------
  
#include <stdio.h>

// function to sort an array using selection sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    // outer loop runs from 0 to n-1
    for (i = 0; i < n-1; i++) {
        // initialize the minimum index as i
        minIndex = i;
        // inner loop runs from i+1 to n-1
        for (j = i+1; j < n; j++) {
            // if the current element is smaller than the element at minimum index
            if (arr[j] < arr[minIndex]) {
                // set the current element's index as new minimum index
                minIndex = j;
            }
        }
        // swap the element at minimum index with the element at i
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
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

    // call the selectionSort function with the array and its size as input
    selectionSort(arr, n);

    // print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
