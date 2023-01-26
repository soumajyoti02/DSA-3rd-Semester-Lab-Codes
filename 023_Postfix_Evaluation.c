Question : Write a program to evaluate the given postfix expression.
==============================================================================
  
Algorithm:

---> Create a stack
---> Scan through the postfix expression
---> If the scanned character is an operand, push it to the stack
---> If the scanned character is an operator, pop two elements from the stack, perform the operation and push the result back to the stack
---> Repeat steps 3 and 4 until all characters are scanned
---> The result will be the top element of the stack
---> Return the result;


Code Below :::
------------------------------------------------------------------------------
  
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a stack structure
typedef struct stack {
    int top;
    int capacity;
    int *array;
} Stack;

// function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// function to push an element to the stack
void push(Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

// function to evaluate postfix expression
int evaluatePostfix(char* exp) {
    // create a stack
    Stack* stack = createStack(strlen(exp));

    // scan through the expression
    for (int i = 0; exp[i]; i++) {
        // if the scanned character is an operand, push it to the stack
        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');
        // if the scanned character is an operator, pop two elements from the stack, perform the operation and push the result back to the stack
        else {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i]) {
                case '+': push(stack, val2 + val1); break;
                case '-': push(stack, val2 - val1); break;
                case '*': push(stack, val2 * val1); break;
                case '/': push(stack, val2 / val1); break;
            }
        }
    }
    return pop(stack);
}

int main() {
    char exp[100];
    printf("Enter the postfix expression: ");
    scanf("%s", exp);
    printf("Result: %d\n", evaluatePostfix(exp));
    return 0;
}



