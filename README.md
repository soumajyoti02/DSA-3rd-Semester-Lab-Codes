# Data Structures
A data structure is a particular way of organizing and storing data in a computer so that it can be accessed and modified efficiently. Common data structures include arrays, linked lists, stacks, queues, trees and graphs. Each data structure has its own set of advantages and disadvantages, and the choice of which to use depends on the specific requirements of the problem being solved.

# Time Complexity
---> Time complexity is a measure of the efficiency of an algorithm, and is usually expressed using big O notation

---> It represents the amount of time required for an algorithm to run as a function of the input size

---> Common time complexities include O(1), O(n), O(log n), and O(n^2)

---> O(1) represents a constant time complexity, meaning the time taken to execute the algorithm does not depend on the size of the input

---> O(n) represents a linear time complexity, meaning the time taken to execute the algorithm increases linearly with the size of the input

---> O(log n) represents a logarithmic time complexity, meaning the time taken to execute the algorithm increases logarithmically with the size of the input

---> O(n^2) represents a quadratic time complexity, meaning the time taken to execute the algorithm increases quadratically with the size of the input

# Malloc
---> malloc is a function in C programming language which allows the user to dynamically allocate memory at runtime

---> malloc returns a pointer to the first byte of the allocated memory, which can be used to access the memory

---> It takes a single argument, the number of bytes of memory to be allocated

---> It's important to free the memory allocated by malloc using the free function when it's no longer needed to avoid memory leaks

# Self-Referencing Structures
---> Self-referencing structures are data structures in which an instance of the structure contains a reference to another instance of the same structure

---> These structures are typically used to implement linked lists and trees, where each node of the list or tree contains a reference to the next or child node

---> These structures are useful for creating recursive algorithms for traversing the structure and solving problems such as tree traversal and graph traversal.

# Sparse Matrix
---> A sparse matrix is a matrix in which most of the elements are zero

---> Sparse matrices are a common representation of data in scientific computing and machine learning

---> Sparse matrices can be stored and manipulated more efficiently than dense matrices by using special data structures such as sparse matrix formats (COO, CSR, CSC, etc)

---> Sparse matrices can be used in linear algebra, graph theory, and many other fields

---> Sparse matrix-vector multiplications and sparse matrix-matrix multiplications are the fundamental operations for many machine learning algorithms that use sparse matrices.

# Row-Major Order
---> In row-major order, the element at position (i, j) in a matrix A of size (m, n) can be accessed at the memory location A[i*n + j]

---> The memory location of the element at position (i, j) is calculated by taking the row number i and multiplying it by the number of columns n, and then adding the column number j.

# Column-Major Order
---> In column-major order, the element at position (i, j) in a matrix A of size (m, n) can be accessed at the memory location A[j*m + i]

---> The memory location of the element at position (i, j) is calculated by taking the column number j and multiplying it by the number of rows m, and then adding the row number i.

# Arrays
---> Arrays are a data structure that stores a fixed-size sequence of elements of the same type

---> They allow for efficient random access, but do not provide an efficient way to insert or delete elements in the middle of the array

---> Common operations on arrays include accessing an element, searching for an element, and sorting the elements

# Stack
---> A stack is a data structure that follows the LIFO (Last In First Out) principle

---> It provides efficient operations for adding an element (push), removing an element (pop), and accessing the top element (peek)

---> Common use cases of stacks include undo/redo functionality, function call history, and parsing expressions

# Queue
---> A queue is a data structure that follows the FIFO (First In First Out) principle

---> It provides efficient operations for adding an element (enqueue), removing an element (dequeue), and accessing the front element (peek)

---> Common use cases of queues include scheduling tasks, event handling, and maintaining a buffer

# Circular Queue
---> A circular queue is a variation of a queue where the last position is connected to the first position

---> This allows for efficient use of memory, as it does not require reallocation of memory when the queue becomes full

---> It also allows for efficient implementation of a circular buffer

# Deque (Double Ended Queue)
---> A deque (double ended queue) is a data structure that allows for efficient insertion and deletion at both ends

---> It provides efficient operations for adding an element at the front (push front), adding an element at the back (push back), removing an element from the front (pop front), and removing an element from the back (pop back)

# Priority Queue
---> A priority queue is a data structure that assigns a priority to each element, and provides efficient operations for adding an element (insert), removing the highest priority element (extract max/min), and accessing the highest priority element (peek)

---> It is commonly implemented using a heap data structure

# Linked List
---> A linked list is a data structure that stores a sequence of elements, where each element points to the next element

---> It allows for efficient insertion and deletion of elements, but does not provide efficient random access

---> Common types of linked lists include singly linked lists, doubly linked lists, and circular linked lists

# Doubly Linked List
--->A doubly linked list is a variation of a linked list where each element points to both the next and the previous elements

--->It allows for efficient traversal in both directions, but requires more memory due to the additional pointers
# Circular Linked List
---> A circular linked list is a variation of a linked list where the last element points to the first element, forming a loop

---> It allows for efficient implementation of a circular buffer and is used in some algorithms such as cycle detection

# BST (Binary Search Tree)
---> A BST is a data structure that stores elements in a binary tree format where the left child of a node is smaller than the parent node and the right child is larger

---> It provides efficient operations for searching, insertion and deletion of elements

---> It can be used for sorting and searching data, like dictionaries and phone directories

# AVL Tree
---> An AVL tree is a variation of a BST where the tree is always balanced, meaning the height of the left and right subtrees of any node differ by at most 1

---> It provides efficient operations for searching, insertion and deletion of elements and it also guarantees a height of O(log n)

# Graph
---> A graph is a data structure that consists of a set of vertices and a set of edges connecting them.

---> It can be used to represent various types of relationships and can be used to solve various problems such as shortest path and connectivity.

# BFS (Breadth-First Search)
---> BFS is an algorithm used to traverse a graph or a tree and it visits all the vertices of the graph in breadth-first order.

---> It is used to find the shortest path and also used to find the connected components in an undirected graph.

# DFS (Depth-First Search)
---> DFS is an algorithm used to traverse a graph or a tree and it visits all the vertices of the graph in depth-first order.
---> It is used to solve problems like finding the connected components, cycle detection, and topological sorting.
