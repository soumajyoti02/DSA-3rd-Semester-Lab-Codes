Question : Write a program to use DFS to traverse through a graph;
================================================================================

Depth First Search (DFS) in a Graph:

Algorithm:
---> Initialize a stack and push the starting vertex in it
---> Mark the starting vertex as visited
---> While the stack is not empty
---> Pop a vertex from stack
---> For each unvisited neighbor of the popped vertex complete remaining part
---> If the neighbor is unvisited
---> Mark the neighbor as visited
---> Push the neighbor in the stack


Code Below :::
-------------------------------------------------------------------------------
  
  
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// adjacency matrix representation of the graph
int graph[MAX_VERTICES][MAX_VERTICES];
int vertices;

// visited array to keep track of visited nodes
bool visited[MAX_VERTICES];

void dfs(int vertex) {
    int i;

    // mark current vertex as visited
    visited[vertex] = true;
    printf("%d ", vertex);

    // visit all adjacent vertices
    for (i = 0; i < vertices; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(i);
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

    // initialize visited array
    for (i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    // do DFS starting from vertex 0
    dfs(0);

    return 0;
}
