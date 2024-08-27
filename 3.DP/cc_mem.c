 //dp(coin change->no.of ways)
//5a.coin change(memorization)
#include<stdio.h>
#define MAX_SIZE 100
 int a[100][100];
int ccw(int n,int s,int wt[])
{

    if(a[n][s]!=-1)
     return a[n][s];
    if(s==0)
     return a[n][s]=1;
    if(n==0)
     return a[n][s]=0;
    else if(wt[n-1]<=s)
      return a[n][s]=ccw(n-1,s-wt[n-1],wt)+ccw(n-1,s,wt);
    else 
      return a[n][s]=ccw(n-1,s,wt);

}

int main()
{
    int i,j,n,coins[n],sum;
    printf("enter the no.of coins:");
    scanf("%d",&n);
     printf("enter the total sum:");
    scanf("%d",&sum);
    printf("enter the coin changes:");
    for(i=0;i<n;i++)
    {    
        scanf("%d",&coins[i]);
    }
    for(i=0;i<MAX_SIZE ;i++)
    {
      for(j=0;j<MAX_SIZE ;j++)
      {
        a[i][j]=-1;
      }}

int total=ccw(n,sum,coins);
printf("total no.of ways to pick coins are:%d\n",total);
}
