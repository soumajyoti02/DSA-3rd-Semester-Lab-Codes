Question : Write a program to implement quick sort.
====================================================================

Algorithm:

---> Start the main function
---> Take user input for the number of elements in the array
---> Allocate memory for the array using malloc
---> Take user input for the elements of the array
---> Print the original array using the printArray function
---> Sort the array using the quicksort function, passing in the array, the low index (0), and the high index (size-1)
---> Print the sorted array using the printArray function
---> Free the allocated memory using the free function
---> End the main function

Algorithm for the quicksort function:

---> Quicksort(arr, low, high):

---> If the subarray has more than one element:
---> partition the subarray
---> sort the left subarray (elements less than pivot)
---> sort the right subarray (elements greater than pivot)
---> repeat steps 1-4 for each partitioned subarray until the entire array is sorted.
  
Algorithm for partition function:

--> partition(arr, low, high)

---> Set pivot element as the first element of the subarray
---> Initialize two pointers i and j, i is pointing to the next element after pivot, j is pointing to the last element of the subarray
---> Compare elements at i and j, if i is less than pivot and j is greater than pivot, swap them
---> Repeat step 3 until i and j cross each other
---> Swap pivot element with the element at j
---> Return the index of the pivot element in the partitioned array




Code Below:::
--------------------------------------------------------------------------------------------------------------------------------------------
  
  
#include <stdio.h>
#include <stdlib.h>

// Function to print the elements of an array
void printArray(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Partition function to partition the array around a pivot element
int partition(int *arr, int low, int high) {
    int pivot = arr[low]; // pivot element is the first element of the array
    int i = low + 1; // pointer i starts just after the pivot element
    int j = high; // pointer j starts at the end of the array
    int temp;

    // Do partition
    do {
        // increment i until an element greater than pivot is found
        while (arr[i] <= pivot) {
            i++;
        }
        // decrement j until an element less than or equal to pivot is found
        while (arr[j] > pivot) {
            j--;
        }
        // if pointers i and j have not crossed, swap elements at i and j
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    // Swap pivot element with element at final position of j
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
    }
// Quicksort function to sort the array
void quickSort(int *arr, int low, int high) {
    int partitionIndex; // Index of pivot after partition

    // If the subarray has more than one element, partition and sort
    if (low < high) {
        partitionIndex = partition(arr, low, high); 
        // sort left subarray (elements less than pivot)
        quickSort(arr, low, partitionIndex - 1);  
        // sort right subarray (elements greater than pivot)
        quickSort(arr, partitionIndex + 1, high); 
    }
}

int main() {
    int size, i;
    int *arr;
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &size);
    arr = (int*)malloc(sizeof(int)*size);
    printf("Enter the elements: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Original Array: ");
    printArray(arr, size);
    quickSort(arr, 0, size - 1); // sort the entire array
    printf("Sorted Array: ");
    printArray(arr, size);
    free(arr);
    return 0;
}
