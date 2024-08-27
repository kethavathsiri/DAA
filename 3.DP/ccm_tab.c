////min no of coins Tabulation
#include<stdio.h>
//#include<math.h>
#include<limits.h>
//int cc(int,int,int[]);
int minm(int,int);
int CCM(int n,int s,int wt[])
{
int a[n+1][s+1];
for(int i=0;i<=n;i++)
{
for(int j=0;j<=s;j++)
{
if(j==0)
a[i][j]=0;
else if(i==0)
//a[i][j]=999999;
a[i][j]=INT_MAX-1000;
else if(wt[i-1]<=j)
{
a[i][j] = minm(1 + a[i][j - wt[i - 1]], a[i - 1][j]);
}
            else{
                a[i][j] = a[i - 1][j];
        }
    }}
   return a[n][s];
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
printf("min value of a bag using coin change %d ",CCM(n,s,wt));
return 0;
}
int minm(int a,int b)
{
return (a<b)?a:b;
}
