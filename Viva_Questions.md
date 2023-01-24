# Stack
## Q) What is a stack?

Ans) A stack is a linear data structure that follows the Last In First Out (LIFO) principle. It allows elements to be added and removed from the top of the stack.

## Q) What is the difference between a stack and a queue?

Ans) A stack follows the LIFO principle while a queue follows the First In First Out (FIFO) principle.

## Q) What is the time complexity of the push and pop operations in a stack?

Ans) The time complexity of the push and pop operations in a stack is O(1)

## Q) What are the applications of stack?

Ans) Stacks are used in various applications such as expression evaluation, parsing, undo/redo, and backtracking.

## Q) What is the overflow condition in stack?

Ans) Overflow condition in stack occurs when we try to push an element in a full stack and there is no space available for the new element.

## Q) What is the underflow condition in stack?

Ans) Underflow condition in stack occurs when we try to pop an element from an empty stack.

## Q) How is a stack implemented?
Ans) A stack can be implemented using an array, a linked list, or a dynamic array.

## Q) What are the basic operations performed on a stack?
Ans) The basic operations performed on a stack are push, pop, peek, and isEmpty.

## Q) What is an overflow condition in a stack?
Ans) An overflow condition in a stack occurs when the stack is full and a new element is pushed onto it.

## Q) What is an underflow condition in a stack?
Ans) An underflow condition in a stack occurs when the stack is empty and an element is popped from it.

## Q) What is a stack pointer?
Ans) A stack pointer is a pointer that points to the top element of the stack.

## Q) What is a stack frame?
Ans) A stack frame is a block of memory that is used to hold the local variables and information about the calling function during a function call.

## Q) What is a stack overflow error?
Ans) A stack overflow error occurs when a program tries to use more memory than the stack can hold.

## Q) What is a stack underflow error?
Ans) A stack underflow error occurs when a program tries to pop an element from an empty stack.

<hr>

# Queue
## Q) What is a queue?
Ans) A queue is a linear data structure that follows the First In First Out (FIFO) principle. It allows elements to be added at the back and removed from the front of the queue.

## Q) What is the difference between a stack and a queue?
Ans) A stack follows the LIFO principle while a queue follows the First In First Out (FIFO) principle.

## Q) What is the time complexity of the enqueue and dequeue operations in a queue?
Ans) The time complexity of the enqueue and dequeue operations in a queue is O(1).

## Q) What are the applications of queue?
Ans) Queues are used in various applications such as scheduling, buffering, and communication.

## Q) What is the overflow condition in queue?
Ans) Overflow condition in queue occurs when we try to insert an element in a full queue and there is no space available for the new element.

## Q) What is the underflow condition in queue?
Ans) Underflow condition in queue occurs when we try to remove an element from an empty queue.

<hr>

# Circular Queue
## Q) What is a circular queue?
Ans) A circular queue is a linear data structure that follows the First In First Out (FIFO) principle. It allows elements to be added at the back and removed from the front of the queue. It is called circular because when the last element is reached, the next insertion will be at the front.

## Q) What is the difference between a regular queue and a circular queue?
Ans) A regular queue uses a fixed size array, once the last element is reached, it cannot insert new element until some space is freed. While in circular queue, once the last element is reached, it starts inserting new elements at the front again.

## Q) What is the advantage of using a circular queue over a regular queue?
Ans) The advantage of using a circular queue is that it eliminates the need for resizing the queue when it becomes full, which can save memory and computational resources.

## Q) How do you implement a circular queue in an array?
Ans) A circular queue can be implemented in an array by using two pointers, one to keep track of the front of the queue and another to keep track of the back of the queue. The front pointer points to the first element of the queue while the rear pointer points to the next available position for inserting an element. When the rear pointer reaches the end of the array, it wraps around to the beginning of the array.

## Q) How do you check if a circular queue is empty or full?
Ans) To check if a circular queue is empty, we can check if the front and rear pointers are pointing to the same location. To check if a circular queue is full, we can check if the next position of the rear pointer is the same as the front pointer.

## Q) What is the time complexity of the enqueue and dequeue operations in a circular queue implemented using an array?
Ans) The time complexity of the enqueue and dequeue operations in a circular queue implemented using an array is O(1).

