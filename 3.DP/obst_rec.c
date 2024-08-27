//recursion
#include<stdio.h>
#include<limits.h>
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}
int obst(int freq[], int i, int j) {
    if (i > j) {
        return 0; // Base case: no nodes in subtree
    }
    if (i == j) {
        return freq[i]; // Base case: one node in subtree
    }
    int min = INT_MAX;
    int val;

    for (int k = i; k <= j; k++) {
        val = obst(freq, i, k - 1) + obst(freq, k + 1, j) + sum(freq, i, j);
        if (val < min) {
            min = val;
        }
    }
    return min;
}
int main(){
  int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);
    int freq[n];
    printf("Enter the frequencies:\n");
    for (int i = 1; i <=n; i++) {
    scanf("%d", &freq[i]);
    }
    printf("Minimum cost of Optimal BST is %d\n", obst(freq, 0, n));
    return 0;
}
