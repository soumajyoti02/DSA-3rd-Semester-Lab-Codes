Question : Search an element from array using Binary search method;
=========================================================================
  
Binary Search Algorithm: The basic steps to perform Binary Search are:

---> Sort the array in ascending order.
---> Set the low index to the first element of the array and the high index to the last element.
---> Set the middle index to the average of the low and high indices.
---> If the element at the middle index is the target element, return the middle index.
---> If the target element is less than the element at the middle index, set the high index to the middle index – 1.
---> If the target element is greater than the element at the middle index, set the low index to the middle index + 1.
---> Repeat steps 3-6 until the element is found or it is clear that the element is not present in the array;


Code Below ::::::::
--------------------------------------------------------------------------
  
#include<stdio.h>
 
int linearSearch(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
 
int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    // Keep searching until low <= high
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    } 
    return -1;
    
}
 
int main(){
    // Unsorted array for linear search
    // int arr[] = {1,3,5,56,4,3,23,5,4,54634,56,34};
    // int size = sizeof(arr)/sizeof(int);
 
    // Sorted array for binary search
    int arr[] = {1,3,5,56,64,73,123,225,444};
    int size = sizeof(arr)/sizeof(int);
    int element = 444;
    int searchIndex = binarySearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);
    return 0;
}



