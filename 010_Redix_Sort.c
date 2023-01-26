Question : Write a program to implement radix sort;
=========================================================================
  
ALGORITHM:

---> Create a function getMax to find the maximum value in the array
----> Initialize the max variable with the first element of the array
----> Iterate through the array and compare each element with the max variable
----> Update the max variable if a larger element is found
----> Return the max variable

---> Create a function radixSort to perform the radix sort
----> Allocate memory for the output array using malloc
----> Call the getMax function to find the maximum value in the array
----> Perform counting sort for each digit of the maximum value
------> Initialize an array count to store the count of occurrences of each digit
------> Iterate through the input array and store the count of occurrences of each digit in the count array
------> Iterate through the count array and update the values to represent the actual position of each digit in the output array
------> Iterate through the input array in reverse order and place each element in the output array at the corresponding position
------> Copy the output array to the input array
----> Free the memory allocated for the output array

---> In the main function, take the number of elements in the array as input
---> Allocate memory for the array using malloc
---> Take the elements of the array as input
---> Call the radixSort function
---> Print the sorted array
---> Free the memory allocated for the array;



Code Below::::
---------------------------------------------------------------------------------------------------------------------------------------------
  
  
  
  
#include <stdio.h>
#include <stdlib.h>

/* function to get maximum value in array */
int getMax(int arr[], int n) {
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

/* function to perform radix sort */
void radixSort(int arr[], int n) {
    int exp, i;
    int *output = (int *)malloc(n * sizeof(int));
    int max = getMax(arr, n);
    /* Perform counting sort for every digit */
    for (exp = 1; max/exp > 0; exp *= 10) {
        int count[10] = {0};
        /* Store count of occurrences in count[] */
        for (i = 0; i < n; i++)
            count[(arr[i]/exp)%10]++;
        /* Change count[i] so that count[i] now contains actual
        position of this digit in output[] */
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];
        /* Build the output array */
        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i]/exp)%10] - 1] = arr[i];
            count[(arr[i]/exp)%10]--;
        }
        /* Copy the output array to arr[], so that arr[] now
        contains sorted numbers according to current digit */
        for (i = 0; i < n; i++)
            arr[i] = output[i];
    }
    free(output);
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
    radixSort(arr, n);  /* call radix sort function */
    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    /*free memory allocated for the array*/
    free(arr);
    return 0;
}





