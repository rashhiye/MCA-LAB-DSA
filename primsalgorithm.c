#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 100

void main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int V[MAX_NODES] = {0};  // visited nodes
    int A[n][n];  // adjacency matrix

    // Read the adjacency matrix
    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
            // If there is no edge between two nodes, assign a big value to it to ignore it
            if (A[i][j] == 0 && i != j)
                A[i][j] = INT_MAX;
        }
    }

    int e = 0;  // number of edges in MST
    int cost = 0;  // total cost of MST
    V[0] = 1;  // start with the first node (0)

    // For each edge in the spanning tree
    while (e < n - 1) {
        int min = INT_MAX;
        int u = -1, v = -1;  // to store the nodes forming the edge

        // For each visited node in the graph
        for (int i = 0; i < n; i++) {
            if (V[i]) {  // If the node is visited
                // Find the smallest edge from the visited node to an unvisited node
                for (int j = 0; j < n; j++) {
                    if (!V[j] && A[i][j] < min) {  // unvisited node and smaller weight
                        min = A[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            // Mark the end of the minimum node as visited and print the edge
            V[v] = 1;  // mark the destination node as visited
            printf("{%d, %d} = %d\n", u, v, min);
            cost += min;
            e++;
        }
    }
    
    printf("Minimum Cost: %d\n", cost);
}
