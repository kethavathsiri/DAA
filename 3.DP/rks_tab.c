//dynamic programing(for 0/1 knap sack->with  repetition)
//tabulation
#include<stdio.h>
int max(int a,int b)
{
     return (a>b)?a:b;
}

int ks(int w,int wt[],int val[],int n)
{
  int a[n+1][w+1];
  int i,j;
  
  for( i=0;i<=n;i++)
  {
    for( j=0;j<=w;j++)
    {
    if(i==0||j==0)
      a[i][j]=0;
    else if(wt[i-1]<=j)
      a[i][j]= max(val[i-1]+a[i][j-wt[i-1]] , a[i-1][j]);
       else 
          a[i][j]=a[i-1][j];
    }
  }
 return a[n][w];
}

int main()
{
     int i,profit,n,w,wt[n],val[n];
     printf("enter the knapsack size:");
     scanf("%d",&n);
     printf("enter the weights of the knapsack:");
     for(i=0;i<n;i++)
     {
        scanf("%d",&wt[i]);
     }
     printf("enter the values for each weight:");
     for(i=0;i<n;i++)
     {
        scanf("%d",&val[i]);
     }
     printf("enter the total capacity of the knapsack:");
     scanf("%d",&w);
     
     profit=ks(w,wt,val,n);
     printf("maximum profit we get is %d:",profit);
  

}