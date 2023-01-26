Question : Write a program to merge two linked list in sorted order. 
==============================================================================
  
Merge Sort Algorithm for Singly Linked Lists:

---> Create a new node with the given data and insert it at the front of the linked list (insert function).
  
---> Find the middle node of the linked list by using a fast and slow pointer technique (getMid function). Initialize both pointers to the head of the 
    list and then move the fast pointer two steps at a time, while the slow pointer moves one step at a time. When the fast pointer reaches the end of the list, 
    the slow pointer will be pointing to the middle node.
  
---> Merge two sorted linked lists together in a sorted manner by comparing the data of the first node of each list and adding the smaller one to a new linked list 
    (mergeLists function). Continue this process until one of the lists is exhausted, then add the remaining nodes of the other list to the new list.
  
---> Sort a linked list using the merge sort algorithm (mergeSort function). First check if the list has 0 or 1 element and return the list if so. Otherwise,
    use the getMid function to find the middle node of the list and split the list into two. Recursively sort both the first and second half of the list and 
    then merge them together using the mergeLists function.
  
---> In the main function, create two linked lists and insert some values into them. Call mergeLists to merge the two lists and mergeSort to sort the merged list.
    Print out the sorted merged list.
  
      
 

Code Below :::
------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
  
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};
void insert(struct Node **head, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}
struct Node *getMid(struct Node *head) {
  struct Node *fast = head;
  struct Node *slow = head;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}
struct Node *mergeLists(struct Node *head1, struct Node *head2) {
  struct Node *dummy = (struct Node *)malloc(sizeof(struct Node));
  dummy->next = NULL;
  struct Node *tail = dummy;
  while (head1 && head2) {
    if (head1->data <= head2->data) {
      tail->next = head1;
      head1 = head1->next;
    } else {
      tail->next = head2;
      head2 = head2->next;
    }
    tail = tail->next;
  }
  tail->next = head1 ? head1 : head2;
  return dummy->next;
}

struct Node *mergeSort(struct Node *head) {
  if (!head || !head->next) {
    return head;
  }
  struct Node *first, *second;
  struct Node *mid = getMid(head);
  second = mid->next;
  mid->next = NULL;
  first = head;
  first = mergeSort(first);
  second = mergeSort(second);
  return mergeLists(first, second);
}

int main() {
  struct Node *head1 = NULL;
  struct Node *head2 = NULL;

  // Inserting nodes in the first linked list
  insert(&head1, 7);
  insert(&head1, 5);
  insert(&head1, 3);
  insert(&head1, 1);

  // Inserting nodes in the second linked list
  insert(&head2, 8);
  insert(&head2, 6);
  insert(&head2, 4);
  insert(&head2, 2);

  // Merging the two linked lists
  struct Node *mergedList = mergeLists(head1, head2);

  // Sorting the merged linked list
  mergedList = mergeSort(mergedList);

  // Printing the sorted merged linked list
  struct Node *temp = mergedList;
  printf("Sorted Merged Linked List: \n");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }

  return 0;
}


