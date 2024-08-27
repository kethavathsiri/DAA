
//substring count
#include<stdio.h>
#include<string.h>
int main(){
int i,j,f,f1,m,n,index,count=0;

char a[100],b[100];
printf("enter the string: ");
scanf("%s",a);
printf("enter the sub string: ");
scanf("%s",b);
m=strlen(a);
n=strlen(b);
f1=0;
for(i=0;i<=m-n;i++){
if(a[i]==b[0]){
f=0;
for(j=0;j<n;j++){
if(b[j]!=a[i+j]){
f=1;break;
}
}	
if(f==0){
f1=1;index=i;
count++;
}
}
}
if(f1==0)
printf("string doesnt match\n");
else
printf("string matches at %d:",index);
printf("\nmatches and  count is %d\n",count);
}







