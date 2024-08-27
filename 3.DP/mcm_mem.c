#include<stdio.h>
#include<limits.h>
int a[10];
int mcm(int i,int j)
{
//int a[10];
int val,min;
int dp[j][j];
if(i==j){
return dp[i][j]=0;}
if(dp[i][j]==-1){
return dp[i][j];
}
min=INT_MAX;
for(int k=i;k<j;k++){
val=mcm(i,k)+mcm((k+1),j)+(a[i-1]*a[k]*a[j]);
if(val<min){
min=val;
}
}
return dp[i][j]=min;
}
int main()
{
int n;
printf("enter the size:");
scanf("%d",&n);
printf("enter the matrices sizes:");
//int a[n+1];
for(int i=0;i<=n;i++)
{
scanf("%d",&a[i]);
}
int r=mcm(1,n);
printf("the minimum ways:%d",r);}






/*#include <stdio.h>
#include <limits.h>

int mcm(int i, int j, int a[], int dp[][11]) { // dp should have size [i][j+1]
    if (i == j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    int min = INT_MAX;
    for (int k = i; k < j; k++) {
        int val = mcm(i, k, a, dp) + mcm(k + 1, j, a, dp) + (a[i - 1] * a[k] * a[j]);
        if (val < min) {
            min = val;
        }
    }
    
    return dp[i][j] = min;
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    
    int a[n + 1];
    printf("Enter the dimensions of the matrices: ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    int dp[n + 1][n + 1]; // Define DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = -1; // Initialize DP table with -1 (indicating not computed)
        }
    }
    
    int min_cost = mcm(1, n, a, dp);
    
    printf("Minimum cost of matrix multiplication: %d\n", min_cost);
    
    return 0;
}*/