## Q) How do you implement a circular queue using a linked list?
Ans) A circular queue can be implemented using a linked list by creating a circular linked list where the last node points to the head node. The front of the queue is the head node and the rear of the queue is the last node.

## Q) How do you implement a circular queue using a dynamic array?
Ans) A circular queue can be implemented using a dynamic array by using the same methods as an array implementation, but with the added functionality of resizing the array when it becomes full.

<hr>

# Linked List
## Q) What is a linked list?
Ans) A linked list is a linear data structure that consists of a sequence of nodes, where each node contains a data element and a reference to the next node in the list. The first node is called the head and the last node is called the tail.

## Q) What is the time complexity of inserting an element at the front of a linked list?
Ans) The time complexity of inserting an element at the front of a linked list is O(1).

## Q) What is the time complexity of inserting an element at the end of a linked list?
Ans) The time complexity of inserting an element at the end of a linked list is O(n), where n is the number of nodes in the list.

## Q) What is the time complexity of deleting an element from a linked list?
Ans) The time complexity of deleting an element from a linked list is O(n), where n is the number of nodes in the list.

## Q) What is the advantage of a linked list over an array?
Ans) One of the advantages of a linked list over an array is that it allows for constant time insertion and deletion at the front of the list, whereas inserting or deleting an element at the beginning of an array requires shifting all the other elements by one position, which takes O(n) time.
## Q) What is a sentinel node in a linked list?
Ans) A sentinel node is a special node in a linked list that is used to simplify the implementation of certain operations. It is typically placed at the beginning or end of the list and serves as a placeholder, making it unnecessary to check for the edge cases of an empty list or a list with only one element.

## Q) How do you reverse a singly linked list?
Ans) There are several ways to reverse a singly linked list, one common method is to iterate through the list, swapping the next and previous pointers of each node, and then update the head pointer to point to the last node.

## Q) How do you find the middle element of a singly linked list?
Ans) One way to find the middle element of a singly linked list is to use two pointers, one that moves one step at a time and another that moves two steps at a time. When the second pointer reaches the end of the list, the first pointer will be pointing to the middle element.

## Q) How do you detect a cycle in a linked list?
Ans) One way to detect a cycle in a linked list is to use the Floyd's cycle-finding algorithm, which uses two pointers, one that moves one step at a time and another that moves two steps at a time. If there is a cycle in the list, the two pointers will eventually meet.

## Q) How do you implement a deep copy of a singly linked list?
Ans) One way to implement a deep copy of a singly linked list is to create a new linked list and iterate through the original list, adding new nodes with the same data values to the new list.

## Q) How do you merge two sorted linked lists?
Ans) One way to merge two sorted linked lists is to create a new linked list, and then iterate through both original lists, comparing the current nodes of each list and adding the smallest value to the new list. Repeat this process until one of the original lists is empty, then add all remaining elements of the other original list to the new list.
<hr>
# Circular Linked List
## Q) What is a circular linked list?
Ans) A circular linked list is a type of linked list where the last node points back to the first node, creating a circular loop.

## Q) What is the difference between a singly linked list and a circular linked list?
Ans) The difference between a singly linked list and a circular linked list is that in a singly linked list, the last node points to null, whereas in a circular linked list, the last node points back to the first node.

## Q) What are the advantages of using a circular linked list over a singly linked list?
Ans) Advantages of using a circular linked list over a singly linked list are that it eliminates the need to check for the last node while traversing, it can be used in a scenario where a circular buffer is required and it can be used in a scenario where a circular list is required.
<hr>
# Doubly Linked List
## Q) What is a doubly linked list?
Ans) A doubly linked list is a type of linked list where each node contains a reference to the previous node as well as the next node.

## Q) What is the advantage of a doubly linked list over a singly linked list?
Ans) The advantage of a doubly linked list over a singly linked list is that it allows for traversing the list in both directions and it allows for constant time insertion and deletion at both the front and the end of the list.

## Q) How is a doubly linked list different from a circular linked list?
Ans) A doubly linked list has a reference to the previous node as well as the next node, whereas a circular linked list only has a reference to the next node. Additionally, a doubly linked list is not circular, it will have a end node which points to null.

