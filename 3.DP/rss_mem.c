//sum of subsets memorization
#include <stdio.h>

#define MAX_N 100
#define MAX_S 100

int a[MAX_N][MAX_S]; // Global array to store memoized values

int ss(int n, int s, int wt[]) {
    if (a[n][s] != -1)
        return a[n][s];
    if (s == 0)
        return a[n][s] = 1;
    if (n == 0)
        return a[n][s] = 0;
    if (wt[n - 1] <= s)
        return a[n][s] = ss(n, s - wt[n - 1], wt) + ss(n - 1, s, wt);
    else
        return a[n][s] = ss(n - 1, s, wt);
}
int main() {
    int n, sum;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int weights[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i)
        scanf("%d", &weights[i]);

    printf("Enter the target sum: ");
    scanf("%d", &sum);
    // Initialize memoization array with -1
    for (int i = 0; i < MAX_N; ++i)
        for (int j = 0; j < MAX_S; ++j)
            a[i][j] = -1;
    int ways = ss(n, sum, weights);
    printf("Total number of ways to achieve the target sum: %d\n", ways);
    return 0;
}

