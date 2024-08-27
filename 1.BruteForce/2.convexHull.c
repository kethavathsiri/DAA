//1b.convex hull
#include <stdio.h>

struct point {
    int x, y;
};

int main() {
    int i, j, k, n, value, np, nn, a, b, c;
    struct point p[10];
    int hull[20], hullSize = 0;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter the points:\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d", &p[i].x, &p[i].y);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            a = p[j].y - p[i].y;
            b = p[i].x - p[j].x;
            c = p[i].x * p[j].y - p[j].x * p[i].y;

            np = 0;
            nn = 0;
            for (k = 0; k < n; k++) {
                value = a * p[k].x + b * p[k].y - c;

                if (value > 0)
                    np++;
                else if (value < 0)
                    nn++;
            }
           //hull array is used to store indices of the points that are the part of convex hull
           //hull size stores the points 
            if (np == 0 || nn == 0) { 
                // Store the points that form the convex hull
                int found_i = 0, found_j = 0;
                for (int m = 0; m < hullSize; m++) {
                    if (hull[m] == i) found_i = 1;    /*the indices i and j are checked if they are already in the hull array using the found_i and found_j flags.
                                                      If they are not found in the hull array, they are added, and hullSize is incremented.*/
                    if (hull[m] == j) found_j = 1;
                }
                if (!found_i) hull[hullSize++] = i;
                if (!found_j) hull[hullSize++] = j;
            }
        }
    }

    printf("The points in the Convex Hull are:\n");
    for (i = 0; i < hullSize; i++) {
        printf("(%d, %d)\n", p[hull[i]].x, p[hull[i]].y);
    }

    return 0;
}
