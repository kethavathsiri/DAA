////converting fibonocci series to recursion
#include<stdio.h>
int fib(int);
int main(){
int n,i;
printf("enter the n value:");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("%d\t",fib(i));
}
printf("\n%d",fib(n));
}
int fib(int n){
if(n==0||n==1)
return 1;
else
return fib(n-1)+fib(n-2);
}
