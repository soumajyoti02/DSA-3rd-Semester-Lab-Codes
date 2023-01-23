Question : Search an element from array using linear search method;
==========================================================================
  
Algorithm:

---> Define a function linearSearch which takes an integer array, its size and the element to be searched as input
---> Use a for loop to iterate through the array, starting from the first element
---> In each iteration, check if the current element is the element to be searched.
---> If it is, return the index of the current element
---> If the element is not found in the array, return -1
---> In the main function, take input from the user for the number of elements in the array and store it in the variable 'n'
---> Use a for loop to take input from the user for the elements of the array and store them in the array
---> Take input from the user for the element to be searched and store it in the variable 'x'
---> Call the linearSearch function to search for the element in the array
---> Check if the element is found in the array and print the appropriate message;

Code Below :::
----------------------------------------------------------------------------
  
#include <stdio.h>

// function to search for an element in an array using linear search
int linearSearch(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        // check if the current element is the element to be searched
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, x, i;
    // take input from the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    // take input from the user for the elements of the array
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    // take input from the user for the element to be searched
    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    // call the linearSearch function to search for the element in the array
    int result = linearSearch(arr, n, x);

    // check if the element is found in the array
    if (result == -1) {
        printf("Element is not present in the array.");
    } else {
        printf("Element is present at index %d.", result);
    }
    return 0;
}


