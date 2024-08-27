//converting fibnocci series to dp (memorizaton)
#include<stdio.h>

int fib(int, int*);

int main() {
    int n, i;
    printf("Enter the size: \n");
    scanf("%d", &n);

    int a[n + 1]; // Array to store Fibonacci numbers

    for (i = 1; i <= n; i++) {
        a[i] = -1; // Initialize all elements to -1
    }

    printf("Fibonacci series:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", fib(i, a)); // Calculate and print Fibonacci numbers
    }
     printf("\nnth term :%d",fib(n,a));
    
    return 0;
}

int fib(int n, int* a) {
    if(n==0||n==1)
    return a[n]=1;

    if (a[n] != -1) {
        return a[n]; // If already calculated, return the stored value
    } else {
        return a[n] = fib(n - 1, a) + fib(n - 2, a); // Calculate and store the Fibonacci number
    }
}




