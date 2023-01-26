Question : Write a progran for BFS traversal in a graph;
=================================================================================
  
Breadth First Search (BFS) in a Graph:

Algorithm:
---> Initialize a queue and push the starting vertex in it
---> Mark the starting vertex as visited
---> While the queue is not empty
---> Dequeue a vertex from queue
---> For each unvisited neighbor of the dequeued vertex
---> Mark the neighbor as visited
---> Enqueue the neighbor;


Code Below :::
----------------------------------------------------------------------------------------------
  
  
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// adjacency matrix representation of the graph
int graph[MAX_VERTICES][MAX_VERTICES];
int vertices;

// visited array to keep track of visited nodes
bool visited[MAX_VERTICES];

// queue for BFS
int queue[MAX_VERTICES];
int front = 0, rear = -1;

void enqueue(int vertex) {
    queue[++rear] = vertex;
}

int dequeue() {
    return queue[front++];
}

bool isQueueEmpty() {
    return front > rear;
}

void bfs(int startVertex) {
    int i;

    // mark start vertex as visited
    visited[startVertex] = true;
    enqueue(startVertex);

    while (!isQueueEmpty()) {
        // get the next vertex from the queue
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        // visit all adjacent vertices of the current vertex
        for (i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int i, j;
    printf("Enter number of vertices and edges: ");
    scanf("%d", &vertices);

    // input adjacency matrix
    printf("Enter the Vertices\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // do BFS starting from vertex 0
    bfs(0);

    return 0;
}






