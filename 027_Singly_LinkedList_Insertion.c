Question : Write a program to insert an element in a Single Linked List at 1st, last and at any position and Display the linked List;
========================================================================================================================================         
  

Algorithm:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*** Main function: ***

-> Initialize head to NULL
-> Continuously prompt the user for a choice until the user chooses to exit
-> Depending on the users choice:
    --> if the choice is 1, 
            ---> Prompt the user for the data to be inserted
            ---> Call the insert_at_first function, passing in the head and the data
    --> if the choice is 2, 
            ---> Prompt the user for the data to be inserted
            ---> check if head is NULL, if it's true then
                 ---> Call the insert_at_first function, passing in the head and the data
            --->else 
                 ---> Call the insert_at_last function, passing in the head and the data
    --> if the choice is 3,
            ---> Prompt the user for the data and position to be inserted
            ---> Call the insert_at_position function, passing in the head, the data, and the position
    --> if the choice is 4, 
            ---> Call the display_list function, passing in the head
    --> if the choice is 5, 
            ---> Exit the program

*** insert_at_first function: ***

--> Allocate memory for a new node using malloc and store the data in the new node
--> Make the new node's next point to the current head
--> Update the head to point to the new node

***insert_at_last function: ***

--> Create a new node with the data passed in
--> Traverse the list starting at the head until the last node is reached
--> Set the last nodes next to point to the new node

*** insert_at_position function: ***

--> Create a new node with the data passed in
--> Traverse the list starting at the head until the node before the desired position is reached
--> Set the new nodes next to point to the current node at the desired position
--> Update the previous nodes next to point to the new node

*** display_list function: ***

--> Initialize a pointer called current to point to the head
--> While the current pointer is not NULL
    --> Print the current nodes data
    --> Update the current pointer to point to the next node
--> End the loop

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Code Below:::
------------------------------------------------------------------------------------------------------------------------------
  
  
#include <stdio.h>
#include <stdlib.h>

// Defining the structure of a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to insert a new node at the beginning of the list
void insert_at_first(Node** head, int data) {
// --> Allocate memory for the new node
    Node* new_node = (Node*) malloc(sizeof(Node));
// --> Assign the data to the new node
    new_node->data = data;
// --> The next pointer of the new node should point to the current head
    new_node->next = *head;
// --> Change the head to point to the new node
    *head = new_node;
}

// Function to insert a new node at the end of the list
void insert_at_last(Node* head, int data) {
// --> Allocate memory for the new node
    Node* new_node = (Node*) malloc(sizeof(Node));
// --> Assign the data to the new node
    new_node->data = data;
// --> The next pointer of the new node should be NULL
    new_node->next = NULL;
// --> Traverse the list until the last node is found
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
// --> Change the next pointer of the last node to point to the new node
    temp->next = new_node;
}

// Function to insert a new node at a specific position in the list
void insert_at_position(Node* head, int data, int position) {
// --> Allocate memory for the new node
    Node* new_node = (Node*) malloc(sizeof(Node));
// --> Assign the data to the new node
    new_node->data = data;
// --> Traverse the list until the node at the specified position is found
    Node* temp = head;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
// --> Change the next pointer of the node at the specified position to point to the new node
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to display the elements of the list
void display_list(Node* head) {
// --> Traverse the list and print the data of each node
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data, position;
    // Continuously prompt the user for a choice until the user chooses to exit
    while (1) {
        printf("1. Insert at first\n2. Insert at last\n3. Insert at position\n4. Display list\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Prompt the user for the data to be inserted
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                // Call the insert_at_first function, passing in the head and the data
                insert_at_first(&head, data);
                break;
            case 2:
                // Prompt the user for the data to be inserted
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                // Call the insert_at_last function, passing in the head and the data
                if(head==NULL) insert_at_first(&head, data);
                else insert_at_last(head, data);
                break;
            case 3:
                // Prompt the user for the data and position to be inserted
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position to insert the data: ");
                scanf("%d", &position);
                // Call the insert_at_position function, passing in the head, the data, and the position
                insert_at_position(head, data, position);
                break;
            case 4:
                // Call the display_list function, passing in the head
                display_list(head);
                break;
            case 5:
                // Exit the program
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}







