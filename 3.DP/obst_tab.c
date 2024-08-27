#include<stdio.h>
#include<limits.h>
int sum(int freq[],int i,int j){
int sum=0;
for(int k=i;k<=j;k++){
 sum=sum+freq[k];
 }
 return sum;
 }
 int obst_tab(int freq[],int a[],int n){
int dp[n+1][n+1];

for(int k=0;k<n;k++){
for(int i=1;i<n-k;i++){
int j=i+k;
dp[i][j]=INT_MAX;
if(i==j){
dp[i][j]=freq[i]; continue;
}
 for(int l=i;l<=j;l++){
 int val=dp[i][l-1]+dp[l+1][j]+sum(freq,i,j);
 if(val<dp[i][j]){
 dp[i][j]=val;
 }
 }
 }
 }
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
 int res=printf("%d",obst_tab(freq,0,n));
 }
 






























/*#include<stdio.h>
#include<limits.h>

// Function to calculate the sum of frequencies between indices i and j
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}

// Function to calculate the minimum cost of Optimal BST using tabulation (bottom-up approach)
void obst(int freq[], int n) {
    // dp array to store the minimum cost
    int dp[n+1][n+1];
    // cost array to store cumulative sums of frequencies
    int cost[n+1][n+1];

    // Initialize cost[i][j] as sum of freq[i] to freq[j]
    for (int i = 1; i <= n; i++) {
        dp[i][i] = freq[i];
        cost[i][i] = freq[i];
    }

    // Calculate cost and dp arrays
    for (int l = 1; l < n; l++) {
        for (int i = 1; i <= n - l; i++) {
            int j = i + l;
            dp[i][j] = INT_MAX;
            cost[i][j] = cost[i][j-1] + freq[j];
            for (int k = i; k <= j; k++) {
                int val = ((k > i) ? dp[i][k-1] : 0) + ((k < j) ? dp[k+1][j] : 0) + cost[i][j];
                if (val < dp[i][j]) {
                    dp[i][j] = val;
                }
            }
        }
    }

    // The minimum cost of optimal BST will be stored in dp[1][n]
    printf("Minimum cost of Optimal BST is %d\n", dp[1][n]);
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int freq[n+1];
    printf("Enter the frequencies:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &freq[i]);
    }

    obst(freq, n); // Call the obst function to find the minimum cost

    return 0;
}*/




/*#include<stdio.h>
#include<limits.h>

int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}
void obst(int freq[], int n) {
    int dp[n+1][n+1];
    for (int l = 0; l < n; l++) {
        for (int i = 1; i <= n - l; i++) {
            int j = i + l;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j; k++) {
            if(i==j)
            dp[i][j]=freq[i];
            continue;
                int val = dp[i][k-1] + dp[k+1][j] + sum(freq,i,j);
                if (val < dp[i][j]) {
                    dp[i][j] = val;
                }
            }
        }
    }
    printf("Minimum cost of Optimal BST is %d\n", dp[1][n]);
}
int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);
    int freq[n+1];
    printf("Enter the frequencies:\n");
    for (int i = 1; i <= n; i++) {
    scanf("%d", &freq[i]);
    }
    obst(freq, n);
    return 0;
}*/

