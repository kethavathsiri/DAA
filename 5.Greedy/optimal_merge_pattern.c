#include <stdio.h>

#define MAX_SIZE 1000  // Define a maximum size for the array

// Function to sort the array in descending order
void sort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    printf("After merge, pattern: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Function to calculate the optimal merge cost
int optimalmerge(int a[], int n) {
    int res = 0;
    while (n > 1) {
        sort(a, n);
        int val = a[n - 1] + a[n - 2];
        a[n - 2] = val;
        res += val;
        n--;
    }
    return res;
}

int main() {
    int a[MAX_SIZE];
    int n;

    printf("Enter the size: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Size exceeds the maximum allowed size of %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Final result: %d\n", optimalmerge(a, n));

    return 0;
}

