//dp(for sum of subsets->with repetition)
//4c.(tabulation)

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
            a[i][j]=a[i][j-wt[i-1]]+a[i-1][j];//i remains same in the case of considering
          else
            a[i][j]=a[i-1][j];

     }
 }
  return a[n][s];
}

int main()
{
    int i,j,n,coins[n],sum;
    printf("enter the size of subsets:");
    scanf("%d",&n);
    printf("enter the subset values:");
    for(i=0;i<n;i++)
    {    
        scanf("%d",&coins[i]);
    }
    printf("enter the total sum:");
    scanf("%d",&sum);

printf("total no.of ways to get required sum are:%d ", ssw(n,sum,coins));
}