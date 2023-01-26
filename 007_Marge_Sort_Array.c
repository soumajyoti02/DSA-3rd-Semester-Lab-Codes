Question : Write a program to implement merge sort;
===========================================================
  
---Algorithm---

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
--->1. Get the number of elements in the array from the user
--->2. Allocate memory for the array
--->3. Get elements from the user
--->4. Call the mergeSort function with the array, left index, and right index as arguments

--- mergeSort function ---

--->1. Check if the left index is less than the right index. If not, return.
--->2. Find the middle index of the current subarray by adding the left index and right index and dividing by 2.
--->3. Recursively call the mergeSort function with the left half of the subarray, from the left index to the middle index
--->4. Recursively call the mergeSort function with the right half of the subarray, from the middle index + 1 to the right index
--->5. Call the merge function with the array, left index, middle index, and right index as arguments

--- merge function ---

--->1. Initialize variables i, j, and k to 0
--->2. Allocate memory for two temporary arrays, leftArr and rightArr, to store the left and right halves of the subarray
--->3. Copy elements from the original array to leftArr and rightArr
--->4. Compare the first element of leftArr and rightArr, and put the smaller element into the original array
--->5. Increment the index of the temporary array from which the element was taken, and the index of the original array
--->6. Repeat step 4 until one of the temporary arrays is fully merged
--->7. Copy the remaining elements of the non-empty temporary array into the original array
--->8. Free the allocated memory
--->9. Return to the mergeSort function

--- main function ---

--->1. Print the sorted array
--->2. Free the allocated memory
--->3. Exit the program


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Code Below :::
-----------------------------------------------------------------------------------------------------------------------------------------
  
  
#include <stdio.h>
#include <stdlib.h>

/*
    This function takes in the original array, left and right indices of the subarray,
    and merges the subarray in a sorted manner.
*/
void merge(int *arr, int leftIdx, int middleIdx, int rightIdx) {
    // Initialize variables
    int i, j, k;
    int leftArrSize = middleIdx - leftIdx + 1;
    int rightArrSize = rightIdx - middleIdx;

    // Create temporary arrays to store left and right subarrays
    int *leftArr = (int*)malloc(leftArrSize * sizeof(int));
    int *rightArr = (int*)malloc(rightArrSize * sizeof(int));

    // Copy elements from original array to left and right subarrays
    for (i = 0; i < leftArrSize; i++) {
        leftArr[i] = arr[leftIdx + i];
    }
    for (j = 0; j < rightArrSize; j++) {
        rightArr[j] = arr[middleIdx + 1 + j];
    }

    // Merge the temp arrays back into arr[leftIdx..rightIdx]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = leftIdx; // Initial index of merged subarray
    while (i < leftArrSize && j < rightArrSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr, if there are any
    while (i < leftArrSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr, if there are any
    while (j < rightArrSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Free the allocated memory
    free(leftArr);
    free(rightArr);
}

/*
    This function takes in the original array, left and right indices of the subarray,
    and sorts the subarray using the merge sort algorithm.
*/
void mergeSort(int *arr, int leftIdx, int rightIdx) {
    if (leftIdx < rightIdx) {
        // Find the middle point
        int middleIdx = leftIdx + (rightIdx - leftIdx) / 2;

        // Sort first and second halves
        mergeSort(arr, leftIdx, middleIdx);
        mergeSort(arr, middleIdx + 1, rightIdx);

        // Merge the sorted halves
        merge(arr, leftIdx, middleIdx, rightIdx);
    }
}

int main() {
    int numElements;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &numElements);

    // Create an array of user-specified size
    int *arr = (int*)malloc(numElements * sizeof(int));

    // Get elements from user
    printf("Enter %d elements: ", numElements);
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform merge sort on the array
    mergeSort(arr, 0, numElements - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < numElements; i++) {
        printf("%d ", arr[i]);
    }

    // Free the allocated memory
    free(arr);
    return 0;
}