<hr>

# Binary Search Tree (BST)
## Q) What is a Binary Search Tree (BST)?
Ans) A Binary Search Tree (BST) is a type of tree data structure in which each node has at most two children, which are referred to as the left child and the right child. The left child of a node contains only nodes with keys lesser than the node's key, while the right child of a node contains only nodes with keys greater than the node's key.

## Q) What is the time complexity for searching an element in a BST?
Ans) The time complexity for searching an element in a BST is O(h), where h is the height of the tree. In an ideal case, where the tree is balanced, the height of the tree will be log(n), where n is the number of nodes in the tree, making the time complexity O(log(n))

## Q) What is the time complexity for inserting an element in a BST?
Ans) The time complexity for inserting an element in a BST is O(h), where h is the height of the tree. In an ideal case, where the tree is balanced, the height of the tree will be log(n), where n is the number of nodes in the tree, making the time complexity O(log(n))

## Q) What is the time complexity for deleting an element in a BST?
Ans) The time complexity for deleting an element in a BST is O(h), where h is the height of the tree. In an ideal case, where the tree is balanced, the height of the tree will be log(n), where n is the number of nodes in the tree, making the time complexity O(log(n))
## Q) What is the property of a Binary Search Tree?
Ans) The property of a Binary Search Tree is that the left child of a node contains only nodes with keys lesser than the node's key and the right child of a node contains only nodes with keys greater than the node's key.

## Q) What is the time complexity of searching an element in a BST?
Ans) The time complexity of searching an element in a BST is O(h), where h is the height of the tree.

## Q) What is the time complexity of inserting an element in a BST?
Ans) The time complexity of inserting an element in a BST is O(h), where h is the height of the tree.

## Q) What is the time complexity of deleting an element in a BST?
Ans) The time complexity of deleting an element in a BST is O(h), where h is the height of the tree.

## Q) What is the difference between a balanced and an unbalanced BST?
Ans) A balanced BST has a height logarithmic to the number of nodes, while an unbalanced BST has a height linear to the number of nodes.

Q) What is the inorder traversal of a BST?
Ans) Inorder traversal of a BST visits the left subtree, root, and then the right subtree.
<hr>
# AVL Tree
## Q) What is an AVL Tree?
Ans) An AVL Tree is a type of self-balancing binary search tree in which the difference between the heights of the left and right subtrees of any node is at most 1.

## Q) What are the advantages of using an AVL tree over a regular BST?
Ans) The advantages of using an AVL tree over a regular BST are that it guarantees a balanced tree, which ensures that the time complexity for searching, inserting, and deleting elements is always O(log(n)), where n is the number of nodes in the tree.

## Q) What is the time complexity for searching an element in an AVL tree?
Ans) The time complexity for searching an element in an AVL tree is O(log(n)), where n is the number of nodes in the tree.

## Q) What is the time complexity for inserting an element in an AVL tree?
Ans) The time complexity for inserting an element in an AVL tree is O(log(n)), where n is the number of nodes in the tree.

## Q) What is the time complexity for deleting an element in an AVL tree?
Ans) The time complexity for deleting an element in an AVL tree is O(log(n)), where n is the number of nodes in the tree.
<hr>
# Graph
## Q) What is a graph?
Ans) A graph is a non-linear data structure that consists of a finite set of vertices(or nodes) and a set of edges that connect them.

## Q) What are the two types of graph representation?
Ans) The two types of graph representation are Adjacency List and Adjacency Matrix.

## Q) What is an undirected graph?
Ans) An undirected graph is a graph in which edges have no direction and can be traversed in both directions.

## Q) What is a directed graph?
Ans) A directed graph is a graph in which edges have a direction and can only be traversed in one direction.

## Q) What is a weighted graph?
Ans) A weighted graph is a graph in which each edge has a weight or a cost associated with it.

## Q) What is a subgraph?
Ans) A subgraph is a subset of vertices and edges in a graph that form a graph on their own.

## Q) What is a connected graph?
Ans) A connected graph is a graph in which there is a path between any two vertices.

