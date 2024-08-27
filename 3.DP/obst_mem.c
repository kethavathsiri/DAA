//memorization
/*#include<stdio.h>
#include<limits.h>
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}
int obst(int freq[], int i, int j) {
int a[i][i];
    if(a[i][j]==-1){
    return a[i][j];
    }
    if (i > j) {
        return a[i][j]=0; // Base case: no nodes in subtree
    }
    if (i == j) {
        return a[i][j]=freq[i]; // Base case: one node in subtree
    }
    int min = INT_MAX;
    int val;

    for (int k = i; k <= j; k++) {
        val = obst(freq, i, k - 1) + obst(freq, k + 1, j) + sum(freq, i, j);
        if (val < min) {
            min = val;
        }
    }
    return a[i][j]=min;
}

int main(){
  int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int freq[n];
    printf("Enter the frequencies:\n");
    for (int i = 1; i <=n; i++) {
        scanf("%d", &freq[i]);
    }
    printf("Minimum cost of Optimal BST is %d\n", obst(freq, 0, n));
    return 0;
}*/


#include<stdio.h>
#include<limits.h>
int sum(int freq[],int i,int j){
int sum=0;
for(int k=i;k<=j;k++){
 sum=sum+freq[k];
 }
 return sum;
 }
int obst(int freq[],int i,int j){
int a[i][i];
if(a[i][j]==-1){
return a[i][j];}
if(i>j){return a[i][j]=0;}
 if(i==j){
 return a[i][j]=freq[i];
 }
 int min=INT_MAX;
 for(int k=i;k<=j;k++){
 int val=obst(freq,i,k-1)+obst(freq,k+1,j)+sum(freq,i,j);
 if(val<min){
 min=val;
 }
 }
 return a[i][j]=min;
 }
 int main(){
 int i,n;
 printf("enter the size:");
 scanf("%d",&n);
 int freq[n];
 printf("enter the frequency:");
 for(i=1;i<=n;i++){
 scanf("%d",&freq[i]);
 }
 int a[n+1][n+1];
 for(i=1;i<=n;i++){
 for(int j=1;j<=n;j++){
 a[i][j]=-1;
 }
 }
 int res=printf("%d",obst(freq,0,n));
 }
 
 
 
