#include <stdio.h>
#include <stdlib.h> // for abs function
int a[100];

int isSafe(int k, int i, int n) {
    for (int j = 0; j < k; j++) {
        if (a[j] == i) // check column
            return 0;
        if (abs(k - j) == abs(i - a[j])) // check diagonal
           return 0;
    }
    return 1;
}
void nq(int n, int k) {
    if (k == n) {
        // Print the solution
        printf("[ ");
        for (int i = 0; i <n; i++) {
            printf("%d ", a[i]);
        }
        printf("]\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isSafe(k, i, n)) {
            a[k] = i;
            nq(n, k + 1);
        }
    }
}
int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    nq(n, 0);
    return 0;
}

 
  
