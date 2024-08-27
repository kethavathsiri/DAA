//Divide and conquer
#include<stdio.h>
#include<stdlib.h>
int main(){
int i,j,n,t;
printf("enter the size of an array:");
scanf("%d",&n);
int a[n];
printf("enter the elements:\n");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
if(a[i]>a[j]){
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
}
printf("sorted elements\n");
for(i=0;i<n;i++){
printf("%d\n",a[i]);
}
int k,low=0,mid;
printf("enter the searching element:\n");
scanf("%d",&k);
int high=n-1;
while(low<=high){
mid=(low+high)/2;
if(k==a[mid]){
printf("element location is %d",mid);
exit(0);
}

else if(k>a[mid]){
low=mid+1;
}
else{
high=mid-1;
}
}
printf("element is not found");
}



