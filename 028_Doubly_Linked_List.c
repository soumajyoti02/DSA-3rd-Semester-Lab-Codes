Question : Write a program in a Doubly Linked List to :
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
Insert at first position:
---> Allocate memory for the new node
---> Set the data of the new node to the given data
---> Check if the head is NULL
---> If it is, set the new nodes next and previous pointers to NULL and set the head to point to the new node
---> If the head is not NULL, set the new nodes next pointer to the current head and the previous pointer to NULL
---> Set the previous pointer of the current head to the new node
---> Set the head to point to the new node

Insert at last position:
---> Allocate memory for the new node
---> Set the data of the new node to the given data
---> Check if the head is NULL
---> If it is, set the new nodes next and previous pointers to NULL and set the head to point to the new node
---> If the head is not NULL, initialize a pointer, current, to point to the head
---> Traverse the list until the last node is reached
---> Set the new nodes previous pointer to the current node and the next pointer to NULL
---> Set the next pointer of the current node to the new node

Insert at any position:
---> Allocate memory for the new node
---> Set the data of the new node to the given data
---> Check if the position is the first position
---> If it is, insert at the first position
---> Else, initialize a pointer, current, to point to the head
---> Traverse the list until the node before the position to be inserted is reached
---> Set the new nodes next pointer to the current nodes next pointer
---> Set the new nodes previous pointer to the current node
---> Set the previous pointer of the current nodes next pointer to the new node
---> Set the current nodes next pointer to the new node
  
Display the linked list:
---> Check if the list is empty
---> If it is, return
---> Else, initialize a pointer, current, to point to the head of the list
---> Traverse the list, printing the data of each node
---> At the end of the list, return
Algorithm for deleting a node from a doubly linked list:

Delete from first position:
---> Check if the list is empty
---> If it is, return
---> Else, create a temporary pointer, temp, and set it to point to the head of the list
---> Set the head to point to the next node in the list
---> Set the previous pointer of the new head to NULL
---> Free the memory allocated for the first node using the temporary pointer

Delete from last position:
---> Check if the list is empty
---> If it is, return
---> Else, initialize a pointer, current, to point to the head of the list
---> Traverse the list until the second-to-last node is reached
---> Set the next pointer of the second-to-last node to NULL
---> Set the previous pointer of the last node to NULL
---> Free the memory allocated for the last node

Delete from any position:
---> Check if the list is empty
---> If it is, return
---> Else, check if the position is the first position
---> If it is, delete from the first position
---> Else, initialize a pointer, current, to point to the head of the list
---> Traverse the list until the node to be deleted is reached
---> Set the previous pointer of the next node to the previous node of the current node
---> Set the next pointer of the previous node to the next node of the current node
---> Free the memory allocated for the current node;





Code Below ::
---------------------------------------------------------------------------------------------------
  
  
  
  
#include <stdio.h>
#include <stdlib.h>

// Structure for a node of the doubly linked list
struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

// Function to create a new node and return its address
struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtStart(struct Node **head, int data) {
  struct Node *newNode = createNode(data);
  newNode->next = *head;
  if (*head != NULL) {
    (*head)->prev = newNode;
  }
  *head = newNode;
}

// Function to insert a new node at a given position
void insertAtPosition(struct Node **head, int data, int position) {
  if (*head == NULL) { // Edge case: if list is empty
    printf("List is empty. Inserting at beginning\n");
    insertAtStart(head, data);
    return;
  }
  if (position < 0) { // Edge case: if position is invalid
    printf("Invalid position\n");
    return;
  }
  int i;
  struct Node *temp = *head;
  for (i = 0; temp->next != NULL && i < position - 1; i++) {
    temp = temp->next;
  }
  if (i !=
      position -
          1) { // Edge case: if position exceeds number of nodes in the list
    printf("Invalid position\n");
    return;
  }
  struct Node *newNode = createNode(data);
  newNode->prev = temp;
  newNode->next = temp->next;
  if (temp->next)
    temp->next->prev = newNode;
  temp->next = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node *head, int data) {
  if (head == NULL) { // Edge case: if list is empty
    printf("List is empty. Inserting at beginning\n");
    insertAtStart(&head, data);
    return;
  }
  struct Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  struct Node *newNode = createNode(data);
  newNode->prev = temp;
  temp->next = newNode;
}

// Function to delete the first node of the list
void deleteFromStart(struct Node **head) {
  if (*head == NULL) { // Edge case: if list is empty
    printf("List is empty\n");
    return;
  }
  struct Node *temp = *head;
  *head = temp->next;
  if (*head != NULL) {
    (*head)->prev = NULL;
  }
  free(temp);
}

// Function to delete a node from a given position
void deleteFromPosition(struct Node **head, int position) {
  if (*head == NULL ||
      position < 0) { // Edge case: if list is empty or position is invalid
    printf("Invalid position\n");
    return;
  }
  int i;
  struct Node *temp = *head;
  for (i = 0; temp->next != NULL && i < position; i++) {
    temp = temp->next;
  }
  if (i !=
      position) { // Edge case: if position exceeds number of nodes in the list
    printf("Invalid position\n");
    return;
  }
  if (temp == *head) {
    *head = temp->next;
    if (*head != NULL) {
      (*head)->prev = NULL;
    }
  } else {
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
      temp->next->prev = temp->prev;
    }
  }
  free(temp);
}

struct Node *deleteFromEnd(struct Node *head) {
  if (head == NULL) { // Edge case: if list is empty
    printf("List is empty\n");
    return NULL;
  }
  if (head->next == NULL) { // Edge case: if there's only one node in the list
    free(head);
    return NULL;
  }
  struct Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->prev->next = NULL;
  free(temp);
  return head;
}

// Function to display the list
void displayList(struct Node *head) {
  if (head == NULL) { // Edge case: if list is empty
    printf("List is empty\n");
    return;
  }
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Function to count the number of nodes in the list
int countNodes(struct Node *head) {
  int count = 0;
  struct Node *temp = head;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

int main() {
  struct Node *head = NULL;
  int choice, data, position;
  while (1) {
    printf("\n1. Insert at start\n");
    printf("2. Insert at position\n");
    printf("3. Insert at end\n");
    printf("4. Delete from start\n");
    printf("5. Delete from position\n");
    printf("6. Delete from end\n");
    printf("7. Display list\n");
    printf("8. Count number of nodes\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the data to insert: ");
      scanf("%d", &data);
      insertAtStart(&head, data);
      displayList(head);
      break;
    case 2:
      printf("Enter the data and position to insert: ");
      scanf("%d%d", &data, &position);
      insertAtPosition(&head, data, position);
      displayList(head);
      break;
    case 3:
      printf("Enter the data to insert: ");
      scanf("%d", &data);
      if (head == NULL) {
        insertAtStart(&head, data);
      } else
        insertAtEnd(head, data);
      displayList(head);
      break;
    case 4:
      deleteFromStart(&head);
      displayList(head);
      break;
    case 5:
      printf("Enter the position to delete: ");
      scanf("%d", &position);
      deleteFromPosition(&head, position);
      displayList(head);
      break;
    case 6:
      head = deleteFromEnd(head);
      displayList(head);
      break;
    case 7:
      displayList(head);
      break;
    case 8:
      printf("Number of nodes: %d\n", countNodes(head));
      break;
    case 9:
      exit(0);
      break;
    default:
      printf("Invalid choice\n");
      break;
    }
  }
  return 0;
}





