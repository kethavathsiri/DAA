#include <stdio.h>
#include <limits.h>

#define MAX 100

int a[MAX][MAX]; // Adjacency matrix
int p[MAX];      // Parent array for Union-Find
int rank[MAX];   // Rank array for Union-Find

void findminedge(int *u, int *v, int n) {
    int min = INT_MAX;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (a[i][j] < min && a[i][j] != -1) {
                min = a[i][j];
                *u = i;
                *v = j;
            }
        }
    }
}
int findparent(int k) {
    if (p[k] != k) {
        p[k] = findparent(p[k]); // Path compression
    }
    return p[k];
}

int checkloop(int u, int v) {
    int pu = findparent(u);
    int pv = findparent(v);
    return pu != pv;
}


void union_sets(int u, int v) {
    int pu = findparent(u);
    int pv = findparent(v);
    if (pu != pv) {
        // Union by rank
        if (rank[pu] > rank[pv]) {
            p[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            p[pu] = pv;
        } else {
            p[pv] = pu;
            rank[pu]++;
        }
    }
}



void kruskals(int n) {
    int u, v;
    int k = n;
    // Initialize the Union-Find data structure
    for (int i = 0; i < n; i++) {
        p[i] = i;
        rank[i] = 0;
    }

    printf("Edges in the MST with their weights:\n");
    while (k > 1) {
        findminedge(&u, &v, n);
        if (checkloop(u, v)) {
         printf("Edge: %d-%d Weight: %d\n", u, v, a[u][v]);
            //printf("%d %d\n", u, v);
            union_sets(u, v);
            k--;
        }
        a[u][v] = -1; // Mark this edge as used
    }
}

int main() {
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use -1 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    kruskals(n);

    return 0;
}
//input
/*Enter the number of vertices: 6
Enter the adjacency matrix (use -1 for no edge):
0 2 -1 -1 -1 3
2 0 4 -1 3 3
-1 4 0 5 -1 4
-1 -1 5 0 8 -1
-1 3 -1 8 0 7
3 3 4 -1 7 0
Edges in the MST with their weights:
Edge: 0-1 Weight: 2
Edge: 0-5 Weight: 3
Edge: 1-4 Weight: 3
Edge: 1-2 Weight: 4
Edge: 2-3 Weight: 5*/

    
