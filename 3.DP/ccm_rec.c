////min no of coins recursion
#include<stdio.h>
#include<limits.h>
//int ccm(int,int,int[]);
//int min(int,int);

int min(int a,int b){
if(a<b)
return a;
else
return b;}

int ccm(int n,int s,int wt[n]){
  if(s==0)
  return 0;
 if(n==0)
 return INT_MAX-1000;
if(wt[n-1]<=s){
return min(1+ccm(n,s-wt[n-1],wt),ccm(n-1,s,wt));}
else
return ccm(n-1,s,wt);}

void main(){
int n,s,i;
printf("enter the number of weights:");
scanf("%d",&n);
int wt[n];
printf("enter the weights:");
for(i=0;i<n;i++){
scanf("%d",&wt[i]);}
printf("enter the weight sum:");
scanf("%d",&s);
printf("%d\n",ccm(n,s,wt));}

 

 
