Question : Write a program using structure to implement stack operations using switch case (push, pop, top, display);
========================================================================================================================
  
Algorithn :

---> Declare a stack structure and typedef it
---> Create a function named "createStack" which takes an integer parameter and returns stack pointer
--->allocate memory for stack and it's data pointer using malloc
--->initialize stack's top with -1 and size with the given parameter
--->return the stack pointer
---> Create a function named "isEmpty" which takes stack pointer as parameter and returns boolean
---> return true if top of stack is -1 else return false
---> Create a function named "isFull" which takes stack pointer as parameter and returns boolean
---> return true if top of stack is equal to size-1 else return false
---> Create a function named "push" which takes stack pointer and an integer as parameter
---> check if stack is full, if yes return error
---> Else increment top and insert the given integer to the top of stack
---> Create a function named "pop" which takes stack pointer as parameter and returns integer
---> check if stack is empty, if yes return error
---> Else decrement top and return the element at top
---> Create a function named "top" which takes stack pointer as parameter and returns integer
---> check if stack is empty, if yes return error
---> Else return the element at top
---> Create a function named "display" which takes stack pointer as parameter
---> check if stack is empty, if yes return error
---> Else print all element from top to bottom
---> In main function, take size of stack from user
---> Create stack by calling the createStack function
---> Use a while loop for continuous operation
---> In every iteration of while loop, take choice from user
---> Use switch case to perform the operation according to user choice
---> Exit the program if user chooses to exit



Code Below :::
--------------------------------------------------------------------------------------------------
  
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Define a stack structure
typedef struct stack {
    int *data;
    int top;
    int size;
} stack;

// Function to create stack
stack* createStack(int size)
{
    stack* s = (stack*)malloc(sizeof(stack));
    s->size = size;
    s->top = -1;
    s->data = (int*)malloc(s->size * sizeof(int));
    return s;
}

// Function to check if the stack is empty
bool isEmpty(stack *s) {
    return (s->top == -1);
}

// Function to check if the stack is full
bool isFull(stack *s) {
    return (s->top == s->size - 1);
}

// Function to push an element onto the stack
void push(stack *s, int x) {
    if (isFull(s)) {
        printf("Error: stack overflow\n");
        return;
    }
    s->data[++s->top] = x;
    printf("%d pushed onto stack\n", x);
}

// Function to pop an element from the stack
int pop(stack *s) {
    if (isEmpty(s)) {
        printf("Error: stack underflow\n");
        return -1;
    }
    int x = s->data[s->top--];
    return x;
}

// Function to return the top element of the stack
int top(stack *s) {
    if (isEmpty(s)) {
        printf("Error: stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}

// Function to display the contents of the stack
void display(stack *s) {
    if (isEmpty(s)) {
        printf("Error: stack is empty\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    int size, choice, x;
    // Create stack by taking size from user
    printf("Enter size of stack: ");
    scanf("%d", &size);
    stack* s = createStack(size);
    while (1) {
        printf("\nStack operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Push an element onto the stack
                printf("Enter the element to be pushed: ");
                scanf("%d", &x);
                push(s, x);
                break;
            case 2:
                // Pop an element from the stack
                x = pop(s);
                if(x!=-1)
                    printf("Popped element is %d\n", x);
                break;
            case 3:
                // Display the top element of the stack
                x = top(s);
                if(x!=-1)
                    printf("Top element is %d\n", x);
                break;
            case 4:
                // Display the contents of the stack
                display(s);
                break;
            case 5:
                // Exit the program
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
         
                   
                   
           
                   
                   
