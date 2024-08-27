//merge sort
#include<stdio.h>
void merge(int arr[20],int low,int mid ,int high){
 int x[20];
 int i = low,j = mid+1,k = low ;
 while(i<=mid && j <= high){
  if(arr[i]<arr[j]){
   x[k] = arr[i];
   i++;
   k++;}
 else{
  x[k] = arr[j];
  j++;
  k++;}}

  while(i<=mid){
   x[k] = arr[i];
   i++;
   k++;}
  while(j<=high){
   x[k] = arr[j];
   j++;
   k++;}
  for(i=low;i<=high;i++){
   arr[i] = x[i];}}


void divide(int arr[20],int low,int high){
 int mid;
 if(low<high){
  mid = (low+high)/2;
  divide(arr,low,mid);
  divide(arr,mid+1,high);
  merge(arr,low,mid,high);}}
  
int main(){
 int arr[20],i,count;
 printf("enter how many elemnts are you going to enter ?: ");
 scanf("%d",&count);
 printf("enter  %d elemnts: ",count);
 for(i=0;i<count;i++){
  scanf("%d",&arr[i]);}
  divide(arr,0,count-1);
  printf("sorted order elemnts\n");
 for(i=0;i<count;i++){
  printf(" %d",arr[i]);}}

   

  
 
