//binary numbers 
//ouput
/*
000
001
010
011
100
101
110
111
*/
#include<stdio.h>
int a[10];
int count=0;
void per(int,int);
void per(int n,int k){
if(k==n){
for(int i=0;i<n;i++){
printf("%d",a[i]);
}
printf("\n");
count++;
return;
}
for(int i=0;i<2;i++){
a[k]=i;
per(n,k+1);
}
}
int main(){
int n,k=0;
printf("enter the size:");
scanf("%d",&n);
per(n,k);
printf("Total count: %d\n", count);
}



