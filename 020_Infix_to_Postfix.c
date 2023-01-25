
Question : Write a program to convert infix expression to postfix expression.
======================================================================================
  
Algorithm:

---> Create a stack
---> Scan through the infix expression
---> If the scanned character is an operand, add it to the output string
---> If the scanned character is an open parenthesis, push it to the stack
---> If the scanned character is a close parenthesis, pop elements from the stack and add them to the output string until an open parenthesis is encountered
---> If the scanned character is an operator, pop elements from the stack and add them to the output string as long as there are operators on the stack with greater or equal precedence
---> Push the scanned operator to the stack
---> Repeat steps 2-7 until all characters are scanned
---> Pop any remaining operators from the stack and add them to the output string
---> Print the final postfix expression;


Code Below :::
------------------------------------------------------------------------------------
  
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// define a stack structure
typedef struct stack {
    int top;
    int capacity;
    char *array;
} Stack;

// function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
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
void push(Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// function to pop an element from the stack
char pop(Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

// function to get the precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

// function to convert infix expression to postfix expression
void infixToPostfix(char* exp) {
    // create a stack
    Stack* stack = createStack(strlen(exp));
    int i, k;
    for (i = 0, k = -1; exp[i]; i++) {
        // if the scanned character is an operand, add it to the output string
        if (isalnum(exp[i]) || (exp[i] == ' ')) {
            if (isalnum(exp[i]))
                exp[++k] = exp[i];
        }
        // if the scanned character is an operator
        else if (exp[i] == '(')
            push(stack, exp[i]);
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && stack->array[stack->top] != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && stack->array[stack->top] != '(')
                return;
            else
                pop(stack);
        } else {
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(stack->array[stack->top]))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }
       while (!isEmpty(stack))
        exp[++k] = pop(stack);
    exp[++k] = '\0';
    printf("Postfix expression: %s\n", exp);
}

int main() {
    char exp[100];
    printf("Enter the infix expression: ");
    scanf(" %[^\n]s", exp);
    infixToPostfix(exp);
    return 0;
}




