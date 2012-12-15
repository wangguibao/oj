/*
 * POJ2479.c - Maximum sum
 * Problem: 2479    User: LoiteringLeo
 * Memory: 484K     Time: 454MS
 * Language: GCC    Result: Accepted
 */
#include <stdio.h>

#define MAX_ELE     50000
#define INFINITY    (50000 * 10000 + 1)
short ele[MAX_ELE + 1] = {0, };

/*
 * lstds - Largest sum of two disjoint subarrays
 * numbers in array a must begin with a[1] and end with a[n]
 */
int lstds(short *a, int n)
{
    int total = a[1];
    int sum = a[1];
    int begin;
    int end;
    int i;
    int larger1 = -INFINITY;
    int larger2 = -INFINITY;
    int ret;
    int segments = 1;

    begin = end = 1;
    for (i = 2; i <= n; i++) {
        if (sum < 0) {
            if (larger2 < larger1) {
                if (total > larger2) {
                    larger2 = total;
                }
            }
            else {
                if (total > larger1) {
                    larger1 = total;
                }
            }

            sum = a[i];
            total = a[i];
            begin = i;
            segments++;
        }
        else {
            sum += a[i];
        }

        if (total < sum) {
            total = sum;
            end = i;
        }

        if (i == n) {
            if (larger2 < larger1) {
                if (total > larger2) {
                    larger2 = total;
                }
            }
            else {
                if (total > larger1) {
                    larger1 = total;
                }
            }
        }
    }

    if (segments == 1) {
        int sub_sum = a[begin];
        int sub_total = a[begin];

        for (i = begin + 1; i <= end; i++) {
            if (sub_sum > 0) {
                sub_sum = a[i];
            }
            else {
                sub_sum += a[i];
            }

            if (sub_total > sub_sum) {
                sub_total = sub_sum;
            }
        }

        ret = sub_total < 0 ? total - sub_total : total;
    }
    else {
        ret = larger1 + larger2;
    }
    return ret;
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
