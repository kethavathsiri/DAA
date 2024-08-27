
//0/1 knapsack memorization(unbounded)
#include <stdio.h>
#include <stdlib.h>

int a[1001][1001]; // Assuming maximum values for n and w

int max(int a, int b) {
    return (a > b) ? a : b;
}

int ks(int n, int w, int val[], int wt[]) {
//int a[n+1][w+1];
    if (a[n][w] != -1)
        return a[n][w];

    if (n == 0 || w == 0)
        return a[n][w] = 0;

    if (wt[n - 1] <= w)
        return a[n][w] = max(val[n - 1] + ks(n-1, w - wt[n - 1], val, wt), ks(n - 1, w, val, wt));
    else
        return a[n][w] = ks(n - 1, w, val, wt);
}

int main() {
    int n, w;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &w);

    int val[n], wt[n];
    printf("Enter the values of items:\n");
    for (int i = 0; i < n; ++i)
        scanf("%d", &val[i]);

    printf("Enter the weights of items:\n");
    for (int i = 0; i < n; ++i)
        scanf("%d", &wt[i]);
 //int a[n+1][w+1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= w; ++j) {
            a[i][j] = -1;
        }
    }

    printf("Maximum value that can be obtained: %d\n", ks(n, w, val, wt));

    return 0;
}

