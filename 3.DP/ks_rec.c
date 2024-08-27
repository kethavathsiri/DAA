//0/1 knapsack with recursion
#include<stdio.h>
int knapsack(int, int[], int[], int);//items,weights,values,weight
int max(int, int);

int main() {
    int n, w; // n = number of items, w = bag weight
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the bag weight: ");
    scanf("%d", &w);

    int wt[n], val[n]; 
    printf("Enter the weights of items:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }
    
    printf("Enter the values of items:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }
    printf("Maximum value in knapsack: %d\n", knapsack(n, wt, val, w));

    return 0;
}


int knapsack(int n, int wt[], int val[], int W) {
    
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapsack(n - 1, wt, val, W);
    else
        return max(val[n - 1] + knapsack(n - 1, wt, val, W - wt[n - 1]), knapsack(n - 1, wt, val, W));
}
int max(int a, int b) {
    return (a > b) ? a : b;
}



