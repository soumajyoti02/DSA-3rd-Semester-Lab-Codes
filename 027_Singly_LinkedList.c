Question : Write a program in a Single Linked List to :
a) Insert at 1st position
b) Insert at last position
c) Insert at any position
Also:
a) Delete From 1st position
b) Delete From last position
c) Delete From any position
d) Display the Linked List;
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
            ---> check if head is NULL, if its true then
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
--> Make the new nodes next point to the current head
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

*** Delete from first position: ***
---> Check if the list is empty
---> If it is, return
---> Else, create a temporary pointer, temp, and set it to point to the head of the list
---> Set the head to point to the next node in the list
---> Free the memory allocated for the first node using the temporary pointer

*** Delete from last position: ***
---> Check if the list is empty
---> If it is, return
---> Else, initialize a pointer, current, to point to the head of the list
---> Traverse the list until the second-to-last node is reached
---> Set the next pointer of the second-to-last node to NULL
---> Free the memory allocated for the last node

*** Delete from any position: ***
---> Check if the list is empty
---> If it is, return
---> Else, check if the position is the first position
---> If it is, delete from the first position
---> Else, initialize a pointer, current, to point to the head of the list
---> Traverse the list until the node before the position to be deleted is reached
---> Set the next pointer of the previous node to the next node of the current node
---> Free the memory allocated for the current node
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Code Below:::
------------------------------------------------------------------------------------------------------------------------------
  
  
#include <stdio.h>
#include <stdlib.h>

// Define a struct Node containing an integer data field and a pointer to the next Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

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
        if(temp == NULL)
        {
            printf("Invalid Position\n");
            return;
        }
        temp = temp->next;
    }
// --> Change the next pointer of the node at the specified position to point to the new node
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to delete a node from the first position
void delete_from_first(Node** head) {
    // Check if the list is empty
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Store a pointer to the current head
    Node* current = *head;
    // Update the head to point to the next node
    *head = current->next;
    // Free the memory allocated for the current head
    free(current);
    printf("Node deleted from first position\n");
}

// Function to delete a node from the last position
void delete_from_last(Node** head) {
    // Check if the list is empty
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Check if the list has only one element
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Node deleted from last position\n");
        return;
    }

    // Initialize two pointers, current and previous, to point to the head
    Node* current = *head;
    Node* previous = NULL;

    // Traverse the list until the last node is reached
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    // Set the previous node's next to NULL
    previous->next = NULL;
    // Free the memory allocated for the last node
    free(current);
    printf("Node deleted from last position\n");
}

// Function to delete a node from a specific position
void delete_from_position(Node** head, int position) {
    // Check if the list is empty
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Check if the position is the first position
    if (position == 1) {
        delete_from_first(head);
        return;
    }

    // Initialize a pointer, current, to point to the head
    Node* current = *head;
    int i;

    // Traverse the list to the desired position
    for (i = 1; i < position-1; i++) {
        // Check if the end of the list is reached
        if (current->next == NULL) {
            printf("Position not found\n");
            return;
        }
        current = current->next;
    }

    // Store a pointer to the node to be deleted
    Node* temp = current->next;
    // Update the current node's next to point to the next next node
    current->next = temp->next;
    // Free the memory allocated for the node to be deleted
    free(temp);
    printf("Node deleted from position %d\n", position);
}

// Function to display the list
void display_list(Node* head) {
    // Check if the list is empty
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Initialize a pointer, current, to point to the head
    Node* current = head;

    // Traverse the list
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL; // Initialize an empty list

    int choice;
    int data, position;

    while(1) {
        printf("1. Insert at first position\n");
        printf("2. Insert at last position\n");
        printf("3. Insert at any position\n");
        printf("4. Delete from first position\n");
        printf("5. Delete from last position\n");
        printf("6. Delete from any position\n");
        printf("7. Display the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
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
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insert_at_position(head, data, position);
                break;
            case 4:
                delete_from_first(&head);
                break;
            case 5:
                delete_from_last(&head);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                delete_from_position(&head, position);
                break;
            case 7:
                display_list(head);
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}







