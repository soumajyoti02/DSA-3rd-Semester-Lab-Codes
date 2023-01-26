Question : Write a program to create a binary search tree and perform the following traversal algorithms:
           i) Pre-order ii) In-order iii)Post-order;
================================================================================================================
  
Algorithm: 

Inorder Traversal:
---> Initialize an empty stack
---> Initialize current node as root
---> Push the current node to stack and set current = current->left until current is NULL
---> If current is NULL and stack is not empty
---> Pop the top item from stack
---> Print the popped item, set current = popped_item->right
---> Repeat steps 2 and 3 until current is NULL and stack is empty

Preorder Traversal:
---> Initialize current node as root
---> Print the current node
---> Traverse the left subtree by recursively calling the pre-order function
---> Traverse the right subtree by recursively calling the pre-order function

Postorder Traversal:
---> Initialize current node as root
---> Traverse the left subtree by recursively calling the post-order function
---> Traverse the right subtree by recursively calling the post-order function
---> Print the current node;



Code Below :::
-------------------------------------------------------------------------------------------------------------
  
  
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

// Function to create a new node and initialize it
struct Node *newNode(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Function to insert a new node into the binary search tree
struct Node *insert(struct Node *node, int data) {
  if (node == NULL)
    return newNode(data); // if the tree is empty, create a new node
  if (data < node->data)
    node->left =
        insert(node->left, data); // if the data is less than the current node,
                                  // recursively insert it in the left subtree
  else if (data > node->data)
    node->right = insert(node->right,
                         data); // if the data is greater than the current node,
                                // recursively insert it in the right subtree
  return node;
}

// Function to perform pre-order traversal of the binary search tree
void preOrder(struct Node *node) {
  if (node == NULL)
    return;                  // if the current node is NULL, return
  printf("%d ", node->data); // print the data of the current node
  preOrder(node->left);      // recursively call preOrder on the left subtree
  preOrder(node->right);     // recursively call preOrder on the right subtree
}

// Function to perform in-order traversal of the binary search tree
void inOrder(struct Node *node) {
  if (node == NULL)
    return;                  // if the current node is NULL, return
  inOrder(node->left);       // recursively call inOrder on the left subtree
  printf("%d ", node->data); // print the data of the current node
  inOrder(node->right);      // recursively call inOrder on the right subtree
}

// Function to perform post-order traversal of the binary search tree
void postOrder(struct Node *node) {
  if (node == NULL)
    return;                  // if the current node is NULL, return
  postOrder(node->left);     // recursively call postOrder on the left subtree
  postOrder(node->right);    // recursively call postOrder on the right subtree
  printf("%d ", node->data); // print the data of the current node
}

int main() {
  struct Node *root = NULL; // Initialize an empty tree

  // Insert some values into the tree
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  printf("Pre-order traversal: ");
  preOrder(root);
  printf("\n");

  printf("In-order traversal: ");
  inOrder(root);
  printf("\n");

  printf("Post-order traversal: ");
  postOrder(root);
  printf("\n");
  return 0;
}




