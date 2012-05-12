/*
 * Problem: 2299, Ultra-QuickSort
 * User: LoiteringLeo
 * Memory: 4076K     Time: 375MS
 * Language: GCC    Result: Accepted
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELE 500010

int b[MAX_ELE];
long long int inverse = 0;

void merge(int *a, int l, int mid, int r)
{
    int i;
    int j;
    int k;

    i = l;
    j = mid + 1;
    k = l;
    while (i <= mid && j <= r) {
        if (a[i] > a[j]) {
            inverse += mid - i + 1;
            b[k] = a[j];
            j++;
        }
        else {
            b[k] = a[i];
            i++;
        }
        k++;
    }

    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= r) {
        b[k++] = a[j++];
    }

    for (i = l; i <= r; i++) {
        a[i] = b[i];
    }
}

void merge_sort(int *a, int l, int r)
{
    int mid = l + ((r-l) >> 1);

#if 0
    for (i = l; i < r; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
#endif

    if (l >= r) {
        return;
    }

    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    merge(a, l, mid, r);

    return;
}

int main()
{
    int n;
    int a[MAX_ELE];
    int i;

    while (scanf("%d", &n) && n != 0) {
        memset(a, 0, sizeof(a));
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        inverse = 0;
        merge_sort(a, 1, n);
        printf("%lld\n", inverse);
    }

    return 0;
}

