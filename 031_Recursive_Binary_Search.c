Question : Write a program to implement recursive binary search;
===============================================================================
  
Algorithm:

1.  Take the input of array, leftmost index, rightmost index, and element to be searched
2.  Create a function binarySearch that takes in array, leftmost index, rightmost index, and element to be searched as arguments
3.  Inside the function, check the base case: if rightmost index is greater than or equal to leftmost index
4.  If base case is true, calculate the middle index as (leftmost index + (rightmost index - leftmost index) / 2)
5.  Compare the element at the middle index with the element to be searched
6.  If the element at the middle index is equal to the element to be searched, return the middle index

7.  If the element at the middle index is greater than the element to be searched, call the binarySearch function again with leftmost index, middle index - 1 and 
    element to be searched as arguments
    
8.  If the element at the middle index is smaller than the element to be searched, call the binarySearch function again with middle index + 1, rightmost index 
    and element to be searched as arguments
    
9.  If the base case is false, return -1 as the element is not present in the array
10. In the main function, take input for the number of elements in the array, the elements themselves and the element to be searched
11. Call the binarySearch function with the array, leftmost index (0), rightmost index (n-1) and the element to be searched as arguments
12. Print the result, if the result is -1, the element is not present in the array, else the element is present at the index returned by the function



Code Below:::
-----------------------------------------------------------------------------------------------------------------------------------------
  
  
#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x) {
  // Base case: element not found
  if (r >= l) {
    int mid = l + (r - l) / 2;
    // If the element is present at the middle
    if (arr[mid] == x)
      return mid;
    // If the element is smaller than mid, it can only be present in left
    // subarray
    if (arr[mid] > x)
      return binarySearch(arr, l, mid - 1, x);
    // Else the element can only be present in right subarray
    return binarySearch(arr, mid + 1, r, x);
  }
  // Element is not present in array
  return -1;
}

int main(void) {
  int n;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int x;
  printf("Enter the element to be searched: ");
  scanf("%d", &x);
  int result = binarySearch(arr, 0, n - 1, x);
  (result == -1) ? printf("Element is not present in array")
                 : printf("Element is present at index %d", result);
  return 0;
}




