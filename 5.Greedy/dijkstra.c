#include <stdio.h>
#include <limits.h>

#define MAX_NODES 100

int adj[MAX_NODES][MAX_NODES]; // Adjacency matrix

int findminnode(int visited[], int cost[], int n) {
    int min = INT_MAX, index = -1;
    for (int i = 0; i < n; i++) {
        if (visited[i] == -1 && cost[i] < min) { 
            min = cost[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int n, int parent[], int visited[], int cost[]) {
    int k = n;

    while (k > 0) {
        int i = findminnode(visited, cost, n);
        
        // If no valid index is found, break out of the loop
        if (i == -1) break;
        
        visited[i] = 1;
        for (int j = 0; j < n; j++) {
            if (adj[i][j] != -1 && visited[j] == -1) {
                if (cost[j] > cost[i] + adj[i][j]) {
                    cost[j] = cost[i] + adj[i][j];
                    parent[j] = i;
                }
            }
        }
        k--;
    }

    // Print the costs
    printf("Vertex \tparent\tCost from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t%d\t%d\n", i,parent[i],cost[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix along with weights (-1 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int visited[n], parent[n], cost[n];

    for (int i = 0; i < n; i++) {
        visited[i] = -1; // Mark all nodes as unvisited initially
        parent[i] = 0;
        cost[i] = INT_MAX;
    }
    cost[0] = 0;  // Starting node has 0 cost
    parent[0]=0;

    dijkstra(n, parent, visited, cost);

    // Calculate and print the sum of all costs
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (cost[i] < INT_MAX) { // Only sum valid costs
            sum += cost[i];
        }
    }

    printf("Sum of all shortest path costs: %lld\n", sum);

    return 0;
}


























/*
1  4  -1  -1  -1  -1  -1  8  -1
4   -1  8   -1  -1  -1  -1  11 -1
-1  8   -1  7   -1  4   -1  -1  2
-1  -1  7   -1  9   14  -1  -1  -1
-1  -1  -1  9   -1  10  -1  -1  -1
-1  -1  4   14  10  -1  2   -1  -1
-1  -1  -1  -1  -1  2   -1  1   6
8   11  -1  -1  -1  -1  1   -1  7
-1  -1  2   -1  -1  -1  6   7   -1
Vertex 	Cost from Source
0 	0
1 	4
2 	12
3 	19
4 	21
5 	11
6 	9
7 	8
8 	14
*/

/*
-1 2 -1 -1 -1 8
2 -1 9 -1 7 4
-1 9 -1 3 -1 2
-1 -1 3 -1 4 -1
-1 7 -1 4 -1 3
8 4 2 -1 3 -1
Vertex 	Cost from Source
0 	0
1 	2
2 	8
3 	11
4 	9
5 	6
*/

