#include<stdio.h>
//#include<stdbool.h>
void ss(int,int,int[]);
void main(){
int s,n,i;
printf("enter the number of weights");
scanf("%d",&n);
printf("enter the sum of weights");
scanf("%d",&s);
int wt[n];
printf("enter the weights");
for(i=0;i<n;i++){
scanf("%d",&wt[i]);}
ss(n,s,wt);}
void ss(int n,int s,int wt[n]){
int a[20][20];
int i,j;
for(i=0;i<=n;i++){
for(j=0;j<=s;j++){
if(j==0){
a[i][j]=1;
continue;}
if(i==0){
a[i][j]=0;
continue;}
if(wt[i-1]<=j)
a[i][j]=(a[i-1][j-wt[i-1]]||a[i-1][j]);
else
a[i][j]=a[i-1][j];}}
printf("%d",a[n][s]);}


/*#include<stdio.h>
void ss(int,int,int[]);
void main(){
int s,n,i;
printf("enter the number of weights");
scanf("%d",&n);
printf("enter the sum of weights");
scanf("%d",&s);
int wt[n];
printf("enter the weights");
for(i=0;i<n;i++){
scanf("%d",&wt[i]);}
ss(n,s,wt);}
void ss(int n,int s,int wt[n]){
int a[20][20];
int i,j;
for(i=0;i<=n;i++){
for(j=0;j<=s;j++){
if(j==0){
a[i][j]=true;
continue;}
if(i==0){
a[i][j]=false;
continue;}
if(wt[i-1]<=j)
a[i][j]=(a[i-1][j-wt[i-1]]||a[i-1][j]);
else
a[i][j]=a[i-1][j];}}
printf("%d",a[n][s]);}*/
