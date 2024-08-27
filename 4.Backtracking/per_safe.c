//permutaions using issafe
#include<stdio.h>
#include<stdbool.h>
char a[10];
bool isSafe(int k,int i){
for(int j=0;j<k;j++){
if(a[j]==i)
return false;
}
return true;
}
void fill(int k,int n){
if(k==n){
for(int i=0;i<n;i++){
printf("%c",a[i]);
}
//printf("%s",a);
printf("\n");
return;
}
for(char i='a';i<='c';i++){
if(isSafe(k,i)){
a[k]=i;
fill(k+1,n);
}
}
}
int main(){
int n,k=0;
printf("enter the size :");
scanf("%d",&n);
fill(k,n);
return 0;
}

