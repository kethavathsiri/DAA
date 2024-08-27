#include<stdio.h>
int w;
int max = 0;
void print(int n, int wt[], int val[], int a[]) {
    int ws = 0, vs = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            ws += wt[i];
            vs += val[i];
        }
    }
    if (ws <= w) {
        if (max < vs)
            max = vs;
    }
}
void fill(int n, int k, int wt[], int val[], int a[]) {
    if (k == n)
        print(n, wt, val, a);
    else {
        a[k] = 0;
        fill(n, k + 1, wt, val, a);
        a[k] = 1;
        fill(n, k + 1, wt, val, a);
    }
}
int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int wt[n], val[n], a[n];
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }
    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }
    printf("Enter the weight limit of the knapsack: ");
    scanf("%d", &w);
    fill(n, 0, wt, val, a);
    printf("Maximum value: %d\n", max);
    return 0;
}

