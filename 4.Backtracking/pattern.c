#include <stdio.h>
int main() {
    int n; // Size of the array
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("Invalid size!\n");
        return 1; // Exit with error
    }
    int a[n + 1][n + 1]; // Declare the array
    int k = 1; // Initialize the starting value
    int i, j, l;
    // Initialize all elements of the array to zero
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            a[i][j] = 0;
        }
    }
    // Populate the array
    for (l = 0; l <= n; l++) {
        for (i = 0; i <= n; i++) {
            j = i + l;
            if (j >= 0 && j <= n) { // Check if j is within bounds
                a[i][j] = k++;
            }
        }
    }
    // Display the array
    printf("The generated array is:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

