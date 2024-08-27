//mcm recurrsion
#include<stdio.h>
#include<limits.h>
int a[10];
int mcm(int i,int j){
if(i==j)
return 0;
int min=INT_MAX;
for(int k=i;k<j;k++){
int val=mcm(i,k)+mcm(k+1,j)+a[i-1]*a[k]*a[j];
if(val<min)
min=val;
}
return min;
}
int main(){
int n,i;
printf("enter the size of matrix:");
scanf("%d",&n);
printf("enter the dimensions of matrix:");
for( i=0;i<=n;i++){
scanf("%d",&a[i]);
}
int res=mcm(1,n);
printf("%d\n",res);
return 0;
}

