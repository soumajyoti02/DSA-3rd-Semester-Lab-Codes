
Question : Write a program to implement circular queue (Push, Pop, isEmpty, isFull, Display);
=======================================================================

Algorithm :

--->Create a queue structure with front, rear, capacity and array as members.

--->Create a function to create a queue of given capacity, allocate memory for the queue, initialize front and rear of the queue and set the capacity of the queue.

--->Create a function to check if the queue is full, by comparing the rear+1 and front of the queue.

--->Create a function to check if the queue is empty, by checking if the front pointer is -1.

--->Create a function to insert an element to the queue, check if the queue is full, if not, increment rear pointer, add the item to the array and set the 
    front pointer if it is -1.

--->Create a function to remove an element from the queue, check if the queue is empty, if not, store the value of the front element in the variable 'item', 
    set the front pointer to the next element and return the value stored in 'item'

--->Create a function to display the elements of the queue, check if the queue is empty, if not, print the elements from front to rear.

--->In the main function, create a queue of given capacity, use a while loop and switch case to handle the users choice of operation, call the appropriate 
    function accordingly;



Code Below ::::
------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
  
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
    // allocating memory for the queue
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    // initializing the front and rear of the queue
    queue->front = queue->rear = -1;
    // setting the capacity of the queue
    queue->capacity = capacity;
    // allocating memory for the array of the queue
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// function to check if the queue is full
int isFull(Queue* queue) {
    //checking the condition of full queue
    return (queue->rear + 1) % queue->capacity == queue->front;
}

// function to check if the queue is empty
int isEmpty(Queue* queue) {
    // checking the condition of empty queue
    return queue->front == -1;
}

// function to insert an element to the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        // if queue is full, print "Queue is full"
        printf("Queue is full\n");
        return;
    }
    //incrementing the rear of the queue and mod it with capacity to wrap around if necessary
    queue->rear = (queue->rear + 1) % queue->capacity;
    // adding the item to the array of the queue
    queue->array[queue->rear] = item;
    if (queue->front == -1)
        // setting the front of the queue
        queue->front = queue->rear;
}

// function to remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        // if queue is empty, print "Queue is empty"
        printf("Queue is empty\n");
        return -1;
    }
    // store the value of the front element in the variable 'item'
    int item = queue->array[queue->front];
    if (queue->front == queue->rear)
        // setting the front and rear pointers to -1 to indicate an empty queue
        queue->front = queue->rear = -1;
    else
        // increment the front pointer by 1 and mod it with capacity to wrap around if necessary
        queue->front = (queue->front + 1) % queue->capacity;
    return item;
}

// function to display the elements of the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        // if queue is empty, print "Queue is empty"
        printf("Queue is empty\n");
        return;
    }
    printf("Elements in the queue: ");
    int i;
    if (queue->rear >= queue->front) {
        // if rear pointer is greater than front pointer, loop through the queue from front to rear
        for (i = queue->front; i <= queue->rear; i++)
            printf("%d ", queue->array[i]);
    } else {
        // if rear pointer is lesser than front pointer, loop through the queue from front to capacity
        for (i = queue->front; i < queue->capacity; i++)
            printf("%d ", queue->array[i]);
        // then loop through the queue from 0 to rear
        for (i = 0; i <= queue->rear; i++)
            printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    // create a queue of capacity 5
    Queue* queue = createQueue(5);

    int choice, item;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            enqueue(queue, item);
            break;
        case 2:
            item = dequeue(queue);
            if (item != -1)
                printf("Dequeued item: %d\n", item);
            break;
        case 3:
            display(queue);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}





