Question : Write a program to implement heap sort;
========================================================================
  
Algorithm :

---> Create a function heapify to heapify a subtree rooted at a given index
----> Initialize the largest variable as the given index
----> Calculate the left and right child indices
----> Compare the left and right children with the root (largest) and update largest
----> if the largest is not the root, swap the root with the largest and recursively heapify the affected subtree

---> Create a function heapSort to perform the heap sort
----> In the first for loop, starting from n/2-1, call heapify for each subtree of the array
----> In the second for loop, starting from n-1, swap the root with the last element and call heapify on the reduced heap

---> In the main function, take the number of elements in the array as input
---> Allocate memory for the array using malloc
---> Take the elements of the array as input
---> Call the heapSort function
---> Print the sorted array
---> Free the memory allocated for the array;



Code Below::::
------------------------------------------------------------------------
  
  
#include <stdio.h>
#include <stdlib.h>

/* function to swap two elements in an array */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* function to heapify a subtree rooted at index i */
void heapify(int arr[], int n, int i) {
    int largest = i;  /* initialize largest as root */
    int left = 2*i + 1;  /* left child index */
    int right = 2*i + 2;  /* right child index */

    /* if left child is larger than root */
    if (left < n && arr[left] > arr[largest])
        largest = left;

    /* if right child is larger than largest so far */
    if (right < n && arr[right] > arr[largest])
        largest = right;

    /* if largest is not root */
    if (largest != i) {
        swap(&arr[i], &arr[largest]);  /* swap root with largest */
        heapify(arr, n, largest);  /* recursively heapify the affected sub-tree */
    }
}

/* function to perform heap sort */
void heapSort(int arr[], int n) {
    int i;

    /* build heap (rearrange array) */
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    /* extract element from heap one by one */
    for (i = n-1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);  /* move current root to end */
        heapify(arr, i, 0);  /* call max heapify on the reduced heap */
    }
}

/* main function to test the program */
int main() {
    int n;  /* number of elements in the array */
    int *arr; /* pointer to the array */
    int i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    /*allocate memory for the array*/
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    heapSort(arr, n);  /* call heap sort function */
    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    /*free memory allocated for the array*/
    free(arr);
    return 0;
}




