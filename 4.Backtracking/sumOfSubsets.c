//sum of subsets using backtracking
/*#include <stdio.h>
int count = 0;
void print(int n, int wt[], int a[]) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            printf("%d ", wt[i]);
        }
        printf("}");
    }

    printf("{ ");
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            printf("%d ", i);  // Print the index instead of the value
        }
        printf("}\n");
    }
    
}
    

void fill(int n, int k, int wt[], int a[], int s) {
    if(k == n) {
        int subsetSum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                subsetSum += wt[i];
            }
        }
        if (subsetSum == s) {
            count++;
            print(n, wt, a);
        }
        return;
    }
    a[k] = 0;
    fill(n, k + 1, wt, a, s);
    a[k] = 1;
    fill(n, k + 1, wt, a, s);
}
int main() {
    int n, s;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int wt[n], a[n];
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }
    printf("Enter the sum limit: ");
    scanf("%d", &s);
    fill(n, 0, wt, a, s);
    printf("Number of subsets with total weight equal to %d: %d\n", s, count);
    return 0;
}*/

#include <stdio.h>

int count = 0;

// Function to print the subset values and their indices
void print(int n, int wt[], int a[]) {
    printf("Subset values: { ");
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            printf("%d ", wt[i]);
        }
    }
    printf("}\n");

    printf("Subset indices: { ");
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            printf("%d ", i);  // Print the index
        }
    }
    printf("}\n");
}

// Recursive function to find all subsets that sum to a given value
void fill(int n, int k, int wt[], int a[], int s) {
    if (k == n) {
        int subsetSum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                subsetSum += wt[i];
            }
        }
        if (subsetSum == s) {
            count++;
            print(n, wt, a);
        }
        return;
    }
    a[k] = 0;
    fill(n, k + 1, wt, a, s);
    a[k] = 1;
    fill(n, k + 1, wt, a, s);
}

int main() {
    int n, s;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    int wt[n], a[n];
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }
    
    printf("Enter the sum limit: ");
    scanf("%d", &s);
    
    // Initialize the array a with zeros
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
    
    fill(n, 0, wt, a, s);
    
    printf("Number of subsets with total weight equal to %d: %d\n", s, count);
    return 0;
}




