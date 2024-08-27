//permutations to print 
/*abc
  acb
  bac
  bca
  cab
  cba*/
                    
#include<stdio.h>
void per(char a[],int pos,int n){
if(pos==n){
for(int i=0;i<n;i++){
printf("%c",a[i]);
}
printf("\n");
//return;
}
for(char i='a';i<='c';i++){
int f=0;
for(int k=0;k<pos;k++){
if(a[k]==i){
f=1;
break;
}
}
if(f==0){
a[pos]=i;
per(a,pos+1,n);
}
}
}
int main(){
int n=3;
char a[n];
per(a,0,n);
}



