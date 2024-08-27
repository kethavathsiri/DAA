//dp(for coin change->no.of ways)
//5c.(tabulation)

#include<stdio.h>

int ssw(int n,int s,int wt[])
{
 int i,j,a[n+1][s+1];
 for(i=0;i<=n;i++)
 {
     for(j=0;j<=s;j++)
     {
        
        if(j==0)
         a[i][j]=1; 
         else if(i==0)
         a[i][j]=0; 
         else if(wt[i-1]<=j)
            a[i][j]=a[i-1][j-wt[i-1]]+a[i-1][j];
          else
            a[i][j]=a[i-1][j];
     }
 }
  return a[n][s];
}

int main()
{
    int i,j,n,sum;
    printf("enter the size:");
    scanf("%d",&n);
    int coins[n];
    printf("enter the coin values:");
    for(i=0;i<n;i++)
    {    
        scanf("%d",&coins[i]);
    }
    printf("enter the total sum:");
    scanf("%d",&sum);

printf("total no.of ways to pick coins are:%d\n", ssw(n,sum,coins));
}
