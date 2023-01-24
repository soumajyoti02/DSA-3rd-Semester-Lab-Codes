Question : Write a program to reverse a string using stack;
==========================================================================
  
Algorithm:

---> Define a stack structure and typedef it
---> Create a function named "createStack" which takes an integer parameter and returns stack pointer
--->allocate memory for stack and it's data pointer using malloc
--->initialize stack's top with -1 and size with the given parameter
--->return the stack pointer
---> Create a function named "isEmpty" which takes stack pointer as parameter and returns boolean
---> return true if top of stack is -1 else return false
---> Create a function named "isFull" which takes stack pointer as parameter and returns boolean
---> return true if top of stack is equal to size-1 else return false
---> Create a function named "push" which takes stack pointer and a character as parameter
---> check if stack is full, if yes return error
---> Else increment top and insert the given character to the top of stack
---> Create a function named "pop" which takes stack pointer as parameter and returns character
---> check if stack is empty, if yes return error
---> Else decrement top and return the element at top
---> Create a function named "reverse" which takes an array of characters as parameter
---> Create a stack
---> Then, the function loops through the given string, pushing each character onto the stack
---> Next, the function loops through the string again, popping each character off the stack and assigning it to the corresponding index in the original string
---> In the main function, the user is prompted to enter a string, which is then passed to the "reverse" function to reverse it
---> The reversed string is then printed out;


Code Below :::
------------------------------------------------------------------------------
  
  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack {
    char *data;
    int top;
    int size;
} stack;

// Function to create stack
stack* createStack(int size)
{
    stack* s = (stack*)malloc(sizeof(stack));
    s->size = size;
    s->top = -1;
    s->data = (char*)malloc(s->size * sizeof(char));
    return s;
}

bool isEmpty(stack* s)
{
    return (s->top == -1);
}

bool isFull(stack* s)
{
    return (s->top == s->size - 1);
}

void push(stack* s, char x)
{
    if (isFull(s))
    {
        printf("Error: Stack Overflow\n");
        return;
    }
    s->data[++s->top] = x;
}

char pop(stack* s)
{
    if (isEmpty(s))
    {
        printf("Error: Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

void reverse(char str[])
{
    int n = strlen(str);
    stack* s = createStack(n);
    for (int i = 0; i < n; i++)
        push(s, str[i]);
    for (int i = 0; i < n; i++)
        str[i] = pop(s);
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    reverse(str);
    printf("Reversed string is: %s\n", str);
    return 0;
}


