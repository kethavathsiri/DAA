//dp(sum of subsets->no.of ways with  repetition)
//4.(recursion)
#include<stdio.h>

int ssw(int wt[],int n,int s)
{
    if(s==0)
      return 1;//bcz not considering is also 1 way
     else if(n==0)
       return 0;//no chance to take 
     else if(wt[n-1]<=s)
       return ssw(wt,n,s-wt[n-1])+ssw(wt,n-1,s);//eventhough after considering n will remain same
     else 
       return ssw(wt,n-1,s);
}  


int main()
{
    int i,n,subset[n],sum;

    printf("enter the size:");
    scanf("%d",&n);
    printf("enter the subset values:");
   for(i=0;i<n;i++)
    {
     scanf("%d",&subset[i]);
    }
    printf("enter the total sum:");
    scanf("%d",&sum);

    printf("total no.of ways to get required sum is:%d",ssw(subset,n,sum));


}