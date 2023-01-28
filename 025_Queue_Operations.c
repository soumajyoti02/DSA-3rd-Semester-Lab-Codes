Question : Write a program to implement linear queue data structure using structure;
========================================================================================
  
>>>>>>>>>>-------- Algorithm for Linear Queue using Structure: --------<<<<<<<<<<<<<

Create a queue structure with variables for front, rear, capacity, and array.
---> Define a struct named 'Queue' with variables front, rear, capacity and array.

Create a function to create a queue of given capacity.
---> Create a function named 'createQueue' which takes an integer as an argument, capacity.
---> Create a pointer of type Queue, 'queue' and initialize it by allocating memory for it.
---> Assign 0 to front and rear of queue.
---> Assign capacity to capacity variable of queue.
---> Allocate memory for the array variable of queue with the given capacity.
---> Return 'queue'

Create a function to check if the queue is full
---> Create a function named 'isFull' which takes a pointer of type Queue as an argument.
---> Return true if 'rear' of queue is equal to its 'capacity' else return false.

Create a function to check if the queue is empty
---> Create a function named 'isEmpty' which takes a pointer of type Queue as an argument.
---> Return true if 'front' of queue is equal to 'rear' else return false.

Create a function to insert an element to the queue
---> Create a function named 'enqueue' which takes two arguments, a pointer of type Queue, 'queue' and an integer, 'item'.
---> If the queue is full, print "Queue is full" and return.
---> Assign item to the position of rear in the array of queue.
---> Increment rear by 1

Create a function to remove an element from the queue
---> Create a function named 'dequeue' which takes a pointer of type Queue as an argument, 'queue'.
---> If the queue is empty, print "Queue is empty" and return -1.
---> Create a variable 'item' and assign the value of front position of array of queue to it.
---> Increment front by 1
---> Return item

Create a function to display the elements of the queue
---> Create a function named 'display' which takes a pointer of type Queue as an argument, 'queue'.
---> If the queue is empty, print "Queue is empty" and return.
---> Print "Elements in the queue: "
---> Iterate from front to rear of the queue and print the elements of the queue.

Create a main function
---> Create a pointer of type Queue, 'queue' and initialize it by calling the 'createQueue' function with capacity as an argument.
---> Create a variable 'choice' and 'item'
---> Use an infinite loop
---> In the loop, Use switch case to handle users choice of operation.
---> case 1: enqueue
---> case 2: dequeue
---> case 3: display
---> case 4: exit
---> default: Invalid choice

End of the program;






Code Below :::::
----------------------------------------------------------------------------------------------------------------------------------------
  
  
  
  
#include <stdio.h>
#include <stdlib.h>

// define a queue structure
typedef struct queue {
    int front, rear;
    int capacity;
    int* array;
} Queue;

// function to create a queue of given capacity
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = 0;
    queue->capacity = capacity;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// function to check if the queue is full
int isFull(Queue* queue) {
    return queue->rear == queue->capacity;
}

// function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

// function to insert an element to the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->array[queue->rear] = item;
    queue->rear++;
}

// function to remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front++;
   return item;
    }
// function to display the elements of the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements in the queue: ");
    for (int i = queue->front; i < queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    // create a queue of capacity 5
    Queue* queue = createQueue(5);

    int choice;
    int item;

    while(1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                item = dequeue(queue);
                if (item != -1) {
                    printf("Dequeued item: %d\n", item);
                }
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

