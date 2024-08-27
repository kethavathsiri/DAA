//min max in 2d array
#include <stdio.h>
#include <limits.h>

#define MAX 100

int a[MAX][MAX];

void find_min_max(int n, int *min_u, int *min_v, int *max_u, int *max_v) {
    int min = INT_MAX;
    int max = INT_MIN;

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
                *min_u = i;
                *min_v = j;
            }
            if (a[i][j] > max) {
                max = a[i][j];
                *max_u = i;
                *max_v = j;
            }
        }
    }
}

int main() {
    int i, j, n;
    printf("Enter the size of the 2D array: ");
    scanf("%d", &n);

    printf("Enter the elements of the %dx%d array:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int min_u, min_v, max_u, max_v;
    find_min_max(n, &min_u, &min_v, &max_u, &max_v);

    printf("Minimum element is at position (%d, %d) with value %d\n", min_u, min_v, a[min_u][min_v]);
    printf("Maximum element is at position (%d, %d) with value %d\n", max_u, max_v, a[max_u][max_v]);

    return 0;
}

