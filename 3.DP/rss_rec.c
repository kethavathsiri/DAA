
//subsets with recursion
#include <stdio.h>

int ss(int n, int s, int wt[]) {
    if (s == 0)
        return 1;
    if (n == 0)
        return 0;

    if (wt[n - 1] <= s) {
        return ss(n, s - wt[n - 1], wt) + ss(n - 1, s, wt);
    } else {
        return ss(n - 1, s, wt);
    }
}
int main() {
    int n, s;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int wt[n];
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; ++i)
        scanf("%d", &wt[i]);

    printf("Enter the target sum: ");
    scanf("%d", &s);

    int count = ss(n, s, wt);
    printf("Number of subsets with sum equal to %d: %d\n", s, count);

    return 0;
}


