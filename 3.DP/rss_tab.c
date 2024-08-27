//subsets Tabulerform unbounded
#include <stdio.h>

int ss(int n, int s, int wt[n]) {
    int a[n + 1][s + 1];

    // Initialize count array
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= s; ++j) {
            if (j == 0){
                a[i][j]=1;continue;
                }
                 if (i == 0){
                a[i][j] = 0;continue;
                }
            if (wt[i - 1] <= j){
                a[i][j] = a[i][j - wt[i - 1]] + a[i - 1][j];
                }
            else{
                a[i][j] = a[i - 1][j];}
        }
    }

   // return a[n][s];
   printf("Total number of ways to achieve the target sum: %d",a[n][s]);
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
     ss(n, sum, weights);
   // printf("Total number of ways to achieve the target sum: %d\n", ways);
    return 0;
}