## Q) What is a disconnected graph?
Ans) A disconnected graph is a graph in which there is no path between some of the vertices.

## Q) What is a bipartite graph?
Ans) A bipartite graph is a graph whose vertices can be divided into two sets such that all edges connect a vertex in one set to a vertex in the other set.

## Q) What is the degree of a vertex?
Ans) The degree of a vertex is the number of edges incident to the vertex.

## Q) What is an isolated vertex?
Ans) An isolated vertex is a vertex that has no incident edges.

## Q) What is a loop?
Ans) A loop is an edge that connects a vertex to itself.

## Q) What is a complete graph?
Ans) A complete graph is a graph in which every vertex is connected to every other vertex.

## Q) What is a tree?
Ans) A tree is a connected undirected graph with no cycles.

## Q) What is a forest?
Ans) A forest is a collection of one or more disjoint trees.

## Q) What is a path?
Ans) A path is a sequence of vertices in a graph such that there is an edge between each consecutive pair of vertices.

## Q) What is a cycle?
Ans) A cycle is a path that starts and ends at the same vertex.

## Q) What is a simple path?
Ans) A simple path is a path that does not contain any repeated vertices.

## Q) What is a simple cycle?
Ans) A simple cycle is a cycle that does not contain any repeated vertices.
<hr>
# Hashing
## Q) What is hashing?
Ans) Hashing is a technique of mapping a large data set to a smaller data set by using a hash function.

## Q) What is a hash function?
Ans) A hash function is a function that takes an input (or 'key'), and returns a fixed-size string of characters, which is called the 'hash value'.

## Q) What is a collision in hashing?
Ans) A collision in hashing occurs when two different keys are mapped to the same index in the hash table.

## Q) What is open addressing in hashing?
Ans) Open addressing in hashing is a method of resolving collisions by finding the next available empty slot in the hash table.

## Q) What is chaining in hashing?
Ans) Chaining in hashing is a method of resolving collisions by creating a linked list of all the keys that have the same hash value.

## Q) What are the different collision resolution techniques in hashing?
Ans) The different collision resolution techniques in hashing are open addressing, chaining, and linear probing.

## Q) What is a perfect hash function?
Ans) A perfect hash function is a hash function that maps each key to a unique index in the hash table.

## Q) What is a load factor in hashing?
Ans) A load factor in hashing is the ratio of the number of items stored in the hash table to the number of slots in the table.

## Q) What is a hash table?
Ans) A hash table is a data structure that stores items using a key-value pair, where the key is used to compute the index of the item in the table using a hash function.

## Q) What is the time complexity of searching an element in a hash table?
Ans) The time complexity of searching an element in a hash table is O(1) on average, O(n) in worst case.

## Q) What is the time complexity of inserting an element in a hash table?
Ans) The time complexity of inserting an element in a hash table is O(1) on average, O(n) in worst case.

## Q) What is the time complexity of deleting an element in a hash table?
Ans) The time complexity of deleting an element in a hash table is O(1) on average, O(n) in worst case.

## Q) What is the difference between a hash table and a dictionary?
Ans) A hash table and a dictionary are the same thing, a hash table is the more common term used in computer science and a dictionary is the more common term used in general.

## Q) What is the difference between a hash table and an array?
Ans) A hash table uses a hash function to map keys to indices, while an array uses an index to access elements.

## Q) What is a hash function's security?
Ans) A hash function's security is the ability of the hash function to produce a unique output for each input and make it difficult to reverse the process.

## Q) What is a hash function's collision rate?
Ans) A hash function's collision rate is the likelihood that two different inputs will result in the same output. The lower the collision rate, the more efficient the hash function is.

## Q) What are the types of hash functions?
Ans) The types of hash functions are:

Division Method
Multiplication Method
Universal Hashing
Cryptographic Hashing
## Q) What is a Bloom filter?
Ans) A Bloom filter is a probabilistic data structure that is used to test whether an element is a member of a set or not.

## Q) What is a hash table's load factor?
Ans) A hash table's load factor is the ratio of the number of items stored in the table to the number of slots in the table. When the load factor exceeds a certain threshold, the table may need to be resized to maintain good performance.



