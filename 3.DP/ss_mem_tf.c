//sum of subsets memorization using True/False
#include<stdio.h>
int ss(int,int,int[]);
void main(){
int s,n,i;
printf("enter the number of weights");
scanf("%d",&n);
printf("enter the sum of weights");
scanf("%d",&s);
int wt[n];
printf("enter the weights");
for(i=0;i<n;i++){
scanf("%d",&wt[i]);}
printf("%d",ss(n,s,wt));}
int ss(int n,int s,int wt[n]){
int a[10][10];
if(s==0){
return a[n][s]=1;}
if(n==0){
return a[n][s]=0;}
if(wt[n-1]<=s){
return a[n][s]=ss(n-1,s-wt[n-1],wt)||ss(n-1,s,wt);}
else{
return a[n][s]=ss(n-1,s,wt);}}


