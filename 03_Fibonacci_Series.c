Question : Write a program to generate Fibonacci series using function;
===========================================================================
  
Algorithm:

---> Define a function fibonacci which takes an integer n as input.
---> If the input value is less than or equal to 0, return 0.
---> If the input value is 1, return 1.
---> Else, return fibonacci(n-1) + fibonacci(n-2).
---> In the main function, take input from the user for the number of terms in the series and store it in the variable 'n'.
---> Use a for loop to iterate from 0 to n-1 and in each iteration, call the fibonacci function with the loop variable as the input and print the output;


Code Below :::::
-----------------------------------------------------
  
#include <stdio.h>

// function to generate and return the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci series: ");

    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    return 0;
}
