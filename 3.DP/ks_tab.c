//0/1 knapsack tabulation
//#include <stdio.h>
//#include <stdlib.h>
//no return type in tabulation
 

#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int ks(int n, int w, int wt[], int val[]) {
    int a[n+1][w+1];
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= w; j++) {
            if(i == 0 || j == 0)
                a[i][j] = 0;
            else if(wt[i-1] <= j)
                a[i][j] = max(val[i-1] + a[i-1][j-wt[i-1]], a[i-1][j]);
            else
                a[i][j] = a[i-1][j];
        }
    }
    return a[n][w];
}

int main() {
    int n, w;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];
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

    //int result = ks(n, w, wt, val);
    printf("Maximum value: %d\n", ks(n,w,wt,val));
    return 0;
}


