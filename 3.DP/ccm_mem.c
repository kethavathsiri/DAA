//min no of coins Memeorization
#include<stdio.h>
//#include<math.h>
#include<limits.h>
//int cc(int,int,int[]);
int minm(int,int);
int CCM(int n,int s,int wt[])
{
int a[n+1][s+1];
if(s==0)
return a[n][s]=0;
if(n==0)
//return a[n][s]=999999;
return a[n][s]=INT_MAX-10000;
if(wt[n-1]<=s)
{
return a[n][s]=minm(1+CCM(n, s-wt[n-1], wt), CCM(n-1, s, wt));
}else {
return a[n][s]=CCM(n-1,s,wt);
}
}
int main()
{
int n,s;
printf("enter the size:");
scanf("%d",&n);
printf("enter the sum of bag:");
scanf("%d",&s);
int wt[n];
printf("enter the items in a bag:");
for(int i=0;i<n;i++)
{
scanf("%d",&wt[i]);
}
printf("min value of a bag using coin change %d:",CCM(n,s,wt));
return 0;
}
int minm(int a,int b)
{
return (a<b)?a:b;
}
