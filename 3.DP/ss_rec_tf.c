//subsets in True/False
//Recursion
#include <stdio.h>
#include <stdbool.h>

int ss(int n, int s, int wt[]) {
    if (s == 0)
        return true; // Subset found with sum equal to s
    if (n == 0)
        return false; // No subset can be formed (array is empty and sum should be something

    // If the current element is greater than the sum, exclude it
    if (wt[n - 1] > s)
        return ss(n - 1, s, wt);
    else
        // Include the current element or exclude it and move to the next element
        return ss(n - 1, s - wt[n - 1], wt) + ss(n - 1, s, wt);
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
    printf("Number of ways to achieve the target sum: %d\n", count);

    return 0;
}




