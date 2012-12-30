/*
 * POJ2479.c - Maximum sum
 * Problem: 2479    User: LoiteringLeo
 * Memory: 1068K		Time: 454MS
 * Language: GCC		Result: Accepted
 */
#include <stdio.h>

#define MAX_ELE     50000
#define INFINITY    (50000 * 10000 + 1)
short ele[MAX_ELE + 1] = {0,};  /* Elements */
int b[MAX_ELE + 1] = {0,};      /* Max two-subarray sum ending at position i */
int c[MAX_ELE + 1] = {0,};      /* Max subarray sum ending at position i */
int d[MAX_ELE + 1] = {0,};      /* max subarray of all sums ending at 1 to i */
/*
 * lstds - Largest sum of two disjoint subarrays
 * numbers in array a must begin with a[1] and end with a[n]
 */
int lstds(short *a, int n)
{
    int i;
    int max = -INFINITY;
    b[0] = 0;
    d[0] = b[0];

    for (i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[i];
        if (b[i] < a[i]) {
            b[i] = a[i];
        }

        if (max < b[i]) {
            max = b[i];
        }
        d[i] = max;
    }

    c[1] = 0;
    c[2] = a[1] + a[2];
    max = c[2];
    for (i = 3; i <= n; i++) {
        c[i] = c[i - 1] + a[i];
        if (c[i] < d[i - 1] + a[i]) {
            c[i] = d[i - 1] + a[i];
        }
        if (max < c[i]) {
            max = c[i];
        }
    }

    return max;
}

int main()
{
    int t;
    int n;
    int i;
    int m;
    int j;
    int k;
    int max;

    scanf("%d", &t);

    while (t > 0) {
        scanf("%d", &n);

        m = 0;
        j = -INFINITY;
        k = -INFINITY;
        for (i = 1; i <= n; i++) {
            scanf("%hd", &ele[i]);
            if (ele[i] > 0) {
                m++;
            }

            if (j < k) {
                if (ele[i] > j) {
                    j = ele[i];
                }
            }
            else {
                if (ele[i] > k) {
                    k = ele[i];
                }
            }

        }

        if (n == 2) {
            max = ele[1] + ele[2];
        }
        else if (m <= 2) {
            max = j + k;
        }
        else {
            max = lstds(ele, n);
        }

        printf("%d\n", max);
        t--;
    }

    return 0;
}
