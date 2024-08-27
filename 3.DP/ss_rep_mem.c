 //dp(sum of subsets->without repetition)
//4b.(memorization)
#include<stdio.h>
#define MAX_SIZE 100
 int a[100][100];
int ssw(int n,int s,int wt[])
{

    if(a[n][s]!=-1)
     return a[n][s];
    if(s==0)
     return a[n][s]=1;
    else if(n==0)
     return a[n][s]=0;
    else if(wt[n-1]<=s)
      return a[n][s]=ssw(n,s-wt[n-1],wt)+ssw(n-1,s,wt);
    else 
      return a[n][s]=ssw(n-1,s,wt);

}

int main()
{
    int i,j,n,subset[n],sum;
    printf("enter the subset size:");
    scanf("%d",&n);
    printf("enter the subset values:");
    for(i=0;i<n;i++)
    {    
        scanf("%d",&subset[i]);
    }
    printf("enter the total sum:");
    scanf("%d",&sum);

    for(i=0;i<MAX_SIZE ;i++)
    {
      for(j=0;j<MAX_SIZE ;j++)
      {
        a[i][j]=-1;
      }}

int total=ssw(n,sum,subset);
printf("total no.of ways to get the required sum is:%d",total);
}