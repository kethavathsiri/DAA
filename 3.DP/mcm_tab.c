#include<stdio.h>
#include<limits.h>
int mcm_tab(int a[],int n){
int dp[n+1][n+1];
for(int k=0;k<=n-1;k++){
for(int i=1;i<=n-k;i++){
int j=i+k;
dp[i][j]=INT_MAX;
if(i==j){
dp[i][j]=0; continue;
}
 for(int l=i;l<=j-1;l++){
 int val=dp[i][l]+dp[l+1][j]+(a[i-1]*a[j]*a[l]);
 if(val<dp[i][j]){
 dp[i][j]=val;
 }
 }
 }
 }
 printf("%d ",dp[1][n]);
 }
 int main(){
 int n,j,i;
 printf("enter the size :");
 scanf("%d",&n);
 int a[n+1];
 printf("enter the dimensions:");
 for(i=0;i<=n;i++){
  scanf("%d",&a[i]);
  }
  mcm_tab(a,n);
  }







