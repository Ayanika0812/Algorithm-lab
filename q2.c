#include <stdio.h>

#define MAX_SIZE 100

// Function to display adjacency list
void displayAdjacencyList(int adjacencyMatrix[][MAX_SIZE], int n) {
    // Traverse each row of the matrix
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i);

        // Traverse each column of the row
        for (int j = 0; j < n; j++) {
            // If there is an edge from vertex i to vertex j
            if (adjacencyMatrix[i][j] == 1) {
                printf("%d ", j);
            }
        }

        printf("\n");
    }
}

int main() {
    int n;
    int adjacencyMatrix[MAX_SIZE][MAX_SIZE];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("\nAdjacency List:\n");
    displayAdjacencyList(adjacencyMatrix, n);

    return 0;
}