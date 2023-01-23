Question : Write a program to arrange list of numbers in ascending order using Bubble sort algorithms;
===========================================================================================================
  
Algorithm:

---> Define a function bubbleSort which takes an integer array and its size as input.
---> Use two nested for loops. The outer loop runs from 0 to n-2 and the inner loop runs from 0 to n-i-1.
---> Compare the current element with the next element. If the current element is greater than the next element, swap them.
---> In the main function, take input from the user for the number of elements in the array and store it in the variable 'n'.
---> Use a for loop to take input from the user for the elements of the array and store them in the array
---> Call the bubbleSort function with the array and its size as input
---> Print the sorted array;


Code Below:::::::::
-----------------------------------------------------------------------------------------------------------
  
  
#include <stdio.h>

// function to sort an array using bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}





