Question : Write a program to implement queue data structure using linked list.
========================================================================================
  
Algorithm :

Initialize the front and rear pointers to NULL

enqueue(int x):
---> Create a new node and assign the value of x to the data field
---> Make the next field of the new node point to NULL
---> If the front and rear pointers are both NULL, make them point to the new node
---> Else, make the next field of the rear pointer point to the new node and update the rear pointer to point to the new node

dequeue():
---> If the front pointer is NULL, print an error message and return
---> Else, if the front and rear pointers are pointing to the same node, set both pointers to NULL
---> Else, move the front pointer to the next node

peek():
---> If the front pointer is NULL, print an error message and return
---> Else, print the data of the front node

printQueue():
---> Initialize a temporary pointer to point to the front of the queue
---> Traverse through the queue, starting from the front, and print the data of each node
---> When the end of the queue is reached, print a newline

In the main function:
---> Continuously prompt the user for a choice between the available options
---> Depending on the choice, call the appropriate function
---> If the choice is invalid, print an error message
---> If the choice is to exit, end the program


Code Below :::
---------------------------------------------------------------------------------------------------------------------
  
  
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void dequeue() {
    if (front == NULL) {
        printf("Error: Queue is Empty\n");
        return;
    }
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
}

void peek() {
    if (front == NULL) {
        printf("Error: Queue is Empty\n");
        return;
    }
    printf("Front element is %d\n", front->data);
}

void printQueue() {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, x;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Print Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Enqueue
                printf("Enter the element to enqueue: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2: // Dequeue
                dequeue();
                break;
            case 3: // Peek
                peek();
                break;
            case 4: // Print Queue
                printQueue();
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



