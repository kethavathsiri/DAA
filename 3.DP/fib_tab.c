//converting fibnocci series to iterative

#include<stdio.h>
void fib(int n, int a[]) {
    int i;
    for (i = 0; i <= n; i++) {
        if (i == 0 || i == 1)
            a[i] = 1;
        else
            a[i] = a[i - 1] + a[i - 2];
            printf("%d",a[i]);
    }
    printf("\n%d",a[n]);
   
}
int main(){
int n,i,j;
printf("enter the size:");
scanf("%d",&n);
int a[n+1];
fib(n,a);
}














/*void fib(int, int*);

int main() {
    int n, i;
    printf("Enter the size:");
    scanf("%d", &n);
    
    int a[n + 1]; // Array to store Fibonacci series
    
    printf("Fibonacci series:\n");
    fib(n, a); // Call fib() function to calculate Fibonacci series
    
    /*for (i = 0; i < n; i++) {
        printf("%d ", a[i]); // Print Fibonacci series
    }
    printf("\nnth term of a fibonacci series:%d\n",a[n]);
    return 0;
}

void fib(int n, int* a) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == 0 || i == 1)
            a[i] = 1;
        else
            a[i] = a[i - 1] + a[i - 2];
            printf("%d",a[i]);
    }
   
}*/

    




