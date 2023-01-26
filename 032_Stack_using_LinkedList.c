Question :  Write a program to implement stack data structure using linked list;
=============================================================================================
  
Algorithm:

push(int x): This function creates a new node, assigns the value of x to the data field, and makes the next field point to the current top element. 
              The top pointer is then updated to point to the new node.

pop(): This function removes the top element from the stack. It checks if the stack is empty and if it is, it prints an error message. 
      If the stack is not empty, it creates a temporary pointer that points to the current top element, updates the top pointer to point to the next 
      element and then frees the memory allocated for the temporary pointer.

peek(): This function returns the value of the top element in the stack. It checks if the stack is empty and if it is, it prints an error message. 
        If the stack is not empty, it prints the value of the top element.

printStack(): This function prints all the elements of the stack starting from the top element. It creates a temporary pointer that points to the current 
              top element and then iterates through the stack while printing the data field of each node and moving the temporary pointer to the next node.

main(): This is the entry point of the program and contains the logic for the menu-driven user interface. It initializes an empty stack, and then 
        enters into a while loop that prints a menu of options for the user to choose from. The options include pushing an element onto the stack, popping an 
        element from the stack, peeking at the top element of the stack, printing the entire stack, or exiting the program. Depending on the users choice,
        the corresponding function is called;


Code Below :::
---------------------------------------------------------------------------------------------------------------------------------------------------
  
  
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top;

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        printf("Error: Stack is Empty\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    free(temp);
}

void peek() {
    if (top == NULL) {
        printf("Error: Stack is Empty\n");
        return;
    }
    printf("Top element is %d\n", top->data);
}

void printStack() {
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    top = NULL; // Initialize empty stack
    int choice, x;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Push
                printf("Enter the element to push: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2: // Pop
                pop();
                break;
            case 3: // Peek
                peek();
                break;
            case 4: // Print Stack
                printStack();
                break;
            case 5: // Exit
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
