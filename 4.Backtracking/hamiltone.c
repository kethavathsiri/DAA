#include<stdio.h>
#include<stdbool.h>
#define MAX 100
int adj[MAX][MAX],a[10];
int issafe(int i,int k,int n){
for(int j=0;j<k;j++){
 if(a[j]==i){
 return 0;
 }
 }
 if(k>0&&adj[a[k-1]][i]==0){
 return 0;
 }
 if(k==n-1&&adj[i][a[0]]==0){
 return 0;
 }
 return 1;
 }
 bool hamil(int n,int k){
  if(n==k){
  for(int i=0;i<=n;i++){
  printf("%d",a[i]);
  }
  
  return true;
  }
  for(int i=0;i<n;i++){
  if(issafe(i,k,n)){
  a[k]=i;
        if(hamil(n,k+1)){
           return true;
             a[k]=-1;
  }
  }
  }
  return false;
  }
  int main(){
  int i,j,n;
  printf("enter the matrix size:");
  scanf("%d",&n);
  printf("enter the matrix:\n");
  for(i=0;i<n;i++){
  for(j=0;j<n;j++){
  scanf("%d",&adj[i][j]);
  }
  }
  
  for(i=0;i<n;i++){
  a[i]=-1;
  }
  a[0] = 0;
  if(!hamil(n,1)){
  printf("no hamilton cycle is formed");
  return 0;
  }
  }
