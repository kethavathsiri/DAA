 #include <stdio.h>
#include <limits.h>
#define MAX 100
int adj[MAX][MAX],u,v;
void prims(int n,int vis[], int par[]) {
int k = n;
    int min;
      vis[0] = 1; 
      //k--;
    while (k > 0) {
        min = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 1) {
                for (int j = 0; j < n; j++) {
                    if (adj[i][j] != -1 && vis[j] == 0) {
                        if (adj[i][j] < min) {
                            min = adj[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }
        vis[v] = 1;
        par[v] = u; 
        k--;
    }
}
int main() {
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
int vis[n], par[n];
 
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
      vis[i] = 0;
      par[i] = -1;
    }
    prims(n, vis, par);
     printf("Edges and their weights in the Minimum Spanning Tree:\n");
    for (int i = 1; i <n; i++) {
        printf("%d - %d : %d\n", par[i], i, adj[i][par[i]]);
    }
    return 0;
}
/*
-1  2  -1  6  -1
2   -1  3   8   5
-1  3  -1  -1   7
6    8  -1  -1  9
-1   5   7   9  -1
*/
