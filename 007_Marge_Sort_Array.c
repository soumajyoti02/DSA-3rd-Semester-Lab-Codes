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

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergeSort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    mergeSort(A, 0, 6);
    printArray(A, n);
    return 0;
}






