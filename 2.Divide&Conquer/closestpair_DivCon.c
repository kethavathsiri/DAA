//divide and conquer
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>
double index_i=0,index_j=0,min,d;
int n,i,j;
struct point{
int x,y;
};
double bruteforce(struct point *p,int st,int end){
min=INT_MAX;
	for(i=st;i<end-1;i++){
	 	for(j=i+1;j<end;j++){
	 		 d=sqrt(pow((p[i].x-p[j].x),2)+pow((p[i].y-p[j].y),2));
	 		if(d<min){
	 		min=d;
	 		index_i=i;
	 		index_j=j;
	 		}
	 		}
	 		}
	 		return min;
	 		}

double closestp(struct point *p,int st,int end){
struct point s[10];
double ld,rd,bd,d;
int k=0,mid;
if(end>st+1){
mid=(st+end)/2;
	ld=closestp(p,st,mid);
	rd=closestp(p,mid+1,end);
	d=ld>rd?rd:ld;
	for(i=st;i<=end;i++){
	if(abs(p[i].x-p[mid].x<d)){
	s[k++]=p[i];
	}
	}

bd=bruteforce(s,0,k);
return bd>d?d:bd;
}
else{
return bruteforce(p,st,end);
}
}
int main(){
int n;
printf("enter the size:");
scanf("%d",&n);
struct point p[n];
printf("enter the x and y coordinates:");
for(i=0;i<n;i++){
 scanf("%d %d",&p[i].x,&p[i].y);
 }
 double min=closestp(p,0,n);
 printf("min distance: %f\n",min);
 printf("(%d %d) and (%d %d) ",p[(int)index_i].x,p[(int)index_i].y,p[(int)index_j].x,p[(int)index_j].y);
 }
 



























/*#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<stdlib.h>
int min,indexi=0,i,j,d,indexj=0,mid,n;
struct point
{
    int x,y;
};
int bruteforce(struct point *p,int st,int end)
{
    min=INT_MAX;
    for(i=st;i<end-1;i++)
    {
        for(j=i+1;j<end;j++)
        {
            d=sqrt(pow((p[i].x-p[j].x),2) + pow((p[i].y-p[j].y),2));
            if(d<min)
            {
                min=d;
                indexi=i+1;
                indexj=j+2;
            }
        }
    }
    return min;
}
int closestp(struct point *p,int st,int end)
{
    struct point s[20];
    int k=0,ld,rd,bd;
    if(end>st+1)
    {
        mid=(st+end)/2;
        ld=closestp(p,st,mid);
        rd=closestp(p,mid+1,end);
        d=ld>rd?rd:ld;
        for(i=st;i<=end;i++)
        {
            if(abs(p[i].x-p[mid].x<d))
            {
                s[k++]=p[i];
            }
        }
        bd=bruteforce(s,0,k);
        return bd>d?d:bd;
    }
    else
    return bruteforce(p,st,end);
}
int main()
{
    printf("enter no.of points");
    scanf("%d",&n);
    struct point p[n];
    printf("enter the points");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    min=closestp(p,0,n);
    printf("minimum shortest distance=%d\n",min);
    printf("1st point=%d\n",indexi);
    printf("2nd point=%d\n",indexj);
    return 0;
}*/



