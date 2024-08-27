
//substring
#include<stdio.h>
#include<string.h>
int Reverse(char a[],char b[]){
int j=0,i;
int m=strlen(a);
int n=strlen(b);
/*for(i=0;i<m;i++){
for(j=0;j<n;j++){
if(a[i+j]!=b[n-1-j]){
break;*/
for(i=m-1;i>=0&&j<n;i--){
if(a[i]==b[j]){
j++;
}
}
if(j==n){
return 1;//reverse string is found
}
else{
return 0;//reverse string is not found
}
}
int main(){
int i,j,f,f1,m,n,index;
char a[100],b[100];
printf("enter the string: ");
scanf("%s",a);
printf("enter the sub string: ");
scanf("%s",b);
if(Reverse(a,b)){
printf("substring found in superstring\n");
}
else{
printf("substring not found in superstring\n");
}
}











