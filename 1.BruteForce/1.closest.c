//closest pair

/*#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
int min, indexi = 0, i, j, d, indexj = 0, mid, n;
struct point
{
    int x, y;
};
int bruteforce(struct point *p, int st, int end)
{
    min = INT_MAX;
    for (i = st; i < end - 1; i++)
    {
        for (j = i + 1; j < end; j++)
        {
            d = sqrt(pow((p[i].x - p[j].x), 2) + pow((p[i].y - p[j].y), 2));
            if (d < min)
            {
                min = d;
                indexi = i;
                indexj = j;
            }
        }
    }
    return min;
}
int main()
{
    printf("enter no.of points");
    scanf("%d", &n);
    struct point p[n];
    printf("enter the points");
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &p[i].x, &p[i].y);
    }
    min = bruteforce(p, 0, n);
    printf("minimum shortest distance=%d\n", min);
    printf("Closest pair is (%d, %d) and (%d, %d)\n", p[indexi].x, p[indexi].y, p[indexj].x, p[indexj].y);
    return 0;
}*/


/*#include<stdio.h>
#include<limits.h>
#include<math.h>

struct point {
    int x, y;
};

int main() {
    struct point p[10];
    int i, j, d, min = INT_MAX, index_i, index_j, n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the values of x and y: ");
    for(i = 0; i < n; i++) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            d = sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
            if(d < min) {
                min = d;
                index_i = i;
                index_j = j;
            }
        }
    }

    printf("Closest pair is (%d, %d) and (%d, %d)\n", p[index_i].x, p[index_i].y, p[index_j].x, p[index_j].y);
    printf("Distance between them is: %d\n", min);


    return 0;
}*/


#include<stdio.h>
#include<limits.h>
#include<math.h>

struct point{
    int x, y;
};

int main() {
    struct point p[10];
    int i, j, n;
    double d, min = INT_MAX, index_i, index_j;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the values of x and y: ");
    for(i = 0; i < n; i++) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
       //    d = sqrt((double)((p[i].x - p[j].x) * (p[i].x - p[j].x)) + (double)((p[i].y - p[j].y) * (p[i].y - p[j].y)));
         d = sqrt((double)(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2)));

            if(d < min) {
                min = d;
                index_i = i;
                index_j = j;
            }
        }
    }

    printf("Closest pair is (%d, %d) and (%d, %d)\n", p[(int)index_i].x, p[(int)index_i].y, p[(int)index_j].x, p[(int)index_j].y);
    printf("Distance between them is: %f\n", min);

    return 0;
}


/*struct point {
    int x, y;
};

// Function to find the minimum distance between points using brute force
double bruteforce(struct point *p, int st, int end) {
    double min = INT_MAX;  // Initialize min to a large value
    int index_i, index_j;   // Variables to store indices of closest points

    // Iterate over all pairs of points
    for (int i = st; i < end - 1; i++) {
        for (int j = i + 1; j < end; j++) {
            // Calculate distance between p[i] and p[j]
            double d = sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2));
            
            // Update min distance and indices if a smaller distance is found
            if (d < min) {
                min = d;
                index_i = i;
                index_j = j;
            }
        }
    }
    
    // Print the indices of the closest pair of points
    printf("Closest pair is (%d, %d) and (%d, %d)\n", p[index_i].x, p[index_i].y, p[index_j].x, p[index_j].y);

    return min;  // Return the minimum distance found
}

int main() {
    int n;

    // Input the number of points
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Declare an array of points
    struct point p[n];

    // Input the points
    printf("Enter the points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    // Find the minimum distance using the bruteforce method
    double min = bruteforce(p, 0, n);

    // Print the minimum distance found
    printf("Minimum shortest distance = %.2f\n", min);

    return 0;
}*/

/*#include<stdio.h>
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
 }*/
 





